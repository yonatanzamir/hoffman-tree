#pragma once
#include"HuffmanTree.h"
class PriorityQueue
{
public:
	struct PqCell {
		int frequency;
		HuffmanTree* t;
	};
private:	
	int MaxSize;
	int HeapSize;
	PqCell* data;
	int allocated;
	static int left(int node);
	static int right(int node);
	static int parent(int node);
	void FixHeap(int node);
public:
	PriorityQueue(int max);
	PriorityQueue(PqCell* arr, int n);//BuildHeap with Fluid Algorithem
	~PriorityQueue();
	PqCell Min();
	PqCell DeleteMin();
	void insert(PqCell item);
	bool IsEmpty() { return (HeapSize == 0); }
	void MakeEmpty();
};

