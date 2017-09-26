
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
class sudoku
{
private:
	int data[9][9];
	int step[81];
	int step_num;
	int line_target[9];
	int row_target[9];
	int squared_target[9];
	int back_data[9][9];
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
	char File_buf[164];
	char file_buf[16400];
	int file_buf_top = 0;
	FILE *output;
public:
	sudoku()
	{
		int i = 0;
		int j = 0;
		fopen_s(&output, "sudoku.txt", "w");
		file_buf_top = 0;
/*		if (output == NULL)
			cout << "shit" << endl;*/
		for (i = 0; i < 9; i++)
		{
			line_target[i] = 0;
			row_target[i] = 0;
			squared_target[i] = 0;
			stack_top[i] = 0;
			super_squared[0][i] = i + 1;
			super_squared[1][i] = i + 1;
			super_squared[2][i] = i + 1;
			num_possibility_top[i] = 0;
			for (j = 0; j < 9; j++)
			{
				data[i][j] = 0;
				num_buf[i * 9 + j] = 0;
				step[i*9+ j] = 0;
			}
		}
		for (i = 0; i < 64; i++)
		{
			flag[i][0] = i / 16;
			flag[i][1] = 2 + ((i / 8) % 2) - (2 * (i / 32));
			flag[i][2] = (i % 8) / 2;
			flag[i][3] = 3-(flag[i][1] % 2 + (flag[i][2] / 2) * 2);
			flag[i][4] = (!(flag[i][2] % 2)) + 2*(i % 2);
			flag[i][5]= 3 - (flag[i][0] % 2 + (flag[i][4] / 2) * 2);
/*			for (j = 0; j < 6; j++)
				cout << flag[i][j] << " ";
			cout << "\n";*/
		}
		for (i = 0; i < 3; i++)
			num_flag[i] = 0;
		step_num = 0;
		is_new_array = 1;
		result_flag[0] = 5;
		for(i=1;i<5;i++)
			result_flag[i] = i;
		for(;i<9;i++)
			result_flag[i] = i+1;
		for (i = 0; i < 162; i++)
		{
			if ((i + 1) % 18 == 0)
				File_buf[i] = '\n';
			else
			{
				if (i & 1)
					File_buf[i] = ' ';
				else
					File_buf[i] = '\0';
			}
		}
		File_buf[162] = '\n';
		File_buf[163] = '\0';
	}
	~sudoku()
	{
	//	fclose(output);
	}
	void data_to_back()
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				back_data[i][j] = data[i][j];
	}
	void back_to_data()
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				data[i][j] = back_data[i][j];
	}
	void print_sudoku(int mode)
	{
		int i = 0;
		int j = 0;
/*		for (i = 0; i < 9; i++)
		{
			printf("%d %d %d %d %d %d %d %d %d\n", data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5], data[i][6], data[i][7], data[i][8]);
//			std::cout << "\n";
		}
		std::cout << "\n";*/
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				File_buf[(i * 9 + j) << 1] = '0'+data[i][j];
		if (mode)
			File_buf[161] = '\0';
		fputs(File_buf,output);
	}
	void print_arrange()
	{
		int i = 0;
		for (i = 0; i < 9; i++)
			cout << result_flag[i] << " ";
		cout << "\n";
	}
	void init_sudoku()
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < 9; i++)
		{
			line_target[i] = 0;
			row_target[i] = 0;
			squared_target[i] = 0;
			stack_top[i] = 0;
			for (j = 0; j < 9; j++)
			{
				data[i][j] = 0;
				num_buf[i * 9 + j] = 0;
				step[i*9 + j] = 0;
			}
		}
		result_flag[0] = 5;
		for (i = 1; i<5; i++)
			result_flag[i] = i;
		for (; i<9; i++)
			result_flag[i] = i + 1;
		for (i = 0; i < 64; i++)
		{
			flag[i][0] = i / 16;
			flag[i][1] = 2 + ((i >>3) &1) - ((i >>5)<<1);
			flag[i][2] = (i & 0x7) >>1;
			flag[i][3] = 3 - ((flag[i][1] &1) + (flag[i][2]&0xfffffffe));
			flag[i][4] = (!(flag[i][2] &1)) + ((i &1)<<1);
			flag[i][5] = 3 - ((flag[i][0] &1) + (flag[i][4] &0xfffffffe));
		}
		for (i = 0; i < 3; i++)
			num_flag[i] = 0;
		step_num = 0;
		is_new_array = 1;
	}
	void line_ban_num(int line, int num, int type)
	{
		int i = 0;
		switch(type)
		{
			case(0):
				for (i = 0; i < 9; i++)
					data[line][i] &= (~(1 << (3 + num)));
				break;
			case(1):
				for (i = 0; i < 9; i++)
					data[i][line] &= (~(1 << (3 + num)));
				break;
			case(2):
				for (i = 0; i < 9; i++)
					data[3*(line/3)+i/3][3*(line%3)+i%3] &=(~(1 << (3 + num)));
				break;
		}
	}
	void check_num_in_line(int line, int num, int type)
	{
		int i = 0;
		num_buf_length = 0;
		switch (type)
		{
		case(0):
			for (i = 0; i < 9; i++)
			{
				if (data[line][i] & (1 << (3 + num)))
				{ 
					num_buf[num_buf_length] = line*9+i;
					num_buf_length++;
				}
			}
			break;
		case(1):
			for (i = 0; i < 9; i++)
			{
				if (data[i][line] & (1 << (3 + num)))
				{
					num_buf[num_buf_length] = line + i * 9;
					num_buf_length++;
				}
			}
			break;
		case(2):
			for (i = 0; i < 9; i++)
			{
				if (data[3 * (line / 3) + i / 3][3 * (line % 3) + i % 3] & (1 << (3 + num)))
				{
					num_buf[num_buf_length] = 27 * (line / 3) + 9 * (i / 3) + 3 * (line % 3) + i % 3;
					num_buf_length++;
				}
			}
			break;
		default:
			break;
		}
	}
	int buf_num_is_in_line()
	{
		//001 mains x,010 mains y,100 mains sq
		int result = 7;
		int i=1;
		int temp = num_buf[0];
		if (num_buf_length == 0)
			return 0;
		for (i = 1; i < num_buf_length; i++)
			if (num_buf[num_buf_length] / 9 != temp / 9)
				result &= 0xfffffffe;
			if (num_buf[num_buf_length] % 9 != temp % 9)
				result &= 0xfffffffd;
			if ((num_buf[num_buf_length] % 9)/3+ 3*(num_buf[num_buf_length]/27)!= (temp % 9) / 3 + 3 * (temp / 27))
				result &= 0xfffffffb;
		return result;
	}
	void link_to_buf(int addr)
	{
		num_buf_length = 0;
		int i = 0,j=0;
		int x = 0, y = 0,sq=0,sq_num=0;
		x = addr % 9;
		y = addr / 9;
		sq = 3 * (addr / 27) + (addr % 9) / 3;
		for (i = 0; i < 9; i++)
		{
			if (i != x && data[y][i] == 0)
			{
				num_buf[num_buf_length] = y*9+i;
				num_buf_length++;
			}
			if (i != y && data[i][x] == 0)
			{
				num_buf[num_buf_length] = i*9+x;
				num_buf_length++;
			}
			j = 27 * (sq / 3) + 3 * (sq % 3) + i % 3 + 9 * (i / 3);
			if (j != addr&&j / 9 != addr / 9 && j % 9 != addr % 9 && data[j / 9][j % 9] == 0)
			{
				num_buf[num_buf_length] = j;
				num_buf_length++;
			}
		}
	}
	void clear_addr(int addr)
	{
		int line;
		int row;
		int squared;
		int num;
		line = addr / 9;
		row = addr % 9;
		squared= 3 * (addr / 27) + (addr % 9) / 3;
		num = data[line][row];
		data[line][row] = 0;
		line_target[line] &= (~(1 << (num - 1)));
		row_target[row] &= (~(1 << (num - 1)));
		squared_target[squared] &= (~(1 << (num - 1)));

	}
	void arrange(int count)
	{
		int i = 0, j = 0, temp = 0,temp0=0;
		for (i = 0; i < 9; i++)
			num_possibility_top[i] = 0;
		i = 8;
		is_new_array = 0;
		while (super_squared[count][i] < super_squared[count][i - 1])
		{
			i--;
			if (i == 0)
			{		
				for (j = 0; j < 9; j++)
					super_squared[count][j] = j + 1;
				if(count>0)
					arrange(count - 1);
				return;
			}
		}
		i--;
		j = 8;
		while (super_squared[count][j] < super_squared[count][i])
			j--;
		temp = super_squared[count][i];
		super_squared[count][i] = super_squared[count][j];
		super_squared[count][j] = temp;
		i++;
		j = 8;
		while (i<j)
		{
			temp = super_squared[count][i];
			super_squared[count][i]= super_squared[count][j];
			super_squared[count][j]=temp;
			i++;
			j--;
		}
	}
	int arrange_result()
	{
		int i = 0, j = 0, temp = 0, temp0 = 0;
		i = 8;
		is_new_array = 0;
		while (result_flag[i] <result_flag[i-1])
		{
			i--;
			if (i == 1)
				return 0;
		}
		i--;
		j = 8;
		while (result_flag[j] < result_flag[i])
			j--;
		temp = result_flag[i];
		result_flag[i] = result_flag[j];
		result_flag[j] = temp;
		i++;
		j = 8;
		while (i<j)
		{
			temp = result_flag[i];
			result_flag[i] = result_flag[j];
			result_flag[j] = temp;
			i++;
			j--;
		}
		return 1;
	}
	void arrange()
	{
		arrange(2);
	}
	void loadin_super_squared()
	{
		int i = 0, j = 0, k = 0, p = 0,q=0, num_bit = 1;
		int line = 0, row = 0, squared = 0;
		int buf[4];
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 9; j++)
			{
				line = i * 3 + j / 3;
				row = i * 3 + j % 3;
				squared = i * 4;
				data[line][row] = super_squared[i][j];
				line_target[line] |= (1 << (super_squared[i][j] - 1));
				row_target[row] |= (1 << (super_squared[i][j] - 1));
				squared_target[squared] |= (1 << (super_squared[i][j] - 1));
			}
		}
		for (i = 1; i < 10; i++)
		{
			num_bit = 1 << (i - 1);
			for (j = 0; j < 6; j++)
			{
				squared = j + 1 + j / 3;
				p = 0;
				for (k = 0; k < 9; k++)
				{
					line = 3 * (squared / 3) + k / 3;
					row = 3 * (squared % 3) + k % 3;
					if (!((line_target[line] & num_bit) || (row_target[row] & num_bit)))
					{
						buf[p] = line * 9 + row;
						p++;
					}
				}
				for (q = 0; q < 64; q++)
					num_possibility[i - 1][q][j] = buf[flag[q][j]];

			}
		}
	}
	void back_step()
	{
		int addr, num;
		int line, row, squared;
		step_num--;
		addr = step[step_num];
//		step[step_num] = 0;
		line = addr / 9;
		row = addr % 9;
		squared = 3 * (line / 3) + row / 3;
		num = data[line][row];
		data[line][row] = 0;
		line_target[line] &= (~(1 << (num - 1)));
		row_target[row] &= (~(1 << (num - 1)));
		squared_target[squared] &= (~(1 << (num - 1)));
	}
	int find_another_fit_array(int num)
	{
		int i = 0, j = 0,k=0,temp=0,addr=0;
		if (is_new_array)
		{
			while (i < 9)
			{
				temp = 0;
				for (k = 0; k < 6; k++)
				{
					addr = num_possibility[i][num_possibility_top[i]][k];
					if (num_flag[addr>>5] & (1 << (addr &0x1f)))
					{
						temp = k+1;
						break;
					}
				}
				if (temp)
				{
					switch (temp)
					{
					case 1:
						num_possibility_top[i]+=16;
						break;
					case 2:
						num_possibility_top[i]+=8;
						break;
					case 3:
						num_possibility_top[i]+=2;
						break;
					case 4:
						num_possibility_top[i]+=4;
						break;
					default:
						num_possibility_top[i]+=1;
						break;
					}
				//	num_possibility_top[i]++;
					while (num_possibility_top[i] >= 64)
					{
						num_possibility_top[i] = 0;
						i--;
						if (i < 0)
							return 0;
						for (k=0;k<6;k++)
						{
							addr = num_possibility[i][num_possibility_top[i]][k];
							num_flag[addr>>5] &= (~(1 << (addr&0x1f)));
						}
						num_possibility_top[i]++;
					}
				}
				else
				{
					for (k = 0; k<6; k++)
					{
						addr = num_possibility[i][num_possibility_top[i]][k];
						addr = num_possibility[i][num_possibility_top[i]][k];
						num_flag[addr>>5] |= (1 << (addr&0x1f));
					}
					i++;
				}
			}
		}
		else
		{
			num_possibility_top[0]++;
			i = 0;
			while (i < 9)
			{
				temp = 0;
				for (k = 0; k < 6; k++)
				{
					addr = num_possibility[i][num_possibility_top[i]][k];
					if (num_flag[addr / 30] & (1 << (addr % 30)))
						temp = 1;
				}
				if (temp)
				{
					num_possibility_top[i]++;
					while (num_possibility_top[i] >= 64)
					{
						num_possibility_top[i] = 0;
						i--;
						if (i < 0)
							return 0;
						for (k = 0; k<6; k++)
						{
							addr = num_possibility[i][num_possibility_top[i]][k];
							num_flag[addr / 30] &= (~(1 << (addr % 30)));
						}
						num_possibility_top[i]++;
					}
				}
				else
				{
					for (k = 0; k<6; k++)
					{
						addr = num_possibility[i][num_possibility_top[i]][k];
						addr = num_possibility[i][num_possibility_top[i]][k];
						num_flag[addr / 30] |= (1 << (addr % 30));
					}
					i++;
				}
			}
		}
		return 1;
	}
	void fill_sudoku()
	{
		int i = 0,k=0,addr;
		for (i=0;i<9;i++)
		{
			for (k = 0; k < 6; k++)
			{
				addr = num_possibility[i][num_possibility_top[i]][k];
				data[addr / 9][addr % 9] = i + 1;
			}
		}
	}
	int read_soduku(FILE *fp)
	{
//		FILE *fp;
		int i = 0, j = 0;
		char c;
		int squared = 0,num=0,num_bit=0;
		init_sudoku();
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
			{
				fscanf_s(fp, "%d", &num);
				c = getc(fp);
	//			std::cout << num << std::endl;
				data[i][j] = num;
				if (num != 0)
				{
					num_bit = 1 << (num - 1);
					squared = 3 * (i / 3) + j / 3;
					line_target[i] |= num_bit;
					row_target[j] |= num_bit;
					squared_target[squared] |= num_bit;
				}
				if (c == EOF)
				{
					File_buf[161] = '\0';
					return 0;
				}
			}
		c = getc(fp);
		if (c == EOF)
		{
			File_buf[161] = '\0';
			return 0;
		}
		return 1;

	}
	void solve_sudoku()
	{
		int i = 0,num=1,j=0,result_num=0,num_bit=0,temp_addr=0;
		int line = 0, row = 0, squared = 0,is_fill_in=0;
		int buf[81], buf_top = 0,back_num;
		int blockflag = 0,solve_space=10,solve_addr=0,solve_num=0,temp[2],block_num=0;
		step_num = 0;
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				if (data[i][j] == 0)
					block_num++;
		while (step_num<block_num)
		{
			is_fill_in = 0;
			solve_space = 10;
			for (i = 0; i < 9; i++)
			{
				line = i;
				for (num = 1; num < 10; )
				{
					result_num = 0;
					num_bit = 1 << (num - 1);
					if (line_target[line] & num_bit)
					{
						num++;
						continue;
					}
					for (j = 0; j < 9; )
					{
						row = j;
						squared = 3 * (line / 3) + row / 3;
						if (squared_target[squared] & num_bit)
						{
							j += 3;
							continue;
						}
						if (data[line][row] != 0)
						{
							j++;
							continue;
						}
						if (!((row_target[row] & num_bit)))
						{
							result_num++;
							temp_addr = line * 9 + row;
						}
						j++;
					}
					if (result_num == 1)
					{
						row = temp_addr % 9;
						squared = 3 * (line / 3) + row / 3;
						data[line][row] = num;
						squared_target[squared] |= num_bit;
						line_target[line] |= num_bit;
						row_target[row] |= num_bit;
						step[step_num] = line * 9 + row;
						step_num++;
						is_fill_in = 1;
					}
					num++;
				}
				row = i;
				for (num = 1; num < 10; )
				{
					result_num = 0;
					num_bit = 1 << (num - 1);
					if (row_target[row] & num_bit)
					{
						num++;
						continue;
					}
					for (j = 0; j < 9; )
					{
						line = j;
						squared = 3 * (line / 3) + row / 3;
						if (squared_target[squared] & num_bit)
						{
							j += 3;
							continue;
						}
						if (data[line][row] != 0)
						{
							j++;
							continue;
						}
						if (!((line_target[line] & num_bit)))
						{
							result_num++;
							temp_addr = line * 9 + row;
						}
						j++;
					}
					if (result_num == 1)
					{
						line = temp_addr / 9;
						squared = 3 * (line / 3) + row / 3;
						data[line][row] = num;
						squared_target[squared] |= num_bit;
						line_target[line] |= num_bit;
						row_target[row] |= num_bit;
						step[step_num] = line * 9 + row;
						step_num++;
						is_fill_in = 1;
					}
					num++;
				}
				squared = i;
				for (num = 1; num < 10; )
				{
					result_num = 0;
					num_bit = 1 << (num - 1);
					if (squared_target[squared] & num_bit)
					{
						num++;
						continue;
					}
					for (j = 0; j < 9; )
					{
						line = 3*(squared/3)+j/3;
						row = 3 * (squared%3) + j % 3;
						if ((data[line][row] != 0)||(line_target[line]&num_bit)|| (row_target[row] & num_bit))
						{
							j++;
							continue;
						}
						else
						{
							result_num++;
							temp_addr = line * 9 + row;
						}
						j++;
					}
					if (result_num == 1)
					{
						line = temp_addr / 9;
						row = temp_addr % 9;
						data[line][row] = num;
						squared_target[squared] |= num_bit;
						line_target[line] |= num_bit;
						row_target[row] |= num_bit;
						step[step_num] = line * 9 + row;
						step_num++;
						is_fill_in = 1;
					}
					num++;
				}
			}
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (data[i][j] == 0)
					{
						squared = 3 * (i / 3) + j / 3;
						blockflag = 0;
						blockflag = ((line_target[i] | row_target[j] | squared_target[squared])^0x1ff);
						if (blockflag == 0)
						{
							while (1)
							{
								if (buf_top == 0)
									return;
								back_num = buf[buf_top - 1];
								temp_addr = step[back_num];
								line = temp_addr / 9;
								row = temp_addr % 9;
								squared = 3 * (line / 3) + row / 3;
								num = data[line][row];
								while (step_num > back_num)
								{
									back_step();
			//						print_sudoku();
								}
								num++;
								temp[1] = ((line_target[line] | row_target[row] | squared_target[squared]) ^ 0x1ff);
								while (num < 10)
								{
									num_bit = (1 << (num - 1));
									if (num_bit&temp[1])
									{
										if (temp[1] < (num_bit << 1))
										{
											buf_top--;
											buf[buf_top] = 0;
										}
										data[line][row] = num;
										squared_target[squared] |= num_bit;
										line_target[line] |= num_bit;
										row_target[row] |= num_bit;
										step[step_num] = temp_addr;
										step_num++;
										is_fill_in = 1;
					//					print_sudoku();
										break;
									}
									num++;
								}
								if (num < 10)
									break;
								else
									buf_top--;
/*								if (buf_top < 5)
								{
									print_sudoku();
								}*/
	//							print_sudoku();
							}
						}
						else
						{
							if ((blockflag - 1) ^ blockflag)
							{
								if (is_fill_in == 0)
								{
									temp[0] = blockflag;
									temp[1] = 0;
									while (temp[0])
									{
										if (temp[0] & 1)
											temp[1]++;
										temp[0] >>= 1;
									}
									if (temp[1] < solve_space)
									{
										solve_addr = i * 9 + j;
										solve_space = temp[1];
										num = 1;
										num_bit = 1;
										for (; !(blockflag&num_bit) ; num++)
											num_bit <<= 1;
										solve_num = num;
									}
								}
							}
							else
							{
								num_bit = 1;
								num = 1;
								for (; blockflag != num_bit; num++)
									num_bit <<= 1;
								data[i][j] = num;
								squared_target[squared] |= num_bit;
								line_target[i] |= num_bit;
								row_target[j] |= num_bit;
								step[step_num] = i * 9 + j;
								step_num++;
								is_fill_in = 1;
							}
						}						
					}
				}
			}
			if (step_num >= block_num)
				break;
			else
			{
				if (is_fill_in == 0)
				{
					buf[buf_top] = step_num;
					buf_top++;
					line = solve_addr / 9;
					row = solve_addr % 9;
					squared = 3*(line / 3) + row / 3;
					data[line][row] = solve_num;
					num_bit = (1 << (solve_num - 1));
					squared_target[squared] |= num_bit;
					line_target[line] |= num_bit;
					row_target[row] |= num_bit;
					step[step_num] = solve_addr;
					step_num++;
				}
			}
