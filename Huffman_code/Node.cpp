#include "Node.h"

Node::Node()
{
	left = right = nullptr;
}
Node::Node(Pair item, Node* left, Node* right):right(right),left(left)
{

	this->value.frequency = item.frequency;
	this->value.key = item.key;
}
Node::~Node()
{

}