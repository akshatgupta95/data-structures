#include <iostream>
#include "links.h"
using namespace std;

 int main(){

 	List list;
 	list.append(10);
 	list.append(20);
 	list.append(30);
 	list.append(40);
 	list.append(50);
 	cout << list.nThLastElement(5) << endl;	//10



 	return 0;
 }