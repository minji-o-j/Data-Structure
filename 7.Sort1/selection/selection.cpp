// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

// ======================================================================

void selection_sort(int list[], int n)
{
	int s;												//s는 swap에 이용하기 위해 선언함
	int least_index;									//list의 오른쪽 리스트에서 최솟값을 찾기 위해 선언

	for (int i = 0; i < n-1; i++)						//i:오른쪽 리스트의 시작 index, 오른쪽 리스트의 시작 index가 n-2이면 정렬 마지막단계
	{
	
		least_index = i;								//오른쪽 리스트에서 최솟값을 찾을 것이므로 오른쪽 리스트의 시작 index를 least_index에 저장

		for (int j = i+1; j < n; j++)					//j:오른쪽 리스트의 두 번째 index부터 n-1번째 index까지 증가, 함수가 시작될 때 오른쪽 리스트의 첫번째 index가 저장된 least_index와 비교를 하므로 j는 두번째 index부터 시작
		{
			if (list[least_index] > list[j])			
				least_index = j;						//list[j]가 list[least_index]보다 작으면 least_index에 j를 저장

		}
		SWAP(list[i], list[least_index], s);			//오른쪽 리스트의 첫번째 index의 값을 오른쪽 리스트에서 최솟값으로 변경
		print_array(list, n);							//리스트를 출력
	}

}

// ======================================================================


int grade[MAX_LIST_LENGTH] = {
  5, 3, 8, 1, 2, 7
};

// ======================================================================

int main(void)
{
	print_array(grade, MAX_LIST_LENGTH);
	selection_sort(grade, MAX_LIST_LENGTH);

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