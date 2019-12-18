#pragma once


#include "Trie.h"
#include<iostream>

using namespace std;


Trie::Trie() {

	isEndOfWord = false;

	for (int i = 0; i < SIZE; i++)
		table[i] = NULL;
}

void Trie::insert(Trie*& root, string str, string meaning) {

	// If root is null 
	if (root == NULL)
		root = new Trie();

	Trie* temp = root;			// To traverse the Trie structure

	for (int i = 0; i < str.length(); i++) {
		char x = str[i];

		// Make a new node if there is no path
		if (temp->find(x) == NULL)
			temp->add(x, new Trie());

		temp = temp->find(x);
	}

	// Mark end of word and store the meaning 
	temp->isEndOfWord = true;
	temp->meaning = meaning;
}

bool Trie::getMeaning(Trie* root, string word)
{

	// If root is null i.e. the dictionary is empty 
	if (root == NULL)
		return false;

	Trie* temp = root;

	// Search a word in the Trie 
	for (int i = 0; i < word.length(); i++) {
		temp = temp->find(word[i]);
		if (temp == NULL)
			return false;
	}

	// If it is the end of a valid word stored 
	// before then return its meaning 
	if (temp->isEndOfWord){
		cout << "Meaning of " << word << " is " << temp->meaning << endl;
		return true;
	}

	return false;
}

Trie* Trie::find(char key) {

	return table[getIndex(key)];
}

void Trie::add(char key, Trie* val) {

	table[getIndex(key)] = val;
}

int Trie::getIndex(char key) {

	return (int)key % (int)'a';
}