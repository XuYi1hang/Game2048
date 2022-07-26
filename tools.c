#include "tools.h"
#include "game2048.h"

//	判断是否满
static bool is_full(void)
{
	int* num = (int*)viewp;
	for(int i=0; i<16; i++)
	{
		if(0 == num[i])	return false;
	}
	return true;
}

//	随机位置生成2,行随机，列随机
void rand_two(void)
{
	if(is_full())
	{
		return;
	}
	for(;is_move_merge;)
	{
		int x = rand()%4;
		int y = rand()%4;
		//判断随机出来的位置上是否有数字
		if(0 == viewp[x][y])
		{
			viewp[x][y] = 2;
			return;
		}
	}
}

//	显示界面
void show_view(void)
{
	system("clear");
	for(int i=0; i<4; i++)
	{
		printf("---------------------\n");
		for(int j=0; j<4; j++)
		{
			if(viewp[i][j])
			{
				printf("|%4d",viewp[i][j]);
			}
			else
			{
				printf("|    ");
			}
		}
		printf("|\n");	
	}
	printf("---------------------\n");
}

//	判断是否还能继续
bool is_die(void)
{
	if(!is_full())	return false;
	for(int j=0; j<4; j++)
	{
		for(int i=0; i<3; i++)
		{
			if(viewp[i][j] == viewp[i+1][j])	return false;
		}
	}
	for(int i=0; i<4;i++)
	{
		for(int j=0; j<3; j++)
		{
			if(viewp[i][j] == viewp[i][j+1])	return false;
		}
	}
	return true;
}
