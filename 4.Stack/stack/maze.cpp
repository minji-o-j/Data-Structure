// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// ======================================================================

void print_maze(MAZE * maze)											//지도를 출력
{	
	maze->map[maze->here_r][maze->here_c] = '*';						// here_r과 here_c(현재 행, 열)는 *로 바꿈
	for (int i = 0; i < MAX_MAZE_SIZE; i++)								//2차원 배열 출력(6*6 형태)
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
		print_stack(maze->stack);											//stack에 든 것의 개수와 stack 내용물 출력
	}
	
}


// ======================================================================

int run_maze(MAZE * maze)
{

	push_loc(maze, maze->here_r, maze->here_c + 1); //동
	push_loc(maze, maze->here_r + 1, maze->here_c); //남
	push_loc(maze, maze->here_r, maze->here_c - 1); //서
	push_loc(maze, maze->here_r - 1, maze->here_c); //북

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
	maze1.stack = (STACK*)malloc(sizeof(STACK));			//stack 라는 새로운 구조체 할당 
	init_stack(maze1.stack);								//maze1.stack의 top을 -1로 초기화
	maze1.here_r = 1;
	maze1.here_c = 0;										//*의 시작 위치: 1째행 0번째열

	for (;;) {												//무한루프
		// r = system("clear");
		//r = r;											//왜있는거지...?
		//r = maze1.here_r;									//내가 임의로 넣었음(계속 오류떠서)
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
