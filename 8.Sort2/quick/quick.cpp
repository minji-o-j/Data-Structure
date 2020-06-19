// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

// ======================================================================

int partition(int list[], int left, int right)
{
	//left�� list���� ���� ���� index, right�� list���� ���� ������ index
	int low = left;			//low: ���� ���� index���� ����, ������ ����(���������� �̵�) ó�� ���� ������ ����� �� list[left]�� �ǹ��̹Ƿ� low=left+1�� �� �ʿ䰡 ����.
	int high = right+1;		//high: �� ��(������)index+1���� ����, ������ ����(�������� �̵�)
	int pivot = list[left];	//list[left]�� �ǹ����� ����
	int t;					//swap�� ���� ��������


	do 
	{
		do				//ù��° ����(���۴ܰ�), ���� ������ ��: low�� 1����
		{
			low++;		//low�� ���������� �̵�
		} while ((low <= right) && (pivot > list[low]));	//low�� �����ذ��� �ǹ����� ū ���� ã�� ����


		do				//ù��° ����(���۴ܰ�), ���� ������ ��: high�� 1 ����
		{
			high--;		//high�� �������� �̵�
		} while ((left <= high) && (pivot < list[high]));	//high�� �����ذ��� �ǹ����� ���� ���� ã�� ����


		if (low < high)	//low�� high�� �������� ���� ���¶��
		{
			SWAP(list[low], list[high], t); //list[low]�� list[high]�� ��ȯ�Ѵ�.
		}

	} while (low < high);//�����Ǳ� ������ �ݺ�


	//low�� high���� ���ų� Ŀ�� ����
	SWAP(list[left],list[high],t);	//�ǹ��� list[high]�� ��ȯ�Ѵ�
	return high;	//�̵��� pivot�� ��ġ ��ȯ
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