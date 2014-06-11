#ifndef TRIE_trie_h
#define TRIE_trie_h
#include <iostream>
using namespace std;

/*
 * Node Class
 */

class Node{

public:

	Node();
	// ~Node();
	char content();
	void setContent(char c);
	bool wordMarker();
	void setWordMarker();
	Node * findChild(char c);
	void appendChild(Node * child);
	vector<Node*> children();


private:

	char mContent;
	bool mMarker;
	vector<Node*> mChildren;

};

Node::Node(){
	mContent = ' ';
	mMarker = false;
}

char Node::content(){
	return mContent;
}

void Node::setContent(char c){
	mContent = c;
}

bool Node::wordMarker(){
	return mMarker;
}

void Node::setWordMarker(){
	mMarker = true;
}

Node * Node::findChild(char c){

	Node * tmp = NULL;

	for(int i = 0; i < mChildren.size(); i++){
		tmp = mChildren.at(i);
		if(tmp->content() == c) return tmp;
	}

	return NULL;

}

void Node::appendChild(Node * child){
	mChildren.push_back(child);
}

/*
 * Trie Class
 */

 class Trie{

 public:

 	Trie();
 	void addWord(string s);
 	bool searchWord(string s);
 	// void deleteWord(string s);


 private:

 	Node * root;

 };

 Trie::Trie(){
 	root = new Node();
 }

 void Trie::addWord(string s){

 	Node * current = root;

 	if(s.length() == 0){
 		current->setWordMarker();
 		return;
 	}

 	for(int i = 0; i < s.length(); i++){
 		Node * tmp = current->findChild(s[i]);
 		if(tmp != NULL) current = tmp;
 		else{
 			tmp = new Node();
 			tmp->setContent(s[i]);
 			current->appendChild(tmp);
 			current = tmp;
 		}
 		if(i == s.length() - 1) current->setWordMarker();

 	}

 }

 bool Trie::searchWord(string s){
 	Node * current = root;

 	for(int i = 0; i < s.length(); i++){
 		Node * tmp = current->findChild(s[i]);
 		if(tmp == NULL) return false;
 		current = tmp;
 	}
 	if(current->wordMarker()) return true;
 	else return false;
 }




#endif