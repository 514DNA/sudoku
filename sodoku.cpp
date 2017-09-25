#include "iostream.h"
class puzzle
{
private:
	int num[9][9];
public:
	puzzle()
	{
		int i=0;
		int j=0;
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				num[i][j]=0;
	}
	int get_num(int i,int j)
	{
		return(num[i][j]);
	}
};
int main()
{
	class puzzle p0;
	int i=0;
	for(i=0;i<9;i++)
		cout<<p0.get_num(i,i)<<endl;
	return 0;
}