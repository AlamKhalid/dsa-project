#pragma once

#ifndef AVLNODE_H
#define AVLNODE_H
using namespace std;

class Node
{
public:
  string key;
  string meaning;
  Node *left;
  Node *right;
  int height;
  int numberofnodes;
};

#endif
