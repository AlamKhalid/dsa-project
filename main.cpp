#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<conio.h>

#include "Trie.h"
#include"AVLTree.h"
#include"AVLNode.h"
#include "Stack.h"

using namespace std;

void addWordtoFile(string word, string meaning) {

	ofstream file;
	file.open("words.txt", ios::app);
	file <<"\n"<< word << "-" << meaning;
	file.close();
}

string addNewWord(string key) {

	string newWord = "";
	int cmd;

	cout << "Meaning not found." << endl << endl;
	cout << "Enter 1 to add meaning of the word other wise 0\nChoice: ";

	cin >> cmd;

	if (cmd) {				// for adding new word in dictionary
		system("cls");
		cout << "Word: " << key << endl;
		cout << "Enter meaning: ";
		cin.ignore();
		getline(cin, newWord);
		cout << "\n\nWord successfully added." << endl;
	}

	return newWord;
}

void dictionaryAVL() {

	AVLTree root;
	Stack history;
	ifstream file;
	file.open("words.txt");
	string input;

	//Build Dictionary from file
	while (getline(file, input)) {
		int index = input.find('-');
		string word = input.substr(0, index);
		string meaning = input.substr(index + 1, input.length() - word.length() + 1);
		root.add(word, meaning);
	}
	file.close();

	while (1) {
		int choice;
		system("cls");
		cout << "Dictionary Using AVL Trees\n\n\n1. Search meaning\n2. View history\n3. Exit\n\nChoice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nEnter word to search: ";
			cin >> input;
			if (!root.helpsearch(input)) {				// add new word
				string newMeaning = addNewWord(input);
				if (newMeaning.length() > 0) {
					root.add(input, newMeaning);
					addWordtoFile(input, newMeaning);
				}
			}
			history.push(input);
			break;
		case 2:
			history.printAll();
			break;
		case 3:
			exit(0);
		default:
			cout << "\nInvalid choice." << endl;
		}
		
		cout << "\n\nPress any key to continue" << endl;
		_getch();
	}
}

void dictionaryTrie() {

	Trie* root = NULL;
	Stack history;
	ifstream file;
	file.open("words.txt");
	string input;

	//Build Dictionary from file
	while (getline(file, input)) {
		int index = input.find('-');
		string word = input.substr(0, index);
		string meaning = input.substr(index + 1, input.length() - word.length() + 1);
		root->insert(root, word, meaning);
	}
	file.close();

	while (1) {
		int choice;
		system("cls");
		cout << "Dictionary Using Trie\n\n\n1. Search meaning\n2. View history\n3. Exit\n\nChoice: ";
		cin >> choice;

		switch(choice) {
		case 1:
			cout << "\nEnter word to search: ";
			cin >> input;
			if (!root->getMeaning(root, input)) {

				string newMeaning = addNewWord(input);
				if (newMeaning.length() > 0) {
					root->insert(root, input, newMeaning);
					addWordtoFile(input, newMeaning);
				}

			}
			history.push(input);
			break;
		case 2:
			history.printAll();
			break;
		case 3:
			exit(0);
		default:
			cout << "\nInvalid choice." << endl;
		}
		
		cout << "\n\nPress any key to continue" << endl;
		_getch();
	}
}


int main()
{
	int choice;

	cout << "1. AVL Trees (Balanaced BSTs)\n2. Hash Map (Hash Table/Trie)\n\nChoice: ";
	cin >> choice;

	if (choice == 1) {
		dictionaryAVL();
	}
	else {
		dictionaryTrie();
	}
	return 0;
}