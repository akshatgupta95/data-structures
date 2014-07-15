#include "bst.h"
#include <iostream>
using namespace std;

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
 * InOrder Tree Traversal
 */

template <typename Comparable>
void BinarySearchTree<Comparable>::printTreeInOrder(BinaryNode<Comparable> * curr) const{
	if(curr == NULL) return;
	printTreeInOrder(curr->left);
	cout << curr->data << " ";
	printTreeInOrder(curr->right);
}

template <typename Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::getMinNode(BinaryNode<Comparable> * curr){
	if(curr == NULL) return NULL;
	else if(curr->left == NULL) return curr;
	return getMinNode(curr->left);
}


template <typename Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode<Comparable> * curr){
	if(curr == NULL){
		return NULL;
	}
	else if(x < curr->data){
		curr->left = remove(x, curr->left);
	}
	else if(x > curr->data){
		curr->right = remove(x, curr->right);
	}
	else{
		if((curr->left != NULL) && (curr->right != NULL)){
			BinaryNode<Comparable> * min = getMinNode(curr->right);
			curr->data = min->data;
			curr->right = remove(min->data, curr->right);
		}
		else if(curr->left != NULL){
			BinaryNode<Comparable> * tmp = curr->left;
			delete curr;
			return tmp;
		}
		else{
			BinaryNode<Comparable> * tmp = curr->right;
			delete curr;
			return tmp;
		}
	}
	return curr;
}
