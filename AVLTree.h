#ifndef AVLTREE_H
// contains all the function prototypes of AVL tree functions
#define AVLTREE_H

#include<string>
#include"AVLNode.h"

using namespace std;

class AVLTree {
private:
	Node* root;
	int size;
public:
	AVLTree();
	Node* Rigthrotate(Node*);
	Node* Leftrotate(Node*);
	int getdifference(Node*);
	int height(Node*);
	Node* createnode(string, string);
	int compar(string, string);
	void add(string, string);
	bool search(Node*, string);
	bool helpsearch(string);
	Node* insert(Node*, string, string);
};

#endif
