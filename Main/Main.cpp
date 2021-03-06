#include "stdafx.h"
#include "main.h"
#include <iostream>
#include<array>
#include <stdlib.h>
using namespace std;

pa1::pa1()
{}

void pa1::MagicSquare(int **matrix, int n) {   //form magic square

	int dms = n * n;
	int i = n / 2;
	int	j = 0;     // Matrix construction starts in the middle

	for (int k = 1; k <= dms; ++k) {
		matrix[i][j] = k;

		i++;
		j--;

		if (k % n == 0) {   //adaptive adjustments for out of bound coordinates
			i -= 1;
			j += 2;
			if (i<0) {
				i += n;
			}
		}
		else {
			if (i == n)
				i -= n;
			if (j < 0)
				j += n;
		}

	}
}

void pa1::MyMagicSquare(int **matrix, int n) {   //finds and prints 8 permutations of desired magic square
	MagicSquare(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	transpose(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	flipColumns(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	transpose(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	flipColumns(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	transpose(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	flipColumns(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';

	transpose(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << '\n';
	CheckSum(matrix, n);
	cout << '\n';
}

void pa1::transpose(int **matrix, int n) {   //transpose matrix
	for (int i = 0; i<n; i++) {
		for (int j = i + 1; j<n; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void pa1::flipRows(int **matrix, int n) {   //swaps first row with last row
	for (int i = 0; i<n / 2; i++) {
		for (int j = 0; j<n; j++) {
			int * temp = matrix[i];
			matrix[i] = matrix[n - 1 - i];
			matrix[n - 1 - i] = temp;
		}
	}
}

void pa1::flipColumns(int **matrix, int n) {   //swap first column with last column
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n / 2; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][n - 1 - j];
			matrix[i][n - 1 - j] = temp;
		}
	}
}

void pa1::CheckSum(int **matrix, int n) {
	int sum = 0;
	int tempsum = 0;

	for (int a = 0; a < n; a++) {   //sum of first row
		sum += matrix[a][0];
	}

	cout << "Checking sum of every column: ";
	for (int a = 0; a < n; a++) {   //compare sum of first row to sum of each column: column check
		for (int b = 0; b < n; b++) {
			tempsum += matrix[b][a];
		}
		if (tempsum != sum) {
			cout << "ERROR" << endl;
			return;
		}
		cout << tempsum << " ";
		tempsum = 0;
	}
	cout << endl;

	cout << "Checking sum of every row: ";
	for (int a = 0; a < n; a++) {   //comparing sum of first row to sum of every other row: row check
		for (int b = 0; b < n; b++) {
			tempsum += matrix[a][b];
		}
		if (tempsum != sum) {
			cout << "ERROR" << endl;
			return;
		}
		cout << tempsum << " ";
		tempsum = 0;
	}
	cout << endl;

	cout << "Checking sum of every diagonal: ";
	for (int b = 0; b < n; b++) {   //sum of first diagonal
		tempsum += matrix[b][b];
	}
	if (tempsum != sum) {
		cout << "ERROR" << endl;
		return;
	}
	cout << tempsum << " ";
	tempsum = 0;

	for (int b = 0; b < n; b++) {   //sum of second diagonal
		tempsum += matrix[n - b - 1][n - b - 1];
	}
	if (tempsum != sum) {
		cout << "ERROR" << endl;
		return;
	}
	cout << tempsum << " " << endl;


}

void pa1::PrintMagicSquare(int **matrix, int n) {
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			cout << matrix[a][b] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n = 0;
	cout << "Enter the size of magic square: ";

	do {
		cin >> n;

		if ((n < 3) || (n % 2 == 0) || (n > 15)) {   // exception handling for when user enters even number
			cout << "Please select an odd number between 3 and 15." << endl;
		}
	} while ((n < 3) || (n % 2 == 0) || (n > 15));
	int** matrix;
	matrix = new int*[n];

	for (int i = 0; i < n; i++) {   //allocate memory for each of row 2D array
		matrix[i] = new int[n];
	}

	pa1 obj;
	obj.MyMagicSquare(matrix, n);

	
	for (int i = 0; i<n; i++) {   //deallocate
		delete[] matrix[i];
	}
	delete[] matrix;

	system("pause");
	return 0;
}