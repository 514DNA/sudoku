#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;
#define addr2line(addr) ((addr)/9)
#define addr2row(addr) ((addr)%9)
#define linerow2squared(line,row) (3*((line)/3)+((row)/3))

class __declspec(dllexport) Core
{
public:
	Core();
	~Core();
	void arrange();
	void loadin_super_squared();
	void back_step();
	int find_another_fit_array(int num);
	void fill_sudoku();
	int read_soduku(FILE *fp);
	bool solve_sudoku();
	void create_sudoku(int n);
	void create_test_sudoku();
	int check_puzzle(int i, int j, int n);
	void set_play(bool a);
	void create_sudoku_puzzle(int n, int mode);
	void create_sudoku_puzzles(int block_num, int mode, int n);
	void create_random_sudoku();
	void solve_all_soduku(FILE *fp);
	void generate(int number, int** result);
	void generate(int number, int mode, int** result);
	void generate(int number, int lower, int upper, bool unique, int** result);
	bool solve(int* puzzle, int* solution);
private:
	int data[9][9];
	int step[81];
	int step_num;
	int line_target[9];
	int row_target[9];
	int squared_target[9];
	int back_data[9][9];
	int back_line_target[9];
	int back_row_target[9];
	int back_squared_target[9];
	int num_buf[81];
	int num_buf_length;
	int stack[9][9];
	int stack_top[9];
	int super_squared[3][9];
	int num_possibility[9][64][6];
	int num_possibility_top[9];
	int flag[64][6];
	int num_flag[3];
	int is_new_array;
	int result_flag[9];
	int first_num_addr;
	int first_num_max_addr;
	char File_buf[164];
	char file_buf[20000];
	int file_buf_top = 0;
	FILE *output;
	int **resultStore;
	bool test = false;
	bool play = false;
	void unfold(int *puzzle);
	void fold(int *solution);
	void close_file();
	void init_sudoku();
	void arrange(int count);
	int arrange_result();
	void print_sudoku(int mode);
	void print_sudoku_to_cmd();
	void print_arrange();
	void add_addr(int addr, int num);
	void clear_addr(int addr);
	int to_next(int i, int j, int n);
	int init_check_puzzle();
	void data_to_back();
	void back_to_data();
	void data_to_buf();
	void clear_buf();
	int get_first_num_addr(int squared);
	int get_first_num_max_addr(int squared);
	void set_first_num_addr_to_zero(int squared);
	void first_num_addr_to_next();
	int can_delete(int addr);
	int can_delete_senior(int addr);
};
