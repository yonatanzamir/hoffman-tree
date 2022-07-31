#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
class BS_Tree
{
private:
	Node* root;
public:
	BS_Tree();
	~BS_Tree();
	Node* Find(char key);
	void Insert(char key, int freq);
	char Delete(char key);
	void MakeEmpty();
	void MakeEmptyRec(Node* node);
	bool IsEmpty();
	Node* Max(Node* node);
	Node* Min(Node* node);
	Node* Parent(Node* son);
	Node* getRoot() { return root; }
	void printRec(Node* node);
	void print();
	int Count();
	void CountRec(Node* node, int* counter);

};

