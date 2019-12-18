#include"AVLTree.h"
#include"AVLNode.h"
#include<iostream>
#include<algorithm>
using namespace std;

AVLTree::AVLTree() {
	size = 0;
	root = NULL;
}

Node* AVLTree::Rigthrotate(Node* y)
{
	Node* temp1 = y->left;
	Node* temp2 = temp1->right;

	temp1->right = y;
	y->left = temp2;

	y->height = max(height(y->left), height(y->right)) + 1;
	y->numberofnodes = 1;
	if (y->left != NULL)
	{
		y->numberofnodes += y->left->numberofnodes;

	}
	if (y->right != NULL)
		y->numberofnodes += y->right->numberofnodes;
	temp1->height = max(height(temp1->left), height(temp1->left)) + 1;
	temp1->numberofnodes = 1;
	if (temp1->left != NULL)
	{
		temp1->numberofnodes += temp1->left->numberofnodes;

	}
	if (temp1->right != NULL)
		temp1->numberofnodes += temp1->right->numberofnodes;
	return temp1;
}

Node* AVLTree::Leftrotate(Node* y)
{
	Node* temp1 = y->right;
	Node* temp2 = temp1->left;

	temp1->left = y;
	y->right = temp2;

	y->height = max(height(y->left), height(y->right)) + 1;
	y->numberofnodes = 1;
	if (y->left != NULL)
	{
		y->numberofnodes += y->left->numberofnodes;

	}
	if (y->right != NULL)
		y->numberofnodes += y->right->numberofnodes;

	temp1->height = max(height(temp1->left), height(temp1->left)) + 1;
	temp1->numberofnodes = 1;
	if (temp1->left != NULL)
	{
		temp1->numberofnodes += temp1->left->numberofnodes;

	}
	if (temp1->right != NULL)
		temp1->numberofnodes += temp1->right->numberofnodes;
	return temp1;
}

int AVLTree::getdifference(Node* root)
{
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

int AVLTree::height(Node* root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

Node* AVLTree::createnode(string key, string meaning)
{
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

int AVLTree::compar(string word1, string word2)
{
	return word1.compare(word2);
}

void AVLTree::add(string key, string meaning)
{
	root = insert(root, key, meaning);
}

bool AVLTree::search(Node* root, string key)
{
	if (root == NULL)
		return false;

	else if (compar(key, root->key) <= -1)
	{
		search(root->left, key);
	}
	else if (compar(key, root->key) >= 1)
	{
		search(root->right, key);
	}
	else
	{
		cout << "Meaning of " << key << " is " << root->meaning << endl;
		return true;
	}
}

Node* AVLTree::minright(Node* root)
{
	Node* cur = root;
	while (cur->left != NULL)
	{
		cur = cur->left;
	}

	return cur;
}

int AVLTree::number()
{
	if (size < 0)
		return 0;
	return size;
}

bool AVLTree::helpsearch(string key)
{
	return search(root, key);
}

int AVLTree::count(Node* root, string k)
{
	if (root == NULL)
		return 0;
	else if (compar(k, root->key) <= 0)
	{
		if (root->right != NULL)
			return 1 + root->right->numberofnodes + count(root->left, k);
		else
			return 1 + count(root->left, k);
	}
	else if (compar(k, root->key) > 0)
	{
		return count(root->right, k);
	}
}

int AVLTree::helpcount(string k1, string k2)
{
	int first = size - count(root, k1);
	int second = size - count(root, k2);
	if (search1(root, k2) == 1)
		second++;
	return second - first;
}

int AVLTree::search1(Node* root, string key)
{
	if (root == NULL)
		return -1;

	else if (compar(key, root->key) <= -1)
	{
		return search1(root->left, key);
	}
	else if (compar(key, root->key) >= 1)
	{

		return search1(root->right, key);
	}

	else
	{
		return 1;
	}

}

Node* AVLTree::insert(Node* root, string key, string meaning)
{

	if (root == NULL)
	{
		return createnode(key, meaning);
	}
	if (compar(key, root->key) <= -1)
	{
		root->left = insert(root->left, key, meaning);
		root->numberofnodes = 1;
		if (root->left != NULL)
		{
			root->numberofnodes += root->left->numberofnodes;

		}
		if (root->right != NULL)
			root->numberofnodes += root->right->numberofnodes;
	}
	else if (compar(key, root->key) >= 1)
	{
		root->right = insert(root->right, key, meaning);
		root->numberofnodes = 1;
		if (root->left != NULL)
		{
			root->numberofnodes += root->left->numberofnodes;

		}
		if (root->right != NULL)
			root->numberofnodes += root->right->numberofnodes;
	}
	else
	{
		root->meaning = meaning;
		return root;
	}

	root->height = 1 + max(height(root->left), height(root->right));

	int check = getdifference(root);
	if (check > 1 && compar(key, root->left->key) <= -1)
	{
		return Rigthrotate(root);
	}
	else if (check < -1 && compar(key, root->right->key) >= 1)
	{
		return Leftrotate(root);
	}
	else if (check > 1 && compar(key, root->left->key) >= 1)
	{
		root->left = Leftrotate(root->left);
		return Rigthrotate(root);
	}
	else if (check < -1 && compar(key, root->right->key) <= -1)
	{
		root->right = Rigthrotate(root->right);
		return Leftrotate(root);
	}
	if (root != NULL)
	{
		root->numberofnodes = 1;
		if (root->left != NULL)
			root->numberofnodes += root->left->numberofnodes;
		if (root->right != NULL)
			root->numberofnodes += root->right->numberofnodes;
	}
	return root;
}


