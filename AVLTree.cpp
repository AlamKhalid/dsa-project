#pragma once

#include"AVLTree.h"
#include"AVLNode.h"
#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;

AVLTree::AVLTree() : size(0), root(nullptr) {}

// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.
Node* AVLTree::Rigthrotate(Node* y) {
	Node* temp1 = y->left;
	Node* temp2 = temp1->right;

	// Perform rotation 
	temp1->right = y;
	y->left = temp2;

	// Update heights 
	y->height = max(height(y->left), height(y->right)) + 1;
	y->numberofnodes = 1;
	
	// update number of nodes in tree
	if (y->left != NULL) 
		y->numberofnodes += y->left->numberofnodes;
	
	if (y->right != NULL)
		y->numberofnodes += y->right->numberofnodes;
	
	temp1->height = max(height(temp1->left), height(temp1->left)) + 1;
	temp1->numberofnodes = 1;
	
	if (temp1->left != NULL)
		temp1->numberofnodes += temp1->left->numberofnodes;
	
	if (temp1->right != NULL)
		temp1->numberofnodes += temp1->right->numberofnodes;
	
	// Return new root 
	return temp1;
}

// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.
Node* AVLTree::Leftrotate(Node* y)
{
	Node* temp1 = y->right;
	Node* temp2 = temp1->left;

	// perform rotation
	temp1->left = y;
	y->right = temp2;

	// update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	y->numberofnodes = 1;
	
	// update num of nodes in tree
	if (y->left != NULL)
		y->numberofnodes += y->left->numberofnodes;

	if (y->right != NULL)
		y->numberofnodes += y->right->numberofnodes;

	temp1->height = max(height(temp1->left), height(temp1->left)) + 1;
	temp1->numberofnodes = 1;

	if (temp1->left != NULL)
		temp1->numberofnodes += temp1->left->numberofnodes;

	if (temp1->right != NULL)
		temp1->numberofnodes += temp1->right->numberofnodes;
	
	// return new root
	return temp1;
}

// get difference factor of root
int AVLTree::getdifference(Node* root) {
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

// get height of AVL Tree
int AVLTree::height(Node* root) {
	if (root == NULL)
		return 0;
	return root->height;
}

// create node with the word and its meaning
Node* AVLTree::createnode(string key, string meaning) {
	size++;
	Node* temp = new Node;
	temp->key = key;
	temp->meaning = meaning;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	temp->numberofnodes = 1;
	return temp;
}

// compare two words
int AVLTree::compar(string word1, string word2) {
	return word1.compare(word2);
}

// add word in tree
void AVLTree::add(string key, string meaning) {
	root = insert(root, key, meaning);
}

// search word in tree and return its meaning
bool AVLTree::search(Node* root, string key) {
	clock_t startTime = clock();
	//Build Dictionary from file
	if (root == NULL) // if no root
		return false;

	else if (compar(key, root->key) <= -1) { // search left
		return search(root->left, key);
	}
	else if (compar(key, root->key) >= 1) { // search right
		return search(root->right, key);
	}
	else { 
		cout << "Time taken to search: " << double(clock() - startTime) / CLOCKS_PER_SEC << " seconds." << endl;
		cout << "Meaning of " << key << " is " << root->meaning << endl;
		return true;
	}
}

// utility function to search for a word in the tree
bool AVLTree::helpsearch(string key) {
	return search(root, key);
}

// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.
Node* AVLTree::insert(Node* root, string key, string meaning) {
	/* 1. Perform the normal BST insertion */
	if (root == NULL)
		return createnode(key, meaning);
	
	if (compar(key, root->key) <= -1) {
		root->left = insert(root->left, key, meaning);
		root->numberofnodes = 1;
		
		if (root->left != NULL)
			root->numberofnodes += root->left->numberofnodes;
		
		if (root->right != NULL)
			root->numberofnodes += root->right->numberofnodes;
	}
	else if (compar(key, root->key) >= 1) {
		root->right = insert(root->right, key, meaning);
		root->numberofnodes = 1;
		
		if (root->left != NULL)
			root->numberofnodes += root->left->numberofnodes;

		if (root->right != NULL)
			root->numberofnodes += root->right->numberofnodes;
	}
	else { // Equal keys are not allowed in BST
		root->meaning = meaning;
		return root;
	}
	/* 2. Update height of this ancestor node */
	root->height = 1 + max(height(root->left), height(root->right));

	/* 3. Get the difference factor of this ancestor node to check whether this node became unbalanced */
	int check = getdifference(root);

	// If this node becomes unbalanced, then  
	// there are 4 cases

	// left left case
	if (check > 1 && compar(key, root->left->key) <= -1)
		return Rigthrotate(root);
	
	// Right Right Case
	else if (check < -1 && compar(key, root->right->key) >= 1)
		return Leftrotate(root);

	// Left Right Case
	else if (check > 1 && compar(key, root->left->key) >= 1) {
		root->left = Leftrotate(root->left);
		return Rigthrotate(root);
	}

	// Right Left Case
	else if (check < -1 && compar(key, root->right->key) <= -1) {
		root->right = Rigthrotate(root->right);
		return Leftrotate(root);
	}

	if (root != NULL) {
		root->numberofnodes = 1;
		if (root->left != NULL)
			root->numberofnodes += root->left->numberofnodes;
		if (root->right != NULL)
			root->numberofnodes += root->right->numberofnodes;
	}
	/* return the (unchanged) node pointer */
	return root;
}