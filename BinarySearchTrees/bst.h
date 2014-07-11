#ifndef BST_bst_h
#define BST_bst_h
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
 * BinarySearchTree class
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
	void makeEmpty();
	void insert(const Comparable & x, BinaryNode<Comparable> * node);
	void remove(const Comparable & x, BinaryNode<Comparable> * node);
	const BinarySearchTree & operator=(const BinarySearchTree & rhs);
	BinaryNode<Comparable> * getRoot();
	
};

/*
 * root is private in BinarySearchTree class
 * getter for the root of the tree
 */

template <typename Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::getRoot(){
	return root;
}

/*
 * Minimum element is the left most element in the tree
 * @param BinaryNode<Comparable> * node 
*/

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> * node) const {
	if(node->left == NULL) return node->data;
	return findMin(node->left);
}

/*
 * Maximum element is the right most element in the tree
 * @param BinaryNode<Comparable> * node 
*/

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> * node) const {
	if(node->right == NULL) return node->data;
	return findMax(node->right);
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode<Comparable> * node){
	if(node == NULL) return false;
	else if(x < node->data) return contains(x, node->left);
	else if(x > node->data) return contains(x, node->right);
	else return true;
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty(BinaryNode<Comparable> * node){
	if(node == NULL) return true;
	else return false;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * curr){
	if(root == NULL){
		root = new BinaryNode<Comparable>(x, NULL, NULL);
	}
	else if(x < curr->data){
		if(curr->left != NULL){
			insert(x, curr->left);
		}
		else {
			curr->left = new BinaryNode<Comparable>(x, NULL, NULL);
		}
	}
	else if(x > curr->data){
		if(curr->right != NULL){
			insert(x, curr->right);
		}
		else {
			curr->right = new BinaryNode<Comparable>(x, NULL, NULL);
		}
	}
	else ;
}

/*
 * InOrder Tree Traversal (left, node, right)
 */

template <typename Comparable>
void BinarySearchTree<Comparable>::printTreeInOrder(BinaryNode<Comparable> * curr) const{
	if(curr == NULL) return;
	printTreeInOrder(curr->left);
	cout << curr->data << " ";
	printTreeInOrder(curr->right);
}







#endif