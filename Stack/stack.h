#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
using namespace std;

/*
 * Node Struct
*/

class Node{

public:
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



#endif