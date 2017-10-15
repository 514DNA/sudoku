#pragma once
#define SIZE 9

class __declspec(dllexport) Core {

public:
	Core();

	/* -c */
	void generate(int number, int result[][SIZE * SIZE]);

	/* -s */
	bool solve(int puzzle[SIZE * SIZE], int solution[SIZE * SIZE]);

	/* -n -r -u */
	void generate(int number, int lower, int upper, bool unique, int result[][SIZE * SIZE]);

	/* -n -m */
	void generate(int number, int mode, int result[][SIZE * SIZE]);
};

