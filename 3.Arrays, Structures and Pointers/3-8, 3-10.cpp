#include <stdio.h>
#include <stdlib.h>



typedef struct set {
	int arr[1024];
	int items;
}SET;

void insert(int array[], int loc, int value)
{
	int items = 12;
	items += 1;
	for (int i = 0; i < items-loc; i++)
	{
		array[items-1-i] = array[items-2-i];
	}
	array[loc-1] = value;
	
	for (int j = 0; j < items; j++)
	{
		printf("%d ", array[j]);
	}
	printf("\n");
}

int del(int array[], int loc)
{
	int items = 13;
	array[loc-1] = 0;
	for (int i = 0; i < items-loc; i++)
	{
		array[loc-1+i] = array[loc+i];
	}
	items-=1;
	
	for (int j = 0; j < items; j++)
	{
		printf("%d ", array[j]);
	}

	return 0;
}

int main(void)
{

	SET*s1 = (SET*)malloc(sizeof(SET));

	for (int i = 0; i < sizeof(s1->arr) / sizeof(int); i++)
		s1->arr[i] = NULL;

	s1->items = 0;
	s1->arr[0] = 1;
	s1->arr[1] = 3;
	s1->arr[2] = 5;
	s1->arr[3] = 7;
	s1->arr[4] = 9;
	s1->arr[5] = 11;
	s1->arr[6] = 13;
	s1->arr[7] = 15;
	s1->arr[8] = 16;
	s1->arr[9] = 17;
	s1->arr[10] = 18;
	s1->arr[11] = 19;

	insert(s1->arr, 2, 121);
	del(s1->arr, 4);
	return 0;
}