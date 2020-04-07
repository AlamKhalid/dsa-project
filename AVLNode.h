#pragma once
// definition of node for AVL tree
#ifndef AVLNODE_H
#define AVLNODE_H
using namespace std;

class Node {
public:
	string key; // word
	string meaning;
	Node *left;
	Node *right;
	int height;
	int numberofnodes;
};

#endif
