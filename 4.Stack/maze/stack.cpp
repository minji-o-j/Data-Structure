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
	if (s->top == MAX_STACK_SIZE - 1)
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
	if (s->top == -1)
		return ERROR;
	else
	{

		return(s->data[s->top--]);

	}
}
// ======================================================================