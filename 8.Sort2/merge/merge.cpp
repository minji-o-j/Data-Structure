// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

// ======================================================================

void merge(int list[], int left, int mid, int right)
{
	//mid는 원소 개수가 2n 또는 2n+1개 일 때 n번째 원소임
	//left는 list[]의 왼쪽 배열에서 맨 왼쪽 원소의 index
	//오른쪽 배열의 첫 번째 index는 mid+1(원소 개수가 n개 일 때 n+1번째)
	//right는 list[](의 오른쪽 배열) 에서 맨 오른쪽 원소의 index

	int newMerge[MAX_LIST_LENGTH];			//배열을 복사하고 정렬시킬 공간
	int li = left;							//li(left index): list[]에서 (정렬된)왼쪽 배열의  index(왼쪽 배열 처음~mid)
	int ri = mid + 1;						//ri(right index): list[]에서 (정렬된)오른쪽 배열의 index(mid+1(오른쪽 배열 처음)~right)
	int index = left;						//newMerge의 index

	while ((li <=mid)&&(ri <= right))		//왼쪽 배열의 index범위:왼쪽 배열 처음(left)~mid 이고 오른쪽 배열의 index 범위: 오른쪽 배열의 처음(mid+1)~right
	{
		if (list[li] < list[ri])			//왼쪽 배열의 index가 가리키는 값이 오른쪽 배열의 index가 가리키는 값보다 작은 경우
		{
			newMerge[index] = list[li];		//왼쪽 항목을 저장
			li++;
			index++;
		}
		else //list[li] >= list[ri])		//오른쪽 배열의 index가 가리키는 값이 왼쪽 배열의 index가 가리키는 값보다 작은 경우
		{
			newMerge[index] = list[ri];		//오른쪽 항목을 저장
			ri++;
			index++;
		}
		
	}

	if (li <= mid)// ㅣi가 mid+1이면 왼쪽 정렬의 끝까지 newMerge에 들어갔다는 이야기이므로 그렇지 않은 경우.
	{
		for (; li < mid+1; li++) //왼쪽 정렬의 남아있는것 복사(정렬된 상태이므로 가져오기만 하면 됨)
		{
			newMerge[index] = list[li];
			index++;
		}
	}
	else// ri가 끝까지 newMerge에 들어가지 않았을 때, ri<=right인 경우
	{
		for (; ri < right + 1; ri++)  //오른쪽 정렬의 남아있는것 복사(정렬된 상태이므로 가져오기만 하면 됨)
		{
			newMerge[index] = list[ri];
			index++;
		}
	}

	for (int c = left; c<=right; c++) //list에 newMerge(정렬된 항목)들을 복사
	{
		list[c] = newMerge[c];
	}


}

// ======================================================================

// ======================================================================

int grade[MAX_LIST_LENGTH] = {
  27, 10, 12, 20, 25, 13, 15, 22
};

// ======================================================================

int main(void)
{
	merge_sort_log(grade, 0, MAX_LIST_LENGTH - 1);

	return EXIT_SUCCESS;
}

// ======================================================================

void merge_sort_log(int list[], int left, int right)
{
	static int recursion = 0;
	int i;

	recursion = recursion + 1;

	for (i = 0; i < recursion; i++)
		printf("|");
	printf("+ ");
	for (i = left; i <= right; i++) {
		printf("[%d:%d]", i, list[i]);
	}
	printf("\n");

	merge_sort(list, left, right);

	for (i = 0; i < recursion; i++)
		printf("|");
	printf("- ");
	for (i = left; i <= right; i++) {
		printf("[%d:%d]", i, list[i]);
	}
	printf("\n");

	recursion = recursion - 1;
}

// ======================================================================

void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort_log(list, left, mid);
		merge_sort_log(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

// ======================================================================