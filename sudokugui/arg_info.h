#include "generate.h"
class __declspec(dllexport)  arg_info
{
	/*	-c 0x1 0
	-s 0x2 1
	-n 0x4 2
	-m 0x8 3
	-r 0x10 4
	-u 0x20 5
	*/
public:
	arg_info();
	int read_arg_info(int argc, char **argv);
	void run_cmd(int argc, char **argv);
private:
	int arg_bit;
	int c_or_n_arg;
	int m_arg;
	int r_arg[2];
	char *s_arg;
	FILE *fp;
	int str2num(char *str);
	int str2range_num(char *str);
	void error_out(int error);
	void set_arg_bit_on(int mode);
}; 
