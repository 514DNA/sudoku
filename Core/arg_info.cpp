#include "arg_info.h"

	/*	-c 0x1 0
	-s 0x2 1
	-n 0x4 2
	-m 0x8 3
	-r 0x10 4
	-u 0x20 5
	*/

arg_info::arg_info()
	{
		arg_bit = 0;
		c_or_n_arg = 0;
		m_arg = 0;
		r_arg[0] = 0;
		r_arg[1] = 0;
		s_arg = NULL;
		fp = NULL;
	}
void arg_info::set_arg_bit_on(int mode)
	{
		if (mode >= 0 && mode <= 5)
			arg_bit |= (1 << mode);
		return;
	}
int arg_info::str2num(char *str)
	{
		int i = 0;
		int num = 0;
		char c = '\0';
		while (str[i] != '\0')
		{
			c = str[i];
			if (c<'0' || c>'9')
			{
				return -1;
			}
			num = (num * 10) + c - '0';
			i++;
			if (i > 16)
				return -2;
		}
		return num;
	}

int arg_info::str2range_num(char *str) {
		int sign = 0, num = 0, i = 0;
		for (i = 0; i < (strlen(str)); i++) {
			if (str[i] <= '9' && str[i] >= '0') {
				num = num * 10 + (str[i] - '0');
			}
			else if (sign == 0 && str[i] == '~') {
				sign = 1;
				if (num >= 20 && num <= 55) {
					r_arg[0] = num;
					num = 0;
				}
				else {
					return -1;
				}
			}
			else {
				return -1;
			}
		}
		if (sign == 1 && num >= r_arg[0] && num <= 55) {
			r_arg[1] = num;
		}
		else {
			return -1;
		}
		return 0;
	}

void arg_info::error_out(int error) {
		switch (error) {
		case -1:
			cout << "The number format is incorrect or the number is out of range" << endl;
			break;
		case -2:
			cout << "The file does not exist or format of the file is incorrect" << endl;
			break;
		case -3:
			cout << "Illegal arg or illegal number of args" << endl;
			break;
		case -4:
			cout << "Incorrect combination of args" << endl;
			break;
		case -5:
			cout << "The option lacks of necessary arg" << endl;
			break;
		default:
			break;
		}
		return;
	}

int arg_info::read_arg_info(int argc, char **argv)
	{
		int i = 1, num = 0, error = 0;
		if (argc < 3)
		{
			cout << "Error:" << endl;
			return -3;
		}
		while (i < argc)
		{
			if (argv[i][0] != '\0'&&argv[i][1] != '\0'&&argv[i][0] == '-'&&argv[i][2] == '\0')
			{
				switch (argv[i][1])
				{
				case('c'):
					if (arg_bit != 0) {
						return -4;
						break;
					}
					else {
						if (i + 1 == argc) {
							return -5;
							break;
						}
						else {
							i++;
							num = str2num(argv[i++]);
							if (1 <= num && num <= 1000000) {
								c_or_n_arg = num;
								set_arg_bit_on(0);
							}
							else {
								return -1;
								break;
							}
						}
					}
					break;
				case('s'):
					if (arg_bit != 0) {
						return -4;
						break;
					}
					else {
						if (i + 1 == argc) {
							return -5;
							break;
						}
						else {
							i++;
							char *path = argv[i++], format[5] = { '\0' };
							int j = 3, k = 0, length = strlen(path);
							for (k = length - 1; k >= length - 4; k--) {
								format[j--] = path[k];
							}
							if (strcmp(format, ".txt") != 0) {
								return -2;
								break;
							}
							fopen_s(&fp, path, "r");
							if (!fp) {
								return -2;
								break;
							}
							else {
								s_arg = path;
								set_arg_bit_on(1);
							}
						}
					}
					break;
				case('n'):
					if ((arg_bit & (~0x8)) == 0 || (arg_bit & (~(0x10 | 0x20))) == 0) {
						if (i + 1 == argc) {
							return -5;
							break;
						}
						else {
							i++;
							num = str2num(argv[i++]);
							if (1 <= num && num <= 10000) {
								c_or_n_arg = num;
								set_arg_bit_on(2);
							}
							else {
								return -1;
								break;
							}
						}
					}
					else {
						return -4;
						break;
					}
					break;
				case('m'):
					if ((arg_bit & (~0x4)) == 0) {
						if (i + 1 == argc) {
							return -5;
							break;
						}
						else {
							i++;
							num = str2num(argv[i++]);
							if (1 <= num && num <= 3) {
								m_arg = num;
								set_arg_bit_on(3);
							}
							else {
								return -1;
								break;
							}
						}
					}
					else {
						return -4;
						break;
					}
					break;
				case('r'):
					if ((arg_bit &(~(0x4 | 0x20))) == 0) {
						if (i + 1 == argc) {
							return -5;
							break;
						}
						else {
							i++;
							if (str2range_num(argv[i++]) == 0) {
								set_arg_bit_on(4);
							}
							else {
								return -1;
								break;
							}
						}
					}
					else {
						return -4;
						break;
					}
					break;
				case('u'):
					if ((arg_bit & (~(0x4 | 0x10))) == 0) {
						i++;
						set_arg_bit_on(5);
					}
					else {
						return -4;
						break;
					}
					break;
				default:
					return -4;
					break;
				}
			}
			else
			{
				cout << "Error:" << endl;
				return -3;
			}
			//i++;
		}
		if (arg_bit == 0xc || arg_bit == 0x34 || arg_bit == 0x14 || arg_bit == 0x24 || arg_bit == 0x1 || arg_bit == 0x2)
			return 0;
		else
			return -4;
	}
void arg_info::run_cmd(int argc, char **argv)
	{
		int error = 0;
		int i = 0;
		Core s0;
		error = read_arg_info(argc, argv);
		if (error < 0)
		{
			error_out(error);
			return;
		}
		else
		{
			if (arg_bit & 0x1)
			{
				s0.create_sudoku(c_or_n_arg);
				return;
			}
			if (arg_bit & 0x2)
			{
				s0.solve_all_soduku(fp);
				return;
			}
			if (arg_bit & 0x4)
			{
				srand((int)time(0));
				if (arg_bit & 0x8)
				{
					if (m_arg == 1)
						s0.create_sudoku_puzzles(35, 0, c_or_n_arg);
					else if (m_arg == 2)
						s0.create_sudoku_puzzles(35, 1, c_or_n_arg);
					else if (m_arg == 3)
						s0.create_sudoku_puzzles(55, 0, c_or_n_arg);
					return;
				}
				else if (arg_bit & 0x10)
				{
					if (arg_bit & 0x20)
					{
						s0.create_sudoku_puzzles(r_arg[0], 0, c_or_n_arg);
						return;
					}
					else
					{
						s0.create_sudoku_puzzles(r_arg[0], 2, c_or_n_arg);
						return;
					}
				}
				else if (arg_bit & 0x20) {
						s0.create_sudoku_puzzles(20, 0, c_or_n_arg);
				}
				return;
			}
		}
		return;
	}

