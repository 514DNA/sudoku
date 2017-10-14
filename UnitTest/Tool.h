#pragma once
#include "stdafx.h"
#include <string.h>
#define LEN  9
using namespace std;
class Tool {
public:
	int *CreateSet(int num);
	void DeleteSet(int *set);
	int** CreateArray(int m, int n);
	void DeleteArray(int **a, int m);
	int ToNum(char* n);
	int** CopyArray(int **ori);
	void unfold(int *sudokuLine, int **sudokuArray);
	void fold(int **sudokuArray, int *sudokuLine);
};