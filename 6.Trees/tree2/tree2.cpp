// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree2.h"

// ======================================================================

NODE *create_node(int item)
{
	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->left = NULL;
	n->right = NULL;
	n->data = item;
	return n;
}

// ======================================================================

void add_child(NODE * root, NODE * left, NODE * right)
{
	root->left = left;
	root->right = right;
}
// ======================================================================

int sum_tree(NODE * root)
{
	if (root!= NULL)//root가 있을때
	{
		int sum1 = root->data;
		sum1 = sum1 + sum_tree(root->left) + sum_tree(root->right);//재귀함수로 root의 왼쪽과 오른쪽을 더함
		return sum1;//합을 반환
	}
	return 0; //root가 존재하지 않는 경우 0을 반환
}

// ======================================================================

int main(void)
{
	int sum;
	NODE *t0, *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11;

	printf("===== test-tree2 =====\n");

	t0 = create_node(0);
	t1 = create_node(10);
	t2 = create_node(20);
	t3 = create_node(30);
	t4 = create_node(40);
	t5 = create_node(50);
	t6 = create_node(60);
	t7 = create_node(70);
	t8 = create_node(80);
	t9 = create_node(90);
	t10 = create_node(100);
	t11 = create_node(110);

	add_child(t3, t7, t8);
	add_child(t4, t9, t10);
	add_child(t5, t11, NULL);
	add_child(t1, t3, t4);
	add_child(t2, t5, t6);
	add_child(t0, t1, t2);

	sum = sum_tree(t0);
	printf("sum_tree(t0)=%d\n", sum);

	sum = sum_tree(t1);
	printf("sum_tree(t1)=%d\n", sum);

	sum = sum_tree(t2);
	printf("sum_tree(t2)=%d\n", sum);

	sum = sum_tree(t4);
	printf("sum_tree(t4)=%d\n", sum);

	sum = sum_tree(t5);
	printf("sum_tree(t5)=%d\n", sum);

	return EXIT_SUCCESS;
}

// ======================================================================