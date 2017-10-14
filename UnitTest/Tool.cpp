#include "stdafx.h"
#include "Tool.h"

int* Tool::CreateSet(int num) {
	int *set = new int[num];
	memset(set, 0, sizeof(int) * num);
	return set;
}

void Tool::DeleteSet(int *set) {
	delete set;
	return;
}

int** Tool::CreateArray(int m, int n) {
	int **a = NULL;
	a = new int *[m];
	int i = 0, j = 0;
	for (i = 0; i < m; i++) {
		a[i] = new int[n];
		memset(a[i], 0, sizeof(int) * n);
	}

	return a;
}

void Tool::DeleteArray(int **a, int m) {
	int i = 0;
	for (i = 0; i < m; i++) {
		delete[] a[i];
	}
	delete a;
	return;
}

int Tool::ToNum(char* n) {
	unsigned int i = 0, num = 0;
	for (i = 0; i < strlen(n); i++) {
		if (n[i] < '0' || n[i] > '9') {
			return -1;
		}
		num = num * 10 + (n[i] - '0');
	}
	return num;
}

int** Tool::CopyArray(int **ori) {
	int i = 0, j = 0, **copy = CreateArray(LEN, LEN);
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			copy[i][j] = ori[i][j];
		}
	}
	return copy;
}

void Tool::unfold(int *sudokuLine, int** sudokuArray) {
	int i = 0, j = 9, k = 0;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			sudokuArray[i][j] = sudokuLine[k++];
		}
	}
	return;
}

void Tool::fold(int** sudokuArrray, int *sudokuLine) {
	int i = 0, j = 0, k = 0;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			sudokuLine[k++] = sudokuArrray[i][j];
		}
	}
	return;
}