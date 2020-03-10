// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

// ======================================================================

void bubble_sort(int list[], int n)
{
	int t;											//t: swap할 때 이용할 예정
	for (int i=n-1;i>0;i--)							
		    //step 반복 결정, 처음에는 list[0]~list[n-1]까지 정렬이 필요하지만 내부 for문이 반복될 때 i번째 항목은 list[0]~list[i] 중 가장 큰 것이 배치되기 때문에 바깥쪽 for문이 반복될 때 마다 i--을 함
	{

		for (int j=0;j<i;j++)						//j=0부터 j=i-1까지, j와 j+1을 비교할 예정.
		{
			if (list[j] > list[j + 1])				//list[j]가 list[j+1]보다 크면
				SWAP(list[j], list[j + 1], t);		//list[j]와 list[j+1]을 바꿈
		//	print_array(list, n);
		}
		print_array(list, n);//리스트를 출력
		//printf("\n");
	}

}

// ======================================================================
// ======================================================================

int grade[MAX_LIST_LENGTH] = {
  5, 3, 8, 1, 2, 7
};

// ======================================================================

int main(void)
{
	print_array(grade, MAX_LIST_LENGTH);
	bubble_sort(grade, MAX_LIST_LENGTH);

	return EXIT_SUCCESS;
}

// ======================================================================

void print_array(int list[], int n)
{
	static int step = 0;
	int i;

	printf("step %d: ", step++);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}

// ======================================================================