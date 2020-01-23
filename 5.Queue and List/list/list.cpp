#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ======================================================================

void print_list(NODE * list)
{
	printf("(%d: ", length_list(list));//노드의 개수를 앞에 적는다
	if (length_list(list) > 0)
	{
		int length = length_list(list);
		for (int i = 0; i<length-1; i++)
		{
			printf("%d, ",list->data);
			list = list->link;
		}
		
		printf("%d",list->data);//마지막 노드 출력
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
		while (list->link != NULL)//링크끝이 NULL일때까지
		{
			length++;
			list = list->link;
		}
		return length + 1;
	}
}

//// ======================================================================
//
NODE *nth_list(NODE * list, int n)//n번째 node의 주소를 return
{
	if ((n<1)||(length_list(list) < n))//n이 1보다 작거나 n이 node개수보다 큰 수인 경우
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
			for (int i = 0; i < n - 2; i++)//n번째 node의 주소: n-1번째 node의 link에 저장되어있음.
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
}혜인이가 한거*/

NODE *add_list(NODE * list, int item)//맨 앞에 node를 만듦
{
	
	if (length_list(list) == 0)//list길이가 0이면 그냥 넣음(data=item, link=NULL)
	{
		list = (NODE *)malloc(sizeof(NODE));

		list->data = item;
		list->link = NULL;
		return list;
	}
	else//list길이가 0보다 크면 새로 넣는 list의 link는 그 전 맨앞의 주소로 바꿈
	{	
		NODE* nd1= list;//이전 list를 받아놓음
		list = (NODE *)malloc(sizeof(NODE));//(앞에)새로 만들 node를 동적할당
		list->data = item;
		list->link = nd1;
		return list;
	}


	
	
}

//// ======================================================================
//
NODE *delete_list(NODE * list)//맨 앞의 node를 제거
{
	if (length_list(list) == 0)
		return NULL;
	else
	{
		list = nth_list(list, 2);//1개 남았을 때도 2번째가 NULL이라서 가능함
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
//	l1 = (NODE *)malloc(sizeof(NODE));//노드의 생성, l1이헤드?
//	l1->data = 10;//데이터 필드
//	l1->link = NULL;//링크 필드 설정
//	if (length_list(l1) != 1) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l2 = (NODE *)malloc(sizeof(NODE));//두 번째 노드 생성
//	l2->data = 20;//두번째 데이터필드
//	l2->link = NULL;//두번째 링크 필드
//	l1->link = l2;//첫번째의 링크필드를 두번째로연결
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