//			print_sudoku();
		}
		print_sudoku(0);
	}
	void create_sudoku(int n)
	{
		int i = 0,j=0,k=0;
		for (i = 0; i < n;)
		{
			init_sudoku();
			if(i)
				arrange();
			loadin_super_squared();
			find_another_fit_array(9);
			fill_sudoku();
//			arrange_result();
//			print_sudoku();
	//		arrange();
			data_to_back();
			for (j = 0; j < 9; j++)
				for (k = 0; k < 9; k++)
					data[j][k] = result_flag[(back_data[j][k] - 1)];
			print_sudoku(i==(n - 1));
			i++;
			while (i<n&&arrange_result())
			{
				for (j = 0; j < 9; j++)
					for (k = 0; k < 9; k++)
						data[j][k] = result_flag[(back_data[j][k] - 1)];
				print_sudoku(i==(n-1));
				i++;
				if (i >= n)
					break;
			}
			back_to_data();
		}
	}
	void create_random_sudoku()
	{
start:
		int num=1;
		int buf_length=0;
		int squared = 0;
		int inner_addr = 0;
		int addr = 0;
		int i = 0,j=0,k=0,count=0;
		int temp = 0;
		int line;
		int row;
		init_sudoku();
		step_num = 0;
		for (num = 1; num < 10; num++)
		{
	//		data_to_back();
			for (i = 0; i < 9; i++)
				stack_top[i] = 0;
			i = 1 << (num - 1);
			for (squared = 0; squared < 9; squared++)
			{
				num_buf_length = 0;
				for (inner_addr = 0; inner_addr < 9; inner_addr++)
				{
					addr = inner_addr % 3 + 3 * (squared % 3) + 9 * (inner_addr / 3) + 27 * (squared / 3);
					line = addr / 9;
					row = addr % 9;
					if (!((line_target[line] & i) || (row_target[row] & i)||data[line][row]!=0))
					{
						num_buf[num_buf_length] = addr;
						num_buf_length++;
					}
				}
//				cout << num_buf_length << endl;
//				print_sudoku();
				while (num_buf_length==0)
				{
					step_num--;
					squared--;
					for (j = squared + 1; j < 9; j++)
						stack_top[j] = 0;
					if (squared < 0)
					{
						init_sudoku();
						goto start;
					}
					temp = step[step_num];
					stack[squared][stack_top[squared]] = temp;
					stack_top[squared]++;
					clear_addr(temp);
					data[temp / 9][temp % 9] = 0;
					num_buf_length = 0;
					for (inner_addr = 0; inner_addr < 9; inner_addr++)
					{
						addr = inner_addr % 3 + 3 * (squared % 3) + 9 * (inner_addr / 3) + 27 * (squared / 3);
						line = addr / 9;
						row = addr % 9;
						temp = 0;
						for (j = 0; j < stack_top[squared]; j++)
							if (addr == stack[squared][j])
								temp = 1;
						if (!((line_target[line] & i) || (row_target[row] & i) || data[line][row] != 0||temp))
						{
							num_buf[num_buf_length] = addr;
							num_buf_length++;
						}
					}

				}
				addr = num_buf[rand() % num_buf_length];
				line = addr / 9;
				row = addr % 9;
				line_target[line] |= (1 << (num - 1));
				row_target[row] |= (1 << (num - 1));
				squared_target[squared] |= (1 << (num - 1));
				data[line][row] = num;
				step[step_num] = addr;
				step_num++;
			}
		}
	}
	void solve_all_soduku(FILE *fp)
	{
		while (read_soduku(fp))
		{
			solve_sudoku();
		}
		solve_sudoku();
		fclose(fp);
	}
};

int main(int argc,char **argv)
{
	class sudoku s0;
	int i = 0,j=0;
	int N = 0;
	char c = 0;
	FILE *fp;
	if (!strcmp(argv[1],"-s"))
	{
		fopen_s(&fp, argv[2], "r");
		if (fp == NULL)
		{
			cout << "Can't open the file" << endl;
			system("pause");
			return -1;
		}
		s0.solve_all_soduku(fp);
	}
	else if (!strcmp(argv[1], "-c"))
	{

		while (argv[2][i] != '\0')
		{
			N *= 10;
			if (argv[2][i]<'0' || argv[2][i]>'9')
			{
				cout << "argument error" << endl;
				system("pause");
				return -2;
			}
			N += (argv[2][i] - '0');
			i++;
			if (i > 16)
			{
				cout << "argument error" << endl;
				system("pause");
				return -3;

			}
		}
		if (N < 1 || N>1000000)
		{
			cout << "argument error" << endl;
			system("pause");
			return -2;
		}
		s0.create_sudoku(N);
	}
	else
	{
		cout << "argument error" << endl;
		system("pause");
		return -2;
	}
	system("pause");
    return 0;
}

