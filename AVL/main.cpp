#include "avl.h"
using namespace std;
#include <iostream>

int main(){
	AVLTree<int> t;
	t.insert(10);
	t.insert(15);
	t.insert(25);
	t.insert(45);
	t.insert(55);	
	t.remove(10, t.getRoot());
	t.printTreeInOrder(t.getRoot());	//15 25 45 55
}
