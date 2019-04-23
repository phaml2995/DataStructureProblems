//Name: Long Pham
//File_Name: stack.cpp
//Purpose:  Implementation file for the stack.h class

#include <iostream>
#include "stack.h"
using namespace std;

//***********************************************
// Constructor                                  *
// This constructor creates an empty stack. The *
// size parameter is the size of the stack.     *
//***********************************************

Stack::Stack(int stackSize)
{  
   if(stackSize < 2){
      size = 16;
   } else {
      size = stackSize;
   }
   list = new char[size];  
   top = 0;
}

//********************************************
// Overloaded Assignment                     *
//********************************************

Stack& Stack::operator=(const Stack& obj){
   if (this != &obj){
      top = obj.top;
      size = obj.size;
      delete [] list;
      list = new char[size];
      for (int i = 0; i < size; ++i)
      {
         list[i] = obj.list[i];
      }
   }
   return *this;
}

//***********************************************
// Copy constructor                             *
//***********************************************

Stack::Stack(const Stack &obj)
{
  *this = obj;
}

//***********************************************
// Destructor                                   *
//***********************************************

Stack::~Stack()
{
   delete [] list;
}

//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
//*************************************************

void Stack::push(char data)
{
   if (isFull()){
      //cout << "The stack is full.\n";
      resize();
   } 
      
      list[top] = data;
      top ++;
   

}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

bool Stack::pop(char& data)
{  
   //cout << "The value of top is " << top << endl;
   if (isEmpty())
   {  
      
      cout << "The stack is empty.\n";
   }
   else
   {
       top--;
       data = list[top];
   }
    return true;
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

bool Stack::isFull() const
{
   return top == size;
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

bool Stack::isEmpty() const
{
   return top == 0;
}

//****************************************************
// Member function Resizes the stack when it is full *
//****************************************************

void Stack::resize(){
   int tempSize = (int) double(size)*(1.5);
   char * temp = new char[tempSize];
   //CHECK IF WE GOT REQUESTED MEMOR
   for (int i = 0; i < size; i++)
   {
      temp[i] = list[i];
   }
   delete [] list;
   size = tempSize;
   list = temp;
   
   
}