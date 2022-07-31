#include "PriorityQueue.h"
PriorityQueue::PriorityQueue(int max) {
	data = new PqCell[max];
	MaxSize = max;
	HeapSize = 0;
	allocated = 1;
}
PriorityQueue::PriorityQueue(PqCell* arr, int n)
{
	HeapSize = MaxSize = n;
	data = arr;
	allocated = 0;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}
PriorityQueue::~PriorityQueue() {
	MakeEmpty();
}
void PriorityQueue::MakeEmpty() {
	if (allocated)
	{
		delete[]data;
	}
	data = nullptr;
	MaxSize = HeapSize = 0;
}
PriorityQueue::PqCell PriorityQueue::Min()
{
	return data[0];
}
PriorityQueue::PqCell PriorityQueue::DeleteMin() {
	if (HeapSize < 1)
	{
		cout << "ERROR:PriorityQueue empty" << endl;
		exit(1);
	}
	else
	{
		PqCell temp;
		temp.t = data[0].t;
		temp.frequency = data[0].frequency;
		HeapSize--;
		data[0].t = data[HeapSize].t;
		data[0].frequency = data[HeapSize].frequency;
		FixHeap(0);
		return temp;
	}

}
void PriorityQueue::insert(PqCell item) {
	if (HeapSize == MaxSize)
	{
		cout << "ERROR:Place is over ";
		exit(1);
	}

	int i = HeapSize;
	HeapSize++;
	while (i > 0 && data[parent(i)].frequency > item.frequency)
	{
		data[i].frequency = data[parent(i)].frequency;
		data[i].t = data[parent(i)].t;
		i = parent(i);
	}
	data[i].frequency = item.frequency;
	data[i].t = item.t;
}
int PriorityQueue::left(int node)
{
	return(2 * node + 1);
}
int PriorityQueue::right(int node)
{
	return(2 * node + 2);
}
int PriorityQueue::parent(int node)
{
	return((node - 1) / 2);
}
void PriorityQueue::FixHeap(int node)
{
	int Min;
	int Left = left(node);
	int Right = right(node);
	if (Left < HeapSize && data[Left].frequency < data[node].frequency)
	{
		Min = Left;
	}
	else
	{
		Min = node;
	}
	if (Right < HeapSize && data[Right].frequency < data[Min].frequency)
	{
		Min = Right;
	}
	if (Min != node)
	{
		PqCell temp;
		temp.frequency = data[node].frequency;
		temp.t = data[node].t;
		data[node].frequency = data[Min].frequency;
		data[node].t = data[Min].t;
		data[Min].frequency = temp.frequency;
		data[Min].t = temp.t;
		FixHeap(Min);
	}
}
//זה עלול לא לעבוד בעקבות העתקת עצים לא נכונה 
//לעבור על FIXHEAP 
//לבדוק אם עובד באופן כללי