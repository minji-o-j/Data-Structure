// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

// ======================================================================

void merge(int list[], int left, int mid, int right)
{
	//mid�� ���� ������ 2n �Ǵ� 2n+1�� �� �� n��° ������
	//left�� list[]�� ���� �迭���� �� ���� ������ index
	//������ �迭�� ù ��° index�� mid+1(���� ������ n�� �� �� n+1��°)
	//right�� list[](�� ������ �迭) ���� �� ������ ������ index

	int newMerge[MAX_LIST_LENGTH];			//�迭�� �����ϰ� ���Ľ�ų ����
	int li = left;							//li(left index): list[]���� (���ĵ�)���� �迭��  index(���� �迭 ó��~mid)
	int ri = mid + 1;						//ri(right index): list[]���� (���ĵ�)������ �迭�� index(mid+1(������ �迭 ó��)~right)
	int index = left;						//newMerge�� index

	while ((li <=mid)&&(ri <= right))		//���� �迭�� index����:���� �迭 ó��(left)~mid �̰� ������ �迭�� index ����: ������ �迭�� ó��(mid+1)~right
	{
		if (list[li] < list[ri])			//���� �迭�� index�� ����Ű�� ���� ������ �迭�� index�� ����Ű�� ������ ���� ���
		{
			newMerge[index] = list[li];		//���� �׸��� ����
			li++;
			index++;
		}
		else //list[li] >= list[ri])		//������ �迭�� index�� ����Ű�� ���� ���� �迭�� index�� ����Ű�� ������ ���� ���
		{
			newMerge[index] = list[ri];		//������ �׸��� ����
			ri++;
			index++;
		}
		
	}

	if (li <= mid)// ��i�� mid+1�̸� ���� ������ ������ newMerge�� ���ٴ� �̾߱��̹Ƿ� �׷��� ���� ���.
	{
		for (; li < mid+1; li++) //���� ������ �����ִ°� ����(���ĵ� �����̹Ƿ� �������⸸ �ϸ� ��)
		{
			newMerge[index] = list[li];
			index++;
		}
	}
	else// ri�� ������ newMerge�� ���� �ʾ��� ��, ri<=right�� ���
	{
		for (; ri < right + 1; ri++)  //������ ������ �����ִ°� ����(���ĵ� �����̹Ƿ� �������⸸ �ϸ� ��)
		{
			newMerge[index] = list[ri];
			index++;
		}
	}

	for (int c = left; c<=right; c++) //list�� newMerge(���ĵ� �׸�)���� ����
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