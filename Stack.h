#pragma once

#ifndef STACK_H
#define STACK_H

#include<string>
#include"StackNode.h"

using namespace std;

class Stack {

private:
	int size;
	StackNode* top;

public:
	Stack();
	void push(string);
	void printAll();
	bool isEmpty();
};


#endif // !STAKC_H
