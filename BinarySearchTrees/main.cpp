#include "bst.h"
#include <iostream>
using namespace std;

int main(){
	BinarySearchTree<int> t;
	t.insert((int) 10, t.getRoot());
	t.insert((int) 20, t.getRoot());
	t.insert((int) 30, t.getRoot());
	t.insert((int) 15, t.getRoot());
	t.insert((int) 1, t.getRoot());
	t.remove((int) 10, t.getRoot());
	
	cout << (t.getRoot())->data << endl;	// 10
	t.printTreeInOrder(t.getRoot());		// 1 10 15 20 30
	return 0;
}