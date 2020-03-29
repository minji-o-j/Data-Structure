// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

// ======================================================================

void insertion_sort(int list[], int n)
{
	int left = 0;											//왼쪽 리스트의 마지막 항목의 index
	int right = left + 1;									//right: 오른쪽 리스트의 시작 index
	
	
	for (; right < n; left++, right = left + 1)		//오른쪽 리스트의 시작 index부터 n-1까지, left는 1씩 증가하고 right는 left+1임(left값이 바뀔때마다 갱신)
	{
		int rv = list[right];								//list[right]에 있는 값을 rv(right value)에 저장


		for (int i = left; i >= 0 && list[i] > rv; i--)		//왼쪽 리스트의 마지막번째부터 rv값과 비교, rv값이 list[i]보다 클 때 종료
		{
			list[i + 1] = list[i];							//list[i+1]을 list[i]로 바꿈
			list[i] = rv;									//list[i]에는 rv 값 넣음 -->for문이 종료되면 왼쪽 리스트는 정렬된 상태임
		}

		print_array(list, n);								//리스트를 출력

	
	}
	//for (; right < n; )		//오른쪽 리스트의 시작 index부터 n-1까지, left는 1씩 증가하고 right는 left+1임(left값이 바뀔때마다 갱신)
	//{
	//	
	//	int rv = list[right];								//list[right]에 있는 값을 rv(right value)에 저장


	//	for (int i = left; i >= 0 && list[i] > rv; i--)		//왼쪽 리스트의 마지막번째부터 rv값과 비교, rv값이 list[i]보다 클 때 
	//	{
	//		list[i + 1] = list[i];							//list[i+1]을 list[i]로 바꿈
	//		list[i] = rv;									//list[i]에는 rv 값 넣음 -->for문이 종료되면 왼쪽 리스트는 정렬된 상태임
	//	}

	//	print_array(list, n);								//리스트를 출력
	//	right = ++left;

	//}



	
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
	insertion_sort(grade, MAX_LIST_LENGTH);

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