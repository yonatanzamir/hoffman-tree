#pragma once
#include <iostream>
using namespace std;
class Node
{
public:	
	struct Pair {
	char key;
	int frequency;
};
private:

	Pair value;
	Node* left;
	Node* right;
	friend class BS_Tree;
	//friend class HuffmanAlgorithm;
	friend class HuffmanTree;
public:
	Node();
	Pair getValue() { return value; }
	Node(Pair item, Node* left, Node* right);
	void setLeft(Node* node) { left = node; }
	void setRight(Node* node) { right= node; }
	void setFreq(int Freq1, int Freq2) { value.frequency=Freq1 + Freq2; }
	void setKey(char key) { value.key = key; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	bool IsLeaf() { return (left == nullptr && right == nullptr); }

	~Node();
};

