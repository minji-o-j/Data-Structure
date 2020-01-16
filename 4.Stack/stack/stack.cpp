#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// ======================================================================

void init_stack(STACK * s)
{
	s->top = -1;
}

// ======================================================================

void print_stack(STACK * s) //stacks�� ����� data�� ����Ѵ�. --------->item�� ����::s->top +1
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

int empty_stack(STACK * s)//stack s�� empty�̸� 1 �ƴϸ� 0�� return�Ѵ�.
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// ======================================================================

int push_stack(STACK * s, int item) //stack s �� item�� push�� �� stack�� top index�� return�Ѵ�. �����̸� error ���� //������ ����
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

int pop_stack(STACK * s)// stack s�� pop�� �� pop�� item�� return�Ѵ�. ���� �����̸� error ����//top�� -1�̸� ����
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