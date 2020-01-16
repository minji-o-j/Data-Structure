#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// ======================================================================

void init_stack(STACK * s)
{
	s->top = -1;
}

// ======================================================================

void print_stack(STACK * s) //stacks에 저장된 data를 출력한다. --------->item의 개수::s->top +1
{
	
	printf("(%d: ", s->top + 1);

	if (s->top + 1 >= 1)
	{
		for (int i = 0; i < s->top; i++)
		{
			printf("%d, ", s->data[i]);
		}

		printf("%d", s->data[s->top]);
	}
	printf(")\n");
}

// ======================================================================

int empty_stack(STACK * s)//stack s가 empty이면 1 아니면 0을 return한다.
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// ======================================================================

int push_stack(STACK * s, int item) //stack s 에 item을 push한 후 stack의 top index를 return한다. 오류이면 error 리턴 //꽉차면 오류
{
	if (s->top == MAX_STACK_SIZE-1)
		return ERROR;

	else
	{
		s->top++;
		s->data[s->top] = item;
		return s->top;
	}
}

// ======================================================================

int pop_stack(STACK * s)// stack s를 pop한 후 pop한 item을 return한다. 만약 오류이면 error 리턴//top가 -1이면 오류
{
	//if (s->top == -1)
		//return ERROR;
	if (empty_stack(s) == 1)
		return ERROR;

	else
	{

		return(s->data[s->top--]);

	}
}
// ======================================================================

int main(void)
{
	int i, r;
	STACK s1;

	printf("===== test-stack =====\n");

	init_stack(&s1);
	print_stack(&s1);

	for (i = 0; i < MAX_STACK_SIZE + 100; i++) {
		if (push_stack(&s1, i) == ERROR)
			break;
		print_stack(&s1);
	}

	for (i = 0; i < MAX_STACK_SIZE + 100; i++) {
		if (pop_stack(&s1) == ERROR)
			break;
		print_stack(&s1);
	}

	r = empty_stack(&s1);
	if (r != 1)
		printf("ERROR: stack_empty\n");
	else
		printf("OK: stack_empty\n");

	return EXIT_SUCCESS;
}