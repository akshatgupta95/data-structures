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
	t.printTreeInOrder(t.getRoot());	//10 15 25 45 55
}
