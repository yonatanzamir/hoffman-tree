#include "BS_Tree.h"
#include "HuffmanTree.h"
#include "PriorityQueue.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
const int MaxSize = 100;
BS_Tree* MakeBstFromFile(const char* fname);
PriorityQueue::PqCell* MakeArrFromBst(BS_Tree* bst,int size);
HuffmanTree* MakeHuffmanTree(BS_Tree* bst);
void PrintHuffmanTreeRec(Node* node, list<int>& bits);
void PrintHuffmanTree(HuffmanTree T);