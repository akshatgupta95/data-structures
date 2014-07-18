#ifndef AVL_H
#define AVL_H
#include <iostream>
using namespace std;

template <typename Comparable>
class AVLNode{

public:
	
	int height;
	AVLNode<Comparable> * left;
	AVLNode<Comparable> * right;
	Comparable data;
	AVLNode(Comparable newData, AVLNode<Comparable> * l, AVLNode<Comparable> * r):left(l),right(r),data(newData){}
		
};

template <typename Comparable>
class AVLTree{

private:
	
	AVLNode<Comparable> * root;
	
public:
	
	AVLTree();
	AVLNode<Comparable> * getRoot();
	void insert(const Comparable & x);
	AVLNode<Comparable> * insert(const Comparable & x, AVLNode<Comparable> * curr);
	AVLNode<Comparable> * rotateSingleWithLeftChild(AVLNode<Comparable> * k2);
	AVLNode<Comparable> * rotateSingleWithRightChild(AVLNode<Comparable> * k2);	
	AVLNode<Comparable> * rotateDoubleWithLeftChild(AVLNode<Comparable> * k3);
	AVLNode<Comparable> * rotateDoubleWithRightChild(AVLNode<Comparable> * k3);
	int getHeight(AVLNode<Comparable> * curr);
	int max(int a, int b);
	void printTreeInOrder(AVLNode<Comparable> * curr);
	AVLNode<Comparable> * findMin(AVLNode<Comparable> * curr);
	AVLNode<Comparable> * findMax(AVLNode<Comparable> * curr);
	AVLNode<Comparable> * remove(const Comparable & x, AVLNode<Comparable> * curr);
		
};

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::findMin(AVLNode<Comparable> * curr){
	if(curr == NULL) return NULL;
	if(curr->left == NULL) return curr;
	return findMin(curr->left);
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::findMax(AVLNode<Comparable> * curr){
	if(curr == NULL) return NULL;
	if(curr->right == NULL) return curr;
	return findMin(curr->right);
}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(){
	root = NULL;
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::getRoot(){
	return root;
}

template <typename Comparable>
int AVLTree<Comparable>::getHeight(AVLNode<Comparable> * curr){
	return (curr == NULL) ? -1 : curr->height;
}

template <typename Comparable>
int AVLTree<Comparable>::max(int a, int b){
	return (a > b) ? a : b;
}

template <typename Comparable>
void AVLTree<Comparable>::printTreeInOrder(AVLNode<Comparable> * curr){
	if(curr == NULL){
		return;
	}
	else {
		printTreeInOrder(curr->left);
		cout << curr->data << " ";
		printTreeInOrder(curr->right);
	}
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::rotateSingleWithLeftChild(AVLNode<Comparable> * k2){
	AVLNode<Comparable> * k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k2 = k1;
	return k2;
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::rotateSingleWithRightChild(AVLNode<Comparable> * k2){
	AVLNode<Comparable> * k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k2 = k1;
	return k2;
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::rotateDoubleWithLeftChild(AVLNode<Comparable> * k3){
	k3->left = rotateSingleWithRightChild(k3->left);
	return rotateSingleWithLeftChild(k3);
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::rotateDoubleWithRightChild(AVLNode<Comparable> * k3){
	k3->right = rotateSingleWithLeftChild(k3->right);
	return rotateSingleWithRightChild(k3);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x){
	root = insert(x, root);
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::insert(const Comparable & x, AVLNode<Comparable> * curr){
	if(curr == NULL){
		curr = new AVLNode<Comparable> (x, NULL, NULL);
	}
	else if(x < curr->data){
		curr->left = insert(x, curr->left);
		if((getHeight(curr->left) - getHeight(curr->right)) == 2){
			if(x < curr->left->data){
				curr = rotateSingleWithLeftChild(curr);
			} else {
				curr = rotateDoubleWithLeftChild(curr);
			}
		}
	}
	else if(x > curr->data){
		curr->right = insert(x, curr->right);
		if((getHeight(curr->right) - getHeight(curr->left)) == 2){
			if(x > curr->right->data){
				curr = rotateSingleWithRightChild(curr);
			} else {
				curr = rotateDoubleWithRightChild(curr);
			}
		}
	}
	else ;
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	return curr;
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::remove(const Comparable & x, AVLNode<Comparable> * curr){
	if(curr == NULL){
		return NULL;
	}
	else if(x < curr->data){
		curr->left = remove(x, curr->left);
	}
	else if(x > curr->data){
		curr->right = remove(x, curr->right);
	}
	else {
		if((curr->left != NULL) && (curr->right != NULL)){
			AVLNode<Comparable> * min = findMin(curr->right);
			curr->data = min->data;
			curr->right = remove(min->data, curr->right);
		} else {
			AVLNode<Comparable> * tmp = (curr->left != NULL) ? curr->left : curr->right;
			delete curr;
			return tmp;
		}	
	}
	return curr;
}



#endif

