// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

// ======================================================================

void selection_sort(int list[], int n)
{
	int s;												//s�� swap�� �̿��ϱ� ���� ������
	int least_index;									//list�� ������ ����Ʈ���� �ּڰ��� ã�� ���� ����

	for (int i = 0; i < n-1; i++)						//i:������ ����Ʈ�� ���� index, ������ ����Ʈ�� ���� index�� n-2�̸� ���� �������ܰ�
	{
	
		least_index = i;								//������ ����Ʈ���� �ּڰ��� ã�� ���̹Ƿ� ������ ����Ʈ�� ���� index�� least_index�� ����

		for (int j = i+1; j < n; j++)					//j:������ ����Ʈ�� �� ��° index���� n-1��° index���� ����, �Լ��� ���۵� �� ������ ����Ʈ�� ù��° index�� ����� least_index�� �񱳸� �ϹǷ� j�� �ι�° index���� ����
		{
			if (list[least_index] > list[j])			
				least_index = j;						//list[j]�� list[least_index]���� ������ least_index�� j�� ����

		}
		SWAP(list[i], list[least_index], s);			//������ ����Ʈ�� ù��° index�� ���� ������ ����Ʈ���� �ּڰ����� ����
		print_array(list, n);							//����Ʈ�� ���
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