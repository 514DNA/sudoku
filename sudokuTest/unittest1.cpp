#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../sudoku/sudoku.cpp"
//#include "Puzzle.h"
#include "../sudoku/core.h"
#include "Tool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(LegalSudoku) {
			Core core;
			int sudoku[1000][81];
			core.generate(1000, sudoku);
			bool result = 0;
			int answer[81];
			result = core.solve(sudoku[3], answer);
			Assert::AreEqual(result, true);
		}
		
		TEST_METHOD(solve) {
			int puzzle[81] = { 0, 0, 0, 8, 0, 9, 0, 2, 0, 7, 0, 0, 0, 0, 0, 8, 4, 5, 0, 0, 5, 0, 7, 6, 0, 9, 0, 0, 0, 8, 7, 0, 0, 3, 0, 0, 0, 9, 6, 0, 1, 8, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 2, 0, 0, 6, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			int *solution = new int[81];
			Core core;
			bool result = false;
			result = core.solve(puzzle, solution);
			Assert::AreEqual(result, true);
			puzzle[0] = 8;
			result = core.solve(puzzle, solution);
			Assert::AreEqual(result, false);
		}
		TEST_METHOD(generate) {
			Core core;
			Tool tool;
			int result[1000][81], solution[81];
			bool r;
			core.generate(1000, result);
			core.generate(1000, 1, result);
			core.generate(1000, 25, 50, true, result);
			r = core.solve(result[34], solution);
			Assert::AreEqual(r, true);
			core.generate(1000, 20, 50, true, result);
		}
	};
}