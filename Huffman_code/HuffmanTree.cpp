#include "HuffmanTree.h"
HuffmanTree::HuffmanTree(Node::Pair p)
{
	root = new Node(p, nullptr, nullptr);
}

HuffmanTree::HuffmanTree()
{
	root=nullptr;
}
HuffmanTree::~HuffmanTree()
{
MakeEmpty();
}
void HuffmanTree::MakeEmptyRec(Node* node)
{
	if (node != nullptr)
	{
		MakeEmptyRec(node->left);
		MakeEmptyRec(node->right);
		delete node;
	}
}
void HuffmanTree::MakeEmpty()
{

	MakeEmptyRec(root);
	root = nullptr;
}