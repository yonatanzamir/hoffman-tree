#include"HuffmanAlgorithm.h"

BS_Tree* MakeBstFromFile(const char* fname)
{
	char c;
	BS_Tree* bst;
	bst = new BS_Tree();
	ifstream infile;
	infile.open(fname);
	if (!infile.is_open())
	{
		cout << "Error: cant open file." << endl;
		exit(1);
	}
	infile >> c;//
	while (!infile.eof())
	{
		bst->Insert(c, 1);
		infile >> c;
	}
	infile.close();
	return bst;
}
//(Node::Pair p

PriorityQueue::PqCell* MakeArrFromBst(BS_Tree* bst,int size)
{

	PriorityQueue::PqCell* Arr = new PriorityQueue::PqCell[size];
	Node* current;
	Node::Pair temp;
	for (int i = 0; i < size; i++)
	{
		current = bst->Min(bst->getRoot());
		temp.frequency = current->getValue().frequency;
		temp.key = current->getValue().key;
		HuffmanTree* T = new HuffmanTree(temp);
		Arr[i].t=T;
		Arr[i].frequency = temp.frequency;
		bst->Delete(current->getValue().key);
	}
	return Arr;
}
HuffmanTree* MakeHuffmanTree(BS_Tree* bst)
{
	int size = bst->Count();
	int leftFreq, rightFreq;
	HuffmanTree* res;
	PriorityQueue::PqCell* Arr = MakeArrFromBst(bst,size);
	PriorityQueue MinPq(Arr, size);
	PriorityQueue::PqCell left;
	PriorityQueue::PqCell right;
	PriorityQueue::PqCell curr;
	HuffmanTree dummy({ 'z',0 });
	curr.t = &(dummy);
	Node* root;
	for (int i = 1; i < size; i++)
	{
		root = new Node();
		
		curr.t->setRoot(root);
		curr.t->getRoot()->setLeft(MinPq.DeleteMin().t->getRoot());
		curr.t->getRoot()->setRight(MinPq.DeleteMin().t->getRoot());
		leftFreq = curr.t->getRoot()->getLeft()->getValue().frequency;
		rightFreq = curr.t->getRoot()->getRight()->getValue().frequency;
		curr.t->getRoot()->setFreq(leftFreq, rightFreq);
		curr.t->getRoot()->setKey(' ');
		curr.frequency = curr.t->getRoot()->getValue().frequency;
		MinPq.insert(curr);
	}
	res=MinPq.DeleteMin().t;
	delete[]Arr;
	return res;

}
void PrintHuffmanTree(HuffmanTree T)
{
	if (T.getRoot() == nullptr)
	{
		cout<< "Empty Tree";
	}
	else if (T.getRoot()->IsLeaf())
	{
		cout << "'" << T.getRoot()->getValue().key << "'" << "-" << 1;
	}
	else {
		list<int> bits;
		bits.clear();
		PrintHuffmanTreeRec(T.getRoot(), bits);
	}
}
void PrintHuffmanTreeRec(Node* node,list<int>& bits)
{
	if (node->IsLeaf())
	{
		
		cout << "'" << node->getValue().key << "'" << "-";
		for (auto v : bits)
			cout << v;
		cout << endl;
	}
	else
	{
		if (node->getLeft() != nullptr)
		{
			bits.push_back(0);
			PrintHuffmanTreeRec(node->getLeft(), bits);
			bits.pop_back();
		}
		if (node->getRight() != nullptr)
		{
			bits.push_back(1);
			PrintHuffmanTreeRec(node->getRight(), bits);
			bits.pop_back();
		}
	}
}