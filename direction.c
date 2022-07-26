#include "direction.h"
#include "game2048.h"

//	执行向上操作
void up(void)
{
	for(int j=0; j<4; j++)
	{
		int end_line = 0;
		for(int i=1; i<4; i++)
		{
			for(int k=i; k>end_line; k--)
			{
				if(viewp[k][j] && 0 == viewp[k-1][j])
				{
					viewp[k-1][j] = viewp[k][j];
					viewp[k][j] = 0;
					is_move_merge = true;
				}
				else if(viewp[k][j] && viewp[k][j] == viewp[k-1][j])
				{
					viewp[k-1][j] *= 2;
					viewp[k][j] = 0;
					end_line = k;
					is_move_merge = true;
					score += viewp[k-1][j];
				}
			}
		}
	}
}

//	执行向下操作
void down(void)
{
	for(int j=0; j<4; j++)
	{
		int end_line = 3;
		for(int i=2; i>=0; i--)
		{
			for(int k=i; k<end_line; k++)
			{
				if(viewp[k][j] && 0 == viewp[k+1][j])
				{
					viewp[k+1][j] = viewp[k][j];
					viewp[k][j] = 0;
					is_move_merge = true;
				}
				else if(viewp[k][j] && viewp[k][j] == viewp[k+1][j])
				{
					viewp[k+1][j] *= 2;
					viewp[k][j] = 0;
					end_line = k;
					is_move_merge = true;
					score += viewp[k+1][j];
				}
			}
		}
	}
}

//	执行向左操作
void left(void)
{
	for(int i=0; i<4; i++)
	{
		int end_line = 0;
		for(int j=1; j<4; j++)
		{
			for(int k=j; k>end_line; k--)
			{
				if(viewp[i][k] && 0 == viewp[i][k-1])
				{
					viewp[i][k-1] = viewp[i][k];
					viewp[i][k] = 0;
					is_move_merge = true;
				}
				else if(viewp[i][k] && viewp[i][k] == viewp[i][k-1])
				{
					viewp[i][k-1] *= 2;
					viewp[i][k] = 0;
					end_line = k;
					is_move_merge = true;
					score += viewp[i][k-1];
				}
			}
		}
	}
}

//	执行向右操作
void right(void)
{
	for(int i=0; i<4; i++)
	{
		int end_line = 3;
		for(int j=2; j>=0; j--)
		{
			for(int k=j; k<end_line; k++)
			{
				if(viewp[i][k] && 0 == viewp[i][k+1])
				{
					viewp[i][k+1] = viewp[i][k];
					viewp[i][k] = 0;
					is_move_merge = true;
				}
				else if(viewp[i][k] && viewp[i][k] == viewp[i][k+1])
				{
					viewp[i][k+1] *= 2;
					viewp[i][k] = 0;
					end_line = k;
					is_move_merge = true;is_move_merge = true;
					score += viewp[i][k+1];
				}
			}
		}
	}
}
