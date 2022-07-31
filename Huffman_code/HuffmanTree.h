#pragma once
#include "Node.h"

class HuffmanTree
{
private:
	Node* root;
public:
	HuffmanTree(Node::Pair p);
	HuffmanTree();
	void setRoot(Node* Root) {root=Root; }
	Node* getRoot() { return root; }
	~HuffmanTree();
	void MakeEmptyRec(Node* node);
	void MakeEmpty();
};

