#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
 * Node Struct
*/

struct Node{

	int data;
	Node * next;

};

/*
 * Stack class
*/

class Stack{

private:

	Node * upper;	//pointer to the top most element
	int size;	
	Node * lower;	//pointer to the bottom element


public:

	Stack();
	void push(int newData);
	int pop();
	int getSize();
	string reverseWord(string word);

};


/*
 * Stack constructor
*/

Stack::Stack(){
	upper = NULL;
	size = 0;
}

/*
 * return the size of the stack
*/

int Stack::getSize(){
	return size;
}

/*
 * Adds an element to the top of the stack
 *
 * @param newData
*/

void Stack::push(int newData){
	Node * newNode = new Node();
	newNode->data = newData;
	newNode->next = NULL;
	if(size == 0){
		upper = newNode;
		lower = newNode;
		size++;
	} else{
		upper->next = newNode;
		upper = newNode;
		size++;
	}
}

/*
 * returns the top most element of the stack
*/

int Stack::pop(){
	if(size == 0){
		cout << "Stack is empty" << endl;
		exit(EXIT_FAILURE);
	}
	int retData = upper->data;
	if(size == 1){
		delete upper;
		size--;
	}	
	else {
		Node * tmp = lower;
		while(tmp->next != upper){
			tmp = tmp->next;
		}
	
		upper = tmp;
		upper->next = NULL;
		tmp = tmp->next;
		delete tmp;
		size--;
	}

	return retData;
}

/*
 * Reverse the word using a stack
 *
 * @param word
*/

string Stack::reverseWord(string word){

	string output = "";
	
	int len = word.length();
	for(int i = 0; i < len; i++){
		char c = word.at(i);
		int ascii = c - 'a';
		this->push(ascii);
	}

	for(int i = this->getSize(); i > 0; i--){
		int poppedNum = this->pop();
		char letter = (char)(poppedNum + 97);
		output += letter;
	}

	return output;

}



#endif