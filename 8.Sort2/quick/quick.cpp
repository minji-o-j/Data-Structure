// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

// ======================================================================

int partition(int list[], int left, int right)
{
	//left는 list에서 가장 왼쪽 index, right는 list에서 가장 오른쪽 index
	int low = left;			//low: 가장 왼쪽 index부터 시작, 증가할 예정(오른쪽으로 이동) 처음 분할 과정이 실행될 때 list[left]는 피벗이므로 low=left+1을 할 필요가 없다.
	int high = right+1;		//high: 맨 끝(오른쪽)index+1부터 시작, 감소할 예정(왼쪽으로 이동)
	int pivot = list[left];	//list[left]를 피벗으로 정함
	int t;					//swap을 위해 선언했음


	do 
	{
		do				//첫번째 실행(시작단계), 조건 만족할 때: low를 1증가
		{
			low++;		//low를 오른쪽으로 이동
		} while ((low <= right) && (pivot > list[low]));	//low를 증가해가며 피벗보다 큰 값을 찾을 예정


		do				//첫번째 실행(시작단계), 조건 만족할 때: high를 1 감소
		{
			high--;		//high를 왼쪽으로 이동
		} while ((left <= high) && (pivot < list[high]));	//high를 감소해가며 피벗보다 작은 값을 찾을 예정


		if (low < high)	//low와 high가 교차되지 않은 상태라면
		{
			SWAP(list[low], list[high], t); //list[low]와 list[high]를 교환한다.
		}

	} while (low < high);//교차되기 전까지 반복


	//low가 high보다 같거나 커진 상태
	SWAP(list[left],list[high],t);	//피벗과 list[high]를 교환한다
	return high;	//이동된 pivot의 위치 반환
}

// ======================================================================

// ======================================================================

//int grade[MAX_LIST_LENGTH] = { 5,3,8,4,9,1,6,2,7 };
int grade[MAX_LIST_LENGTH] = { 5,7,4,9,8,5,6,3 };

// ======================================================================

int main(void)
{
	quick_sort_log(grade, 0, MAX_LIST_LENGTH - 1);

	return EXIT_SUCCESS;
}

// ======================================================================

void quick_sort_log(int list[], int left, int right)
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

	quick_sort(list, left, right);

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

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		printf("pivot [%d:%d]->[%d:%d]\n", left, list[q], q, list[q]);
		quick_sort_log(list, left, q - 1);
		quick_sort_log(list, q + 1, right);
	}
}

// ======================================================================