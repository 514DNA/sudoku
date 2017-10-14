#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../sudoku/sudoku.cpp"
//#include "Puzzle.h"
#include "../sudoku/generate.cpp"
#include "Tool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//Tool tool;
		TEST_METHOD(SingleSolution)
		{
			Core core;
			core.create_sudoku_puzzle(1, 3);
			int result = 0;
			result = core.check_puzzle(0, 0, 0);
			Assert::AreEqual(result, 1);
		}
		TEST_METHOD(LegalSudoku) {
			int result = 0;
			Core core;
			core.create_random_sudoku();
			core.solve_sudoku();
			Assert::AreEqual(result, 0);
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
			int **result = tool.CreateArray(1000, 81);
			core.generate(1000, result);
			core.generate(1000, 1, result);
			core.generate(1000, 25, 50, true, result);
		}
	};
}