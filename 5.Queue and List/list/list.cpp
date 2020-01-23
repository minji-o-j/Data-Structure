#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ======================================================================

void print_list(NODE * list)
{
	printf("(%d: ", length_list(list));//����� ������ �տ� ���´�
	if (length_list(list) > 0)
	{
		int length = length_list(list);
		for (int i = 0; i<length-1; i++)
		{
			printf("%d, ",list->data);
			list = list->link;
		}
		
		printf("%d",list->data);//������ ��� ���
	}
	printf(")\n");
}

// ======================================================================

int length_list(NODE * list)
{
	int length=0;
	if(list == NULL)
		return 0;
	else
	{
		while (list->link != NULL)//��ũ���� NULL�϶�����
		{
			length++;
			list = list->link;
		}
		return length + 1;
	}
}

//// ======================================================================
//
NODE *nth_list(NODE * list, int n)//n��° node�� �ּҸ� return
{
	if ((n<1)||(length_list(list) < n))//n�� 1���� �۰ų� n�� node�������� ū ���� ���
	{
		return NULL;
	}
	else
	{	
		if (n == 1)
		{
			return list;
		}
		else
		{
			for (int i = 0; i < n - 2; i++)//n��° node�� �ּ�: n-1��° node�� link�� ����Ǿ�����.
			{
				list = list->link;
			}
			return list->link;
		}
	}

}
//
// ======================================================================
//

/*NODE *add_list(NODE* list, int item)
{
	NODE * add = (NODE *)malloc(sizeof(NODE));
	add->data = item;
	add->link = list;
	list = add;
	return add;
}�����̰� �Ѱ�*/

NODE *add_list(NODE * list, int item)//�� �տ� node�� ����
{
	
	if (length_list(list) == 0)//list���̰� 0�̸� �׳� ����(data=item, link=NULL)
	{
		list = (NODE *)malloc(sizeof(NODE));

		list->data = item;
		list->link = NULL;
		return list;
	}
	else//list���̰� 0���� ũ�� ���� �ִ� list�� link�� �� �� �Ǿ��� �ּҷ� �ٲ�
	{	
		NODE* nd1= list;//���� list�� �޾Ƴ���
		list = (NODE *)malloc(sizeof(NODE));//(�տ�)���� ���� node�� �����Ҵ�
		list->data = item;
		list->link = nd1;
		return list;
	}


	
	
}

//// ======================================================================
//
NODE *delete_list(NODE * list)//�� ���� node�� ����
{
	if (length_list(list) == 0)
		return NULL;
	else
	{
		list = nth_list(list, 2);//1�� ������ ���� 2��°�� NULL�̶� ������
		return list;
	}
}
//
// ======================================================================
//
//int main(void)
//{
//	NODE *l1, *l2, *l3, *l4;
//
//	// print_list
//	printf("===== test-list0: print_list =====\n");
//
//	l1 = NULL;
//	print_list(l1);
//
//	l1 = (NODE *)malloc(sizeof(NODE));
//	l1->data = 10;
//	l1->link = NULL;
//	print_list(l1);
//
//	l2 = (NODE *)malloc(sizeof(NODE));
//	l2->data = 20;
//	l2->link = NULL;
//	l1->link = l2;
//	print_list(l1);
//
//	l3 = (NODE *)malloc(sizeof(NODE));
//	l3->data = 30;
//	l3->link = NULL;
//	l2->link = l3;
//	print_list(l1);
//
//	l4 = (NODE *)malloc(sizeof(NODE));
//	l4->data = 40;
//	l4->link = NULL;
//	l3->link = l4;
//	print_list(l1);
//
//	return EXIT_SUCCESS;
//}
//// ======================================================================

////------------------------------------->>>>>>>>>>>>>>>testlist1
//int main(void)
//{
//	NODE *l1, *l2, *l3, *l4;
//
//	// length_list
//	printf("===== test-list1: length_list =====\n");
//
//	l1 = NULL;
//	if (length_list(l1) != 0) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l1 = (NODE *)malloc(sizeof(NODE));//����� ����, l1�����?
//	l1->data = 10;//������ �ʵ�
//	l1->link = NULL;//��ũ �ʵ� ����
//	if (length_list(l1) != 1) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l2 = (NODE *)malloc(sizeof(NODE));//�� ��° ��� ����
//	l2->data = 20;//�ι�° �������ʵ�
//	l2->link = NULL;//�ι�° ��ũ �ʵ�
//	l1->link = l2;//ù��°�� ��ũ�ʵ带 �ι�°�ο���
//	if (length_list(l1) != 2) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l3 = (NODE *)malloc(sizeof(NODE));
//	l3->data = 30;
//	l3->link = NULL;
//	l2->link = l3;
//	if (length_list(l1) != 3) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l4 = (NODE *)malloc(sizeof(NODE));
//	l4->data = 40;
//	l4->link = NULL;
//	l3->link = l4;
//	if (length_list(l1) != 4) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	return EXIT_SUCCESS;
//}

// ======================================================================
////------------------------------------->>>>>>>>>>>>>>>testlist2
//int main(void)
//{
//	NODE *l1, *l2, *l3, *l4;
//	NODE *p;
//
//	// nth_list
//	printf("===== test-list2: nth_list =====\n");
//
//	l1 = (NODE *)malloc(sizeof(NODE));
//	l1->data = 10;
//	l1->link = NULL;
//
//	l2 = (NODE *)malloc(sizeof(NODE));
//	l2->data = 20;
//	l2->link = NULL;
//	l1->link = l2;
//
//	l3 = (NODE *)malloc(sizeof(NODE));
//	l3->data = 30;
//	l3->link = NULL;
//	l2->link = l3;
//
//	l4 = (NODE *)malloc(sizeof(NODE));
//	l4->data = 40;
//	l4->link = NULL;
//	l3->link = l4;
//
//	p = nth_list(l1, 0);
//	if (p == NULL)
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	p = nth_list(l1, 1);
//	if ((p != NULL) && (p->data == 10))
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	p = nth_list(l1, 3);
//	if ((p != NULL) && (p->data == 30))
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	p = nth_list(l1, 5);
//	if (p == NULL)
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	return EXIT_SUCCESS;
//}
//
//// ======================================================================
//===-------------------------------->>>>>>>>>>>>>>>>>>testlist3
//int main(void)
//{
//	NODE *l1;
//
//	// nth_list
//	printf("===== test-list3: add_list =====\n");
//
//	l1 = NULL;
//	print_list(l1);
//
//	l1 = add_list(l1, 40);
//	print_list(l1);
//
//	l1 = add_list(l1, 30);
//	print_list(l1);
//
//	l1 = add_list(l1, 20);
//	print_list(l1);
//
//	l1 = add_list(l1, 10);
//	print_list(l1);
//
//	return EXIT_SUCCESS;
//}
////// ======================================================================
//===-------------------------------->>>>>>>>>>>>>>>>>>testlist4
int main(void)
{
	NODE *l1;

	// nth_list
	printf("===== test-list4: delete_list =====\n");

	l1 = NULL;
	l1 = add_list(l1, 50);
	l1 = add_list(l1, 40);
	l1 = add_list(l1, 30);
	l1 = add_list(l1, 20);
	l1 = add_list(l1, 10);

	l1 = delete_list(l1);
	print_list(l1);

	l1 = delete_list(l1);
	print_list(l1);

	l1 = delete_list(l1);
	print_list(l1);

	l1 = delete_list(l1);
	print_list(l1);

	l1 = delete_list(l1);
	print_list(l1);

	l1 = delete_list(l1);
	if (l1 != NULL) {
		printf("ERROR: delete_list\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

