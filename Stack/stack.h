#ifndef STACK_stack_h
#define STACK_stack_h
#include <stdlib.h>
#include <string.h>
using namespace std;



struct Node{

	int data;
	Node * next;

};

class Stack{

private:

	Node * upper;
	int size;
	Node * lower;


public:

	Stack();
	void push(int newData);
	int pop();
	int getSize();
	string reverseWord(string word);

};

Stack::Stack(){
	upper = NULL;
	size = 0;
}

int Stack::getSize(){
	return size;
}

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