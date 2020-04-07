#pragma once

#include"Stack.h"
#include"StackNode.h"
#include<iostream>
#include<string>

using namespace std;

Stack::Stack() {
	size = 0;
	top = NULL;
}

bool Stack::isEmpty() { 
	return top == NULL;
}

void Stack::push(string word) { // push search in stack

	StackNode* temp = new StackNode();

	if (isEmpty()) {
		temp->next = NULL;
	}
	else {
		temp->next = top;
	}

	temp->wordSeached = word;
	top = temp;
	size++;
}

void Stack::printAll() { // to print all searches

	StackNode* temp = top;
	if (isEmpty()) {
		cout << "\n\nNo history available." << endl;
	}
	else {
		int i = 1;
		cout << "\n\nWords searched are as follows: \n" << endl;
		while (temp) {
			cout << i << ". " << temp->wordSeached << endl;
			temp = temp->next;
			i++;
		}
	}
}