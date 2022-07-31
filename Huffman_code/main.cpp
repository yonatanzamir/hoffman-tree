#include <iostream>
#include "BS_Tree.h"
#include "HuffmanAlgorithm.h"
#include "Node.h"
using namespace std;
void main()
{
//	Node* temp;
//	BS_Tree t1;
//	t1.Insert('a', 1);
//	t1.Insert('c', 2);
//	t1.Insert('b', 3);
//	t1.Insert('d', 4);
//	t1.Insert('g',5);
//	t1.Insert('e', 6);
//	t1.print();
//	t1.Delete('d');
//	t1.Delete('a');
//	t1.Delete('e');
//	cout << endl;
//	cout <<t1.Count();
//	cout <<endl;
//t1.print();
	char filename[MaxSize];
	cin >> filename;

	BS_Tree* bst = MakeBstFromFile(filename);
	HuffmanTree* tree = MakeHuffmanTree(bst);
	PrintHuffmanTree(*tree);
    
}