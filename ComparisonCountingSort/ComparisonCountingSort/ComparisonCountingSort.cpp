#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
struct Record
{
	int key;
	char Data;
};

void ComparisonCountingSort(Record rc[], int n,int Count[])
{
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (rc[i].key > rc[j].key)
			{
				Count[i]++;
			}
			else
			{
				Count[j]++;
			}
		}
	}
	// Output the result
	Record rs[MAX];
	for (int k = 0; k < n; k++)
	{
		rs[Count[k]] = rc[k];
	}
	// Copy the sorted array to the original array
	for (int i = 0; i < n; i++)
	{
		rc[i] = rs[i];
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
	int Count[MAX];
	
	/*
	nhap mang rc
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
	
	for (int i = 0; i < MAX; i++)
		Count[i] = 0;
	// Output the original records
	OutputRecord(rc, n);
	// Sort the records
	ComparisonCountingSort(rc, n, Count);
	// Output the sorted records
	OutputRecord(rc, n);
	return 0;
}