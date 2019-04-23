//Name: Long Pham
//File_Name: stack.cpp
//Purpose:  This program demonstrates the stack class
//Input: None
//Process:..
//OutPut: A list of palindrome and non-palindrome sentences.

#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{	
	cout << "***** START *****" << endl;
	ifstream inputFile;
	string line;	// string line the file reads into
	Stack s1,s2,s3;	// 3 stacks
	char pop, pop2; // pop and pop2 to hold values popped off the stack
	bool palindrome = true; //A boolean to check if the phrase is a palindrome
	int length;
    
    const char* FILE = "/home/fac/sreeder/class/cs2430/p1input.dat";
    
    //Open a file
    inputFile.open(FILE);
    
    // check that it is open/readable
    if (inputFile.fail()){
      cout << endl
           << "Sorry, file not available...exiting program...press enter"
           << endl;
      cin.get();  // grab the enter
	    return 0;
    }
    
    // read data and do work
    while (getline(inputFile, line)){
      palindrome = true;
      length = line.length();
      for (int i = 0; i < length; ++i)
        {
          char c = tolower(line[i]);
          if (c >= 'a' && c <= 'z'){
			    s2.push(c);
			    s1.push(c);
          }
       }	
      while (!s1.isEmpty()){
		
	      s1.pop(pop);
		  s3.push(pop);
        
        
      }
      
      while(!s2.isEmpty() && !s3.isEmpty()){

	     s2.pop(pop);
	     s3.pop(pop2);
		 if(pop != pop2){
       	   palindrome = false;
		}
        
      }
      
	    if(palindrome == true){
         cout << "This is a palindrome: " << line << endl;
	     cout << endl;
	 }
	    else{ 
          cout << "This is not a palindrome: "<<line<<endl;
      	  cout << endl;
      	}
    
    }
    	cout << "***** END *****" << endl;
    
    // close file
    inputFile.close();
    return 0;
}
