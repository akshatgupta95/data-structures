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
  void reverse();
  int nThLastElement(int n);

 };

 



#endif