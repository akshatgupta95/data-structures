#ifndef LINKS_links_h
#define LINKS_links_h

#include <iostream>
using namespace std;




/*
 * Node Class 
 */

 class Node{

 private:

 	int data;
 	Node * next;

 public:

 	Node() {};
 	void setData(int newData) { data = newData; };
 	void setNext(Node * newnext) { next = newnext; };
 	int Data() { return data; };
 	Node * Next() { return next; };

 };

 /*
  * List class
  */

 class List{

 	Node * head;

 public:

 	List() { head = NULL; };
 	void print();
 	void append(int data);
 	void remove(int data);
 	void insertAfter(int data, int putData);
 	int length();
 	int getDataAt(int n, int len);
 	void deleteAll();
 	void sortedInsert(int data);
    void swapHack(int data1, int data2);

 };

 /*
  * Prints all the list items from the beginning
  */
 void List::print(){

 	Node * tmp = head;

 	if(tmp == NULL){
 		cout << "Empty List" << endl;
 	}


 	else {
 		
 		while(tmp != NULL){
 			if(tmp->Next() == NULL) { 
 				cout << tmp->Data() << " --> NULL" << endl; 
 				break; 
 			}
 		cout << tmp->Data() << " --> ";
 		tmp = tmp->Next();
 		}

 	}

 }

 /*
  * Appends the list at the end with a node with the given data
  */
 void List::append(int data){

 	Node * newNode = new Node();
 	newNode->setData(data);
 	newNode->setNext(NULL);

 	Node * tmp = head;

 	if(head == NULL){
 		head = newNode;
 	}

 	else{

 		while(tmp->Next() != NULL){
 			tmp = tmp->Next();
 		}
 		tmp->setNext(newNode);
 		newNode = NULL;
 		tmp = NULL;

 	}

 }

 /*
  * Removes the particular list item with given data
  */
 void List::remove(int data){

 	Node * tmp = head;
 	Node * prev = NULL;

 	if(tmp == NULL){
 		cout << "List is Empty" << endl;
 		return;
 	}

 	if(tmp->Data() == data && tmp->Next() == NULL){
 		delete tmp;
 		tmp = NULL;
 	}


 	else if(tmp->Data() == data && tmp->Next() != NULL){
 		prev = tmp;
 		head = tmp->Next();
 		delete prev;
 		prev = NULL;
 		tmp = NULL;
 	}


 	else {
 		
 		while(tmp->Data() != data){
 			if(tmp->Next() == NULL){
 				cout << data << " is not in the list ";
 				return;
 			}
 			prev = tmp;
 			tmp = tmp->Next();
 		}
 		
 		prev->setNext(tmp->Next());
 		delete tmp;
 		tmp = NULL;
	 	 
   }

 }

 /*
  * Inserts a node with putData after an existing node with data
  */
 void List::insertAfter(int data, int putData){

 	Node * newNode = new Node();
 	newNode->setData(putData);

 	Node * tmp = head;

 	if(tmp == NULL){
 		newNode->setNext(NULL);
 		head = newNode;
 	}

 	else{

 		while(tmp->Data() != data){
 			tmp = tmp->Next();
 		}
 		newNode->setNext(tmp->Next());
 		tmp->setNext(newNode);
 		tmp = NULL;
 		newNode = NULL;

 	}

 }

 /*
  * Returns the length of the list
  */
 int List::length(){

 	Node * tmp = head;
 	int length = 1;

 	if(tmp == NULL) return 0;
 	
 	else if(tmp->Next() == NULL) return 1;

 	else {

 		while(tmp->Next() != NULL){
 			length++;
 			tmp = tmp->Next();
 		}

 	}

 	return length;

 }

 /*
  * Returns the node at the nth position
  */
 int List::getDataAt(int n, int len){

 	if(n < 0 || n >= len){
 		cout << "Invalid Position" << endl;
 		return -1;
 	}

 	Node * tmp = head;
 	int count = 0;

 	while(count != n){
 		count++;
 		tmp = tmp->Next();
 	}

 	return tmp->Data();

 }

 /*
  * Empties the list
  */
 void List::deleteAll(){

 	Node * tmp = head;
 	Node * del = NULL;

 	if(tmp == NULL){
 		cout << "Nothing to be deleted" << endl;
 		return;
 	}

 	else if(tmp->Next() == NULL){
 		delete tmp;
 		tmp = NULL;
 		head = NULL;
 	}

 	else {

 		while(tmp->Next() != NULL){
 			del = tmp;
 			tmp = tmp->Next();
 			delete del;
 		}
 		delete tmp;
 		tmp = NULL;
 		head = NULL;

 	}

 }

 /*
  * Inserts a node with given data in a ascending sorted list in the correct sorted position
  */
 void List::sortedInsert(int data){

 	Node * tmp = head;
 	Node * newNode = new Node();
 	newNode->setData(data);
 	Node * curr = NULL;
 	Node * prev = NULL;


 	if(tmp == NULL){
 		head = newNode;
 		newNode->setNext(NULL);
 	}

 	else if(tmp->Next() == NULL){

 		if(data <= tmp->Data()){
 			head = newNode;
 			newNode->setNext(tmp);
 		} else{
			tmp->setNext(newNode);
			newNode->setNext(NULL); 			
 		}

 	}

 	else if(tmp->Next() != NULL && data <= tmp->Data()){
 		head = newNode;
 		newNode->setNext(tmp);
 	}

 	else {

 		while(tmp != NULL){
 			if(tmp->Next() == NULL){
 				tmp->setNext(newNode);
 				newNode->setNext(NULL);
 				break;
 			} else{
 				prev = tmp;
 				curr = tmp->Next();
 					if(data > prev->Data() && data <= curr->Data()){
 					prev->setNext(newNode);
 					newNode->setNext(curr);
 					break;
 					}
 				tmp = tmp->Next();
 			}
 		}
 		
 	}
 }

 /*
  * A hack for swapping 2 elements of the List
  */

 void List::swapHack(int data1, int data2){

  Node * first = head;

  while(first->Data() != data1){
    first = first->Next();
  }

  Node * sec = head;

  while(sec->Data() != data2){
    sec = sec->Next();
  }

  first->setData(data2);
  sec->setData(data1);

}



#endif