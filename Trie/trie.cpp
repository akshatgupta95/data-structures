#include <iostream>
#include <vector>
#include "trie.h"
using namespace std;


 int main(){

 	Trie * t = new Trie();
 	t->addWord("Hello");
 	t->addWord("Ball");
 	if(t->searchWord("Hello")) cout << "Found .. Hello" << endl;
 	if(t->searchWord("Ball")) cout << "Found .. Ball" << endl;
 	if(t->searchWord("Best")) cout << "Found .. Best" << endl; else cout << "Could not find .. Best" << endl;
 	t->addWord("Best");
 	if(t->searchWord("Best")) cout << "Found .. Best" << endl; else cout << "Could not find .. Best" << endl;


 	return 0;
 }



