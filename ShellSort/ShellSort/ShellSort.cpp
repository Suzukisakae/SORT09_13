#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
struct Record
{
	int key;
	char Data;
};

void mySwap(Record& a, Record& b)
{
	Record temp = a;
	a = b;
	b = temp;
}

void ShellSort(Record rc[], int n)
{
	int* h = new int[n];
	int x, temp, Key, i;
	Record record;
	x = n / 2;
	for (int i = x - 1; i >= 0; i--)
	{
		h[i] = x;
		x--;
	}
	int s;
	int gap = n / 2;
	for (s = (n / 2) - 1; s >= 0; s--)
	{
		temp = h[s];
		for (int j = temp; j < n; j++)
		{
			i = j - temp;
			Key = rc[j].key;
			record = rc[j];
			if ((i >= 0) && Key < rc[i].key)
			{
				while (i >= 0 & Key < rc[i].key)
				{
					mySwap(rc[i], rc[i + temp]);
					i = i - temp;
				}
			}
			else
			{
				rc[i + temp] = record;
			}
		}
		gap--;
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
	
	// Sort the records
	ShellSort(rc, n);
	// Output the sorted records
	OutputRecord(rc, n);	
	return 0;
}