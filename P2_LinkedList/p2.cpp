//Name: Long Pham
//File: p2.cpp
//Purpose: Using member functions to add, delete, or print nodes from linked 
// list to files.

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

struct Node{
	int data;  // The value for this node
	Node* next; // To point to the next node
};

void printList(Node* list, ofstream& outs);
//Purpose: member function that traverses the list, displaying
//the value member of each node. Also reading those value 
// to a file.
//Pre-condition: List must not be empty
// Post-condition: value members of list are printed



bool insertNode(Node*& list, int d);
//Purpose: member function that insert node in an ascending 
//order.
//Pre-cond:....
//Post-cond: Node is inserted in the right position.


void deleteNode(Node*& list, int d);
//Purpose: member function that delete assigned node
//Pre-cond:...
//Post-cond: Selected node is deleted from the list.

void deleteAll(Node*& list);
//Purpose: member function that deletes list
//Pre-cond: list is not empty
//Post-cond: data from list is deleted


int main()
{
	cout << "Welcome to the program!!" << endl;

	const string FILENAME = "P2OutputA.txt";    
	const string FILENAME2 = "P2OutputB.txt";
	const int MAX = 50;		// Size of the list
	const int MAXRAND = 100; // int data used to generate random number
	srand(time(0));
	int input = 0, val = 0;  //Store random #s for list
	


	Node* head = nullptr;  //List head pointer
	Node* nodePtr;		   // To move through the list

	for (int i = 0; i < MAX; i++)
	{
		//get random number
		//insert into list
		input = rand() % MAXRAND;
		insertNode(head, input);
		
	}
	
	ofstream FILE;		
	FILE.open(FILENAME);
	printList(head, FILE);
	FILE.close();
	cout << endl;

	//Delete Smallest data of the list
	cout << "Deleting Smallest data of the list: " << head->data << endl;
	deleteNode(head, head->data);

	//Delete The largest data of the list
	nodePtr = head;
	
	while(nodePtr->next != nullptr){
		nodePtr = nodePtr->next;
	}
	cout << "Deleting the largest data of the list: " << nodePtr->data << endl;
	deleteNode(head,nodePtr->data);
	
	
	//Delete random number
	int count = 0;
	val = rand() % (MAX-2);
	nodePtr = head;
	while(nodePtr->next != nullptr && count < val){
		nodePtr = nodePtr->next;
		count++;
	}
	cout << "Deleting A random number: " << nodePtr->data << endl;
	cout << endl;
	deleteNode(head,nodePtr->data);
	

	FILE.open(FILENAME2);
	printList(head, FILE);
	FILE.close();
	deleteAll(head);
	cout << "End of the program, Bye!!!" << endl;
	return 0;
}




void printList(Node* list, ofstream& outs){
	Node* temp = list;
	while (temp != nullptr){
		cout << temp->data << endl;
		outs << temp->data << endl;
		temp = temp->next;

	}
}



bool insertNode(Node*& list, int d){
	Node* temp = new Node;
	Node* curr;
	if (temp == nullptr)
	{
		return false;
	} 

	temp->data = d;

	if (list == nullptr || list->data > d)
	{
		temp->next = list;
		list = temp;

	} else {
		curr = list;
		while(curr->next != nullptr && curr->next->data < temp->data)
			curr = curr->next;
			temp->next = curr->next;
			curr->next = temp;

	}
	return true;
}



void deleteNode(Node*& list, int d){
	Node* delPtr, *tPtr;

	if (list->data == d){
		delPtr = list;
		list = list->next;
		delete delPtr;
	} else {
		tPtr = list;
		while (tPtr-> next != nullptr && tPtr->next->data < d)
			tPtr = tPtr->next;

		if(tPtr->next != nullptr && tPtr->next->data == d){
			delPtr = tPtr->next;
			tPtr->next = delPtr->next;
			delete delPtr;
		}
	}
}


void deleteAll(Node*& list){
	Node* delPtr;
	while (list != nullptr){
		delPtr = list;
		list = list->next;
		delete delPtr;
	}
}
