#pragma once

#ifndef TRIE_H
#define TRIE_H
#define SIZE 26

#include<string>

using namespace std;

class Trie {
private:

	bool isEndOfWord;
	string meaning;
	Trie* table[SIZE];

public:
	Trie();
	void insert(Trie*&, string, string);
	bool getMeaning(Trie*, string);
	Trie* find(char);
	void add(char, Trie*);
	int getIndex(char);
};


#endif // !TRIE_H

