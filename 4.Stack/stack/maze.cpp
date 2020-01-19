// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// ======================================================================

void print_maze(MAZE * maze)											//������ ���
{	
	maze->map[maze->here_r][maze->here_c] = '*';						// here_r�� here_c(���� ��, ��)�� *�� �ٲ�
	for (int i = 0; i < MAX_MAZE_SIZE; i++)								//2���� �迭 ���(6*6 ����)
	{
		for (int j = 0; j < MAX_MAZE_SIZE; j++)
		{
			printf("%c ", maze->map[i][j]);
		}
		printf("\n");
	}
}

// ======================================================================

void push_loc(MAZE * maze, int r, int c)
{

	if (r < 0 || c < 0)
		return;

	if (maze->map[r][c] != '1'&&maze->map[r][c] != '.')
	{
		push_stack(maze->stack, r);
		push_stack(maze->stack, c);
		print_stack(maze->stack);											//stack�� �� ���� ������ stack ���빰 ���
	}
	
}


// ======================================================================

int run_maze(MAZE * maze)
{

	push_loc(maze, maze->here_r, maze->here_c + 1); //��
	push_loc(maze, maze->here_r + 1, maze->here_c); //��
	push_loc(maze, maze->here_r, maze->here_c - 1); //��
	push_loc(maze, maze->here_r - 1, maze->here_c); //��

	maze->map[maze->here_r][maze->here_c] = '.';

	if (empty_stack(maze->stack) == 1)
		return 3;
	
	maze->here_c = pop_stack(maze->stack);
	maze->here_r = pop_stack(maze->stack);
	
	if (maze->map[maze->here_r][maze->here_c] == 'x')
	{
		printf("============\n");
		print_maze(maze);
		return 1;
	}

	return 2;

}


// ======================================================================
//===================================================================

char map1[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {
  {'1', '1', '1', '1', '1', '1'},
  {'e', '0', '1', '0', '0', '1'},
  {'1', '0', '0', '0', '1', '1'},
  {'1', '0', '1', '0', '1', '1'},
  {'1', '0', '1', '0', '0', 'x'},
  {'1', '1', '1', '1', '1', '1'},
};

// ======================================================================

int main(void)
{
	int r;
	MAZE maze1;

	maze1.map = map1;
	maze1.stack = (STACK*)malloc(sizeof(STACK));			//stack ��� ���ο� ����ü �Ҵ� 
	init_stack(maze1.stack);								//maze1.stack�� top�� -1�� �ʱ�ȭ
	maze1.here_r = 1;
	maze1.here_c = 0;										//*�� ���� ��ġ: 1°�� 0��°��

	for (;;) {												//���ѷ���
		// r = system("clear");
		//r = r;											//���ִ°���...?
		//r = maze1.here_r;									//���� ���Ƿ� �־���(��� ��������)
		printf("============\n");
		print_maze(&maze1);

		r = run_maze(&maze1);
		if (r == FAILED) {
			printf("FAILED!\n");
			break;
		}
		if (r == FOUND) {
			printf("FOUND!\n");
			break;
		} 
		//    getchar();
	}

	return EXIT_SUCCESS;
}

// ======================================================================
