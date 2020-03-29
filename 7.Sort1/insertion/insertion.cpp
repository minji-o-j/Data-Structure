// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

// ======================================================================

void insertion_sort(int list[], int n)
{
	int left = 0;											//���� ����Ʈ�� ������ �׸��� index
	int right = left + 1;									//right: ������ ����Ʈ�� ���� index
	
	
	for (; right < n; left++, right = left + 1)		//������ ����Ʈ�� ���� index���� n-1����, left�� 1�� �����ϰ� right�� left+1��(left���� �ٲ𶧸��� ����)
	{
		int rv = list[right];								//list[right]�� �ִ� ���� rv(right value)�� ����


		for (int i = left; i >= 0 && list[i] > rv; i--)		//���� ����Ʈ�� ��������°���� rv���� ��, rv���� list[i]���� Ŭ �� ����
		{
			list[i + 1] = list[i];							//list[i+1]�� list[i]�� �ٲ�
			list[i] = rv;									//list[i]���� rv �� ���� -->for���� ����Ǹ� ���� ����Ʈ�� ���ĵ� ������
		}

		print_array(list, n);								//����Ʈ�� ���

	
	}
	//for (; right < n; )		//������ ����Ʈ�� ���� index���� n-1����, left�� 1�� �����ϰ� right�� left+1��(left���� �ٲ𶧸��� ����)
	//{
	//	
	//	int rv = list[right];								//list[right]�� �ִ� ���� rv(right value)�� ����


	//	for (int i = left; i >= 0 && list[i] > rv; i--)		//���� ����Ʈ�� ��������°���� rv���� ��, rv���� list[i]���� Ŭ �� 
	//	{
	//		list[i + 1] = list[i];							//list[i+1]�� list[i]�� �ٲ�
	//		list[i] = rv;									//list[i]���� rv �� ���� -->for���� ����Ǹ� ���� ����Ʈ�� ���ĵ� ������
	//	}

	//	print_array(list, n);								//����Ʈ�� ���
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