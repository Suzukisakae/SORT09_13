#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
struct Record
{
	int key;
	char Data;
};

void TwoWayMergeSort(Record X[], Record Y[], int nx, int ny, Record Z[])
{
	int i = 0, j = 0, k = 0;
	while (i < nx && j < ny)
	{
		if (X[i].key < Y[j].key)
		{
			Z[k] = X[i];
			i++;
		}
		else
		{
			Z[k] = Y[j];
			j++;
		}
		k++;
	}
	while (i < nx)
	{
		Z[k] = X[i];
		i++;
		k++;
	}
	while (j < ny)
	{
		Z[k] = Y[j];
		j++;
		k++;
	}
}

int main()
{
	int nx, ny;
	Record X[MAX / 2];
	Record Y[MAX / 2];
	Record Z[MAX];
	
	/*	
	cout << " Enter the number of elements in X: ";
	cin >> nx;
	cout << " Enter the number of elements in Y: ";
	cin >> ny;
	
	cout << " Enter the elements of X: ";
	for (int i = 0; i < nx; i++)
	{
		cin >> X[i].key;
		X[i].Data = 'X';
	}
	cout << "Enter the elements of Y: ";
	for (int i = 0; i < ny; i++)
	{
		cin >> Y[i].key;
		Y[i].Data = 'Y';
	}
	*/

	nx = 3;
	ny = 4;
	X[0].key = 1;
	X[0].Data = '1';
	X[1].key = 3;
	X[1].Data = '3';
	X[2].key = 5;
	X[2].Data = '5';
	
	Y[0].key = 2;
	Y[0].Data = '2';
	Y[1].key = 4;
	Y[1].Data = '4';
	Y[2].key = 6;
	Y[2].Data = '6';
	Y[3].key = 8;
	Y[3].Data = '8';
	
	cout << " X: ";
	for (int i = 0; i < nx; i++)
	{
		cout << X[i].key << " ";
	}
	cout << " Y: ";
	for (int i = 0; i < ny; i++)
	{
		cout << Y[i].key << " ";
	}

	TwoWayMergeSort(X, Y, nx, ny, Z);
	cout << " Z: ";
	for (int i = 0; i < nx + ny; i++)
	{
		cout << Z[i].key << " ";
	}	
	return 0;
}