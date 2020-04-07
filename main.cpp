#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<conio.h>
#include<time.h> 

// including all the header files
#include "Trie.h"
#include"AVLTree.h"
#include"AVLNode.h"
#include "Stack.h"

using namespace std;

// adds word to file which is not in dictionary
void addWordtoFile(string word, string meaning) {

	ofstream file;
	file.open("words.txt", ios::app);
	file << "\n" << word << "-" << meaning;
	file.close();
}

// returns the new word that is need to be added
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

// dictionary with AVL Tree
void dictionaryAVL() {

	AVLTree root;
	Stack history; // to store history of searches
	ifstream file;
	file.open("words.txt");
	string input;

	clock_t startTime = clock();
	
	//Build Dictionary from file
	while (getline(file, input)) {
		int index = input.find('-');
		string word = input.substr(0, index);
		string meaning = input.substr(index + 1, input.length() - word.length() + 1);
		root.add(word, meaning);
	}
	file.close();
	cout << "Time taken to build data structure: " << double(clock() - startTime) / CLOCKS_PER_SEC << " seconds.\n" << endl;
	_getch();

	// prompts the user for searching 
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
			history.push(input); // push history in stack
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

// dictionnary using Hash Map
void dictionaryTrie() {

	Trie* root = NULL;
	Stack history;
	ifstream file;
	file.open("words.txt");
	string input;

	clock_t startTime = clock();

	//Build Dictionary from file
	while (getline(file, input)) {
		int index = input.find('-');
		string word = input.substr(0, index);
		string meaning = input.substr(index + 1, input.length() - word.length() + 1);
		root->insert(root, word, meaning);
	}
	file.close();
	cout << "Time taken to build data structure: " << double(clock() - startTime) / CLOCKS_PER_SEC << " seconds.\n" << endl;
	_getch();

	while (1) { // prompts to search words
		int choice;
		system("cls");
		cout << "Dictionary Using Trie\n\n\n1. Search meaning\n2. View history\n3. Exit\n\nChoice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nEnter word to search: ";
			cin >> input;
			if (!root->getMeaning(root, input)) { // add new word in file

				string newMeaning = addNewWord(input);
				if (newMeaning.length() > 0) {
					root->insert(root, input, newMeaning);
					addWordtoFile(input, newMeaning);
				}
			}
			history.push(input); // push in stack the history
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

// main definition starts here
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
} // main end