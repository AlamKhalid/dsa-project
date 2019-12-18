#ifndef AVLTREE_H
#define AVLTREE_H
#include<string>
#include"AVLNode.h"
using namespace std;

class AVLTree
{
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
	Node* minright(Node*);
	int number();
	bool helpsearch(string);
	int helpcount(string, string);
	Node* insert(Node*, string, string);
	int search1(Node*, string);
	int count(Node*, string);
};

#endif
