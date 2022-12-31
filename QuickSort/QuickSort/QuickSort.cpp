#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
struct Record
{
	int key;
	char Data;
};

struct Node
{
	int l;
	int r;
	Node* next;
};
Node* CreateNode(int l, int r)
{
	Node* p = new Node;
	if (p == nullptr) return nullptr;
	p->l = l;
	p->r = r;
	p->next = nullptr;
	return p;
}

struct Stack
{
	Node* top;
	int size = 0;
	void init()
	{
		this->top = nullptr;
		this->size = 0;
	}
	int isEmpty()
	{
		if (this->top == nullptr) return 1;
		return 0;
	}
	void push(Node* node)
	{
		if (node != nullptr)
		{
			if (this->isEmpty())
				this->top = node;
			else
			{
				node->next = this->top;
				this->top = node;
			}
		}
	}
	Node* pop()
	{
		Node* p;
		if (!this->isEmpty())
		{
			this->size -= 1;
			p = this->top;
			this->top = p->next;
			return p;
		}
		return nullptr;
	}
};

void QuickSort(Record rc[], int n, Stack s)
{
	s.init();
	Node* p = CreateNode(0, n - 1);
	s.push(p);
	while (!s.isEmpty())
	{
		p = s.pop();
		int l = p->l;
		int r = p->r;
		if (l < r)
		{
			int i = l;
			int j = r;
			Record x = rc[l];
			while (i < j)
			{
				while (i < j && rc[j].key >= x.key) j--;
				if (i < j) rc[i++] = rc[j];
				while (i < j && rc[i].key <= x.key) i++;
				if (i < j) rc[j--] = rc[i];
			}
			rc[i] = x;
			s.push(CreateNode(l, i - 1));
			s.push(CreateNode(i + 1, r));
		}
	}
}

void OutputRecord(Record rc[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << rc[i].key << "  " << rc[i].Data << endl;
	}
	cout << endl;
}

int main()
{
	Stack s;
	Record rc[MAX];
	int n;

	/*
	cout << "Please input the number of records: ";
	cin >> n;
	cout << "Please input the records: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> rc[i].key;
		rc[i].Data = 'A' + i;
	}
	*/	
	n = 8;
	rc[0].key = 2; rc[0].Data = 'A';
	rc[1].key = 5; rc[1].Data = 'B';
	rc[2].key = 3; rc[2].Data = 'C';
	rc[3].key = 0; rc[3].Data = 'D';
	rc[4].key = 2; rc[4].Data = 'E';
	rc[5].key = 3; rc[5].Data = 'F';
	rc[6].key = 0; rc[6].Data = 'G';
	rc[7].key = 3; rc[7].Data = 'H';

	//	Output the original records
	cout << "The original records are: " << endl;
	OutputRecord(rc, n);
	QuickSort(rc, n, s);
	//	Output the sorted records
	cout << "The sorted records are: " << endl;
	OutputRecord(rc, n);
	return 0;
}
