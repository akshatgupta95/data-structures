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
 	list.remove(50);	
	list.print();	//10 --> 20 --> 30 --> 40 --> NULL



 	return 0;
 }