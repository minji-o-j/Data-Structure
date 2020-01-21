#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// ======================================================================
// ======================================================================

void init_queue(QUEUE * q)
{
	q->front = 0;
	q->rear = 0;
}

// ======================================================================

void print_queue(QUEUE * q)
{
	int item_num= (q->rear) - (q->front);
	
	while (item_num < 0)
	{
		item_num += MAX_QUEUE_SIZE;
	}
	printf("(%d|%d|%d: ", q->front, q->rear, item_num);
	if (item_num > 0)
	{
		for (int i = 0; i < (item_num)-1; i++)
		{
			printf("%d, ",q->data[(q->front+i+1)%MAX_QUEUE_SIZE]);
		}
		printf("%d", q->data[q->rear]);
	}
	printf(")\n");
}

// ======================================================================

int empty_queue(QUEUE * q)
{
	if (q->front == q->rear)
		return 1;//empty
	else
		return 0;
}

// ======================================================================

int full_queue(QUEUE * q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == (q->front))
	{
		return 1;
	}
	else
		return 0;
}

// ======================================================================
int en_queue(QUEUE * q, int item)
{
	if (full_queue(q) == 1)
		return ERROR;
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;//rearÀ» ´ÙÀ½Ä­À¸·Î ¿Å±è
		q->data[q->rear] = item;//ÇÑÄ­ ´Ã¾î³­ rear¿¡ item »ðÀÔ
		return q->data[q->rear];
	}
}

// ======================================================================

int de_queue(QUEUE * q)
{
	if (empty_queue(q) == 1)
		return ERROR;
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

// ======================================================================




int main(void)
{
	int item = 10, r;
	QUEUE q1;

	printf("===== test-queue =====\n");

	init_queue(&q1);
	print_queue(&q1);

	for (;;) {
		if (en_queue(&q1, item++) == ERROR)
			break;
		print_queue(&q1);
		if (en_queue(&q1, item++) == ERROR)
			break;
		print_queue(&q1);
		if (de_queue(&q1) == ERROR)
			break;
		print_queue(&q1);
	}

	r = full_queue(&q1);
	if (r != 1)
		printf("ERROR: full_queue\n");
	else
		printf("OK: full_queue\n");

	for (;;) {
		if (de_queue(&q1) == ERROR)
			break;
		print_queue(&q1);
		if (de_queue(&q1) == ERROR)
			break;
		print_queue(&q1);
		if (en_queue(&q1, item++) == ERROR)
			break;
		print_queue(&q1);
	}

	r = empty_queue(&q1);
	if (r != 1)
		printf("ERROR: empty_queue\n");
	else
		printf("OK: empty_queue\n");

	return EXIT_SUCCESS;
}