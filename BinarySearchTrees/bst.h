#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

/*
 * BinaryNode class
 */

template <typename Comparable>
class BinaryNode{
	
	public:

	BinaryNode<Comparable> * left;
	BinaryNode<Comparable> * right;
	Comparable data;
	
	BinaryNode(const Comparable & newData, BinaryNode<Comparable> * newLeft, BinaryNode<Comparable> * newRight){
		data = newData;
		left = newLeft;
		right = newRight;
	}
	
};

/*
 * BinarySearchTree class with Comparable
 */ 

template <typename Comparable>
class BinarySearchTree{
	
	BinaryNode<Comparable> * root;
	
public:
	
	BinarySearchTree(){
		root = NULL;
	}
	
	const Comparable & findMin(BinaryNode<Comparable> * node) const;
	const Comparable & findMax(BinaryNode<Comparable> * node) const;
	bool contains(const Comparable & x, BinaryNode<Comparable> * node);
	bool isEmpty(BinaryNode<Comparable> * node);
	void printTreeInOrder(BinaryNode<Comparable> * node) const;			//print Left subtree, then Current node, then Right subtree
	// void makeEmpty();
	void insert(const Comparable & x, BinaryNode<Comparable> * node);
	// const BinarySearchTree & operator=(const BinarySearchTree & rhs);
	BinaryNode<Comparable> * getRoot();
	BinaryNode<Comparable> * remove(const Comparable & x, BinaryNode<Comparable> * curr);
	BinaryNode<Comparable> * getMinNode(BinaryNode<Comparable> * curr);
	
};


#include "bst.inc"
#endif