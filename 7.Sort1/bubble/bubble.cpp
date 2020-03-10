// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

// ======================================================================

void bubble_sort(int list[], int n)
{
	int t;											//t: swap�� �� �̿��� ����
	for (int i=n-1;i>0;i--)							
		    //step �ݺ� ����, ó������ list[0]~list[n-1]���� ������ �ʿ������� ���� for���� �ݺ��� �� i��° �׸��� list[0]~list[i] �� ���� ū ���� ��ġ�Ǳ� ������ �ٱ��� for���� �ݺ��� �� ���� i--�� ��
	{

		for (int j=0;j<i;j++)						//j=0���� j=i-1����, j�� j+1�� ���� ����.
		{
			if (list[j] > list[j + 1])				//list[j]�� list[j+1]���� ũ��
				SWAP(list[j], list[j + 1], t);		//list[j]�� list[j+1]�� �ٲ�
		//	print_array(list, n);
		}
		print_array(list, n);//����Ʈ�� ���
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