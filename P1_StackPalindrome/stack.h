//Name: Long Pham
//File_Name: stack.h
//Purpose:  Specification file for the Stack class


#ifndef STACK_H
#define STACK_H

class Stack
{
private:
   char *list;  // Pointer to the stack array
   int size;    // The stack size
   int top;          // Indicates the top of the stack
   void resize();    
   //purpose: Resize the stack when it is full
   //pre_condition: the stack has to be full in order to resize
   //post_cond: new stack created with a new size.
    bool isFull() const;
   //Purpose: Member function isFull returns true if the stack
   // is full, or false otherwise.  

public:
   // Constructor
   // This constructor creates an empty stack.
   // the size parameter is the default size of the stack.    
   explicit Stack(int stackSize = 16);
   
   //OverLoaded assignment
   Stack& operator=(const Stack& obj);

   // Copy constructor
   Stack(const Stack &);

   // Destructor
   ~Stack();
   
   // Stack operations
   void push(char data);
   //Purpose: Member function push pushes the argument onto 
   // the stack.                         
   //Pre-condition: The stack must not be full.
   //Post-condition: Pushing data into the stack.

   bool pop(char &);
   //Purpose: Member function pop pops the value at the top 
   // of the stack off, and copies it into the variable 
   // passed as an argument.  
   //Precondtion: The stack is not empty
   //Post-condition: Poppin data off the stack.

   bool isEmpty() const;
   //Purpose: Member funciton returns true if the stack
   // is empty, or false otherwise. 
   
}; 
#endif 