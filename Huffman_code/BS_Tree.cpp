#include "BS_Tree.h"
enum {LEFT,RIGHT};
BS_Tree::BS_Tree()
{
	root = nullptr;
}
BS_Tree::~BS_Tree()
{
	MakeEmpty();
}
void BS_Tree::MakeEmptyRec(Node* node)
{
	if (node != nullptr)
	{
		MakeEmptyRec(node->left);
		MakeEmptyRec(node->right);
		delete node;
	}
}
void BS_Tree::MakeEmpty()
{
	MakeEmptyRec(root);
	root = nullptr;
}
void BS_Tree::CountRec(Node* node,int *counter)
{
	if (node != nullptr)
	{
		CountRec(node->left,counter);
		CountRec(node->right, counter);
		*counter = *counter + 1;
	}
}
int BS_Tree::Count()
{
	int count=0;
	CountRec(root,&count);
	return count;
}
Node* BS_Tree::Find(char key)
{
	Node* temp = root;
	while (temp != nullptr && temp->value.key != key)
	{
		if (temp->value.key < key)
			temp = temp->right;
		else if (temp->value.key > key)
			temp = temp->left;
	}
	return temp;
}
void BS_Tree::Insert(char key, int freq)
{
	if (Find(key) == nullptr)
	{
		Node::Pair p;
		p.frequency = freq;
		p.key = key;
		Node* node = new Node(p, nullptr, nullptr);
		if (root == nullptr)
			root = node;
		else {
			Node* temp = root;
			Node* parent = nullptr;
			while (temp != nullptr)
			{
				parent = temp;
				if (temp->value.key < key)
					temp = temp->right;
				else if (temp->value.key > key)
					temp = temp->left;
			}

			if (key > parent->value.key)
				parent->right = node;
			else
			{
				parent->left = node;
			}
		}
	}
	else
	{
		Node* node = Find(key);
		node->value.frequency++;
	}
}
char BS_Tree::Delete(char key)
{
	char temp_key;
	
	Node* ToDelete = Find(key);
	
	if (ToDelete == nullptr)
	{
		cout << "ERROR:Cant delete." << endl << "this key is not in the tree";
		exit(1);
	}
	else
	{
		temp_key = ToDelete->value.key;
		int side;
		Node* Parent_ToDelete = Parent(ToDelete);
		//__________________________________________________________________________________________// If we want to delete the root and he has less than 2 sons 
		if (Parent_ToDelete == nullptr && (ToDelete->left == nullptr || ToDelete->right == nullptr))
		{
			if (ToDelete->left != nullptr)
			{
				root = ToDelete->left;
				delete ToDelete;

			}
			else if (ToDelete->right != nullptr)
			{
				root = ToDelete->right;
				delete ToDelete;
			}
			else
			{
				MakeEmpty();
			}
			return temp_key;
		}
		//_______________________________________________________________________________//  If we want to delete  node(not the root) and he has less than 2 sons 
		if (Parent_ToDelete != nullptr&&Parent_ToDelete->left == ToDelete)
		{
			side = LEFT;
		}
		else if (Parent_ToDelete != nullptr && Parent_ToDelete->right == ToDelete)
		{
			side = RIGHT;
		}
		if ((ToDelete->left == nullptr || ToDelete->right == nullptr)&&(Parent_ToDelete != nullptr))
		{
			if (ToDelete->left != nullptr)
			{
				if (side ==  LEFT)
				{
					Parent_ToDelete->left = ToDelete->left;
					delete ToDelete;
				}
				else
				{
					Parent_ToDelete->right = ToDelete->left;
					delete ToDelete;
				}
			
			}
			else if (ToDelete->right!= nullptr)
			{
				if (side == LEFT)
				{
					Parent_ToDelete->left = ToDelete->right;
					delete ToDelete;
				}
				else
				{
					Parent_ToDelete->right = ToDelete->right;
					delete ToDelete;
				}
			}
			else
			{
				if (side == LEFT)
				{
					Parent_ToDelete->left = nullptr;
					delete ToDelete;
				}
				else
				{
					Parent_ToDelete->right = nullptr;
					delete ToDelete;
				}
			}
			return temp_key;
		}
		//_______________________________________________________________________________//  If we want to delete node and he has 2 sons 
		else 
		{
			Node* MaxLeft = Max(ToDelete->left);
			if (Parent_ToDelete != nullptr)
			{
				Parent(MaxLeft)->right = MaxLeft->left;
				ToDelete->value.frequency = MaxLeft->value.frequency;
				ToDelete->value.key = MaxLeft->value.key;
				delete MaxLeft;
			}
			else {
				if (MaxLeft->left == nullptr)
				{
					ToDelete->value.frequency = MaxLeft->value.frequency;
					ToDelete->value.key = MaxLeft->value.key;
					delete MaxLeft;
				}
				else 
				{
					root = MaxLeft;
					MaxLeft->right = ToDelete->right;
					delete ToDelete;
				}
			}
			return temp_key;
		}

	}
}

bool BS_Tree::IsEmpty()
{
	return (root == nullptr);
}
Node* BS_Tree::Max(Node* node)
{
	if (node == nullptr)
		return nullptr;
	Node* temp = node;
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	return temp;
}
Node* BS_Tree::Min(Node* node)
{
	if (node == nullptr)
		return nullptr;
	Node* temp = node;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}
Node* BS_Tree::Parent(Node* son)
{
	if (son == this->root)
		return nullptr;
	else {
		Node* temp = this->root;
		while (temp->left != son && temp->right != son)
		{
			if (son->value.key > temp->value.key)
				temp = temp->right;
			else if (son->value.key < temp->value.key)
				temp = temp->left;
		}
		return temp;
	}
}

void BS_Tree::print()
{
	printRec(root);
}
void BS_Tree::printRec(Node* node)
{
	if (node != nullptr)
	{
		printRec(node->left);
		cout <<" "<< node->value.key;
		printRec(node->right);
	}
}