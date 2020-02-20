// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree3.h"

// ======================================================================

NODE *insert_node(NODE * root, int key)
{
	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->left = NULL;
	n->right = NULL;
	n->key = key;


	if (root == NULL)//root가 비어있으면
	{
		root = n; //root가 n을 가리킴(n이 최상위 노드)
	}
	NODE*t = root;//포인터 t는 root를 가리킴

	while (t!=NULL)					//t가 NULL가리키지 않는다면 계속 반복함
	{
		if (key == t->key)			//t의 key가 넣으려고 하는 key와 같다면
		{
			return root;			//root 반환(t의 위치:root)
		}

		else if (key < t->key)		//넣으려 하는 key가  t의 key보다 작을때
		{	
			if (t->left != NULL)	//비어있지 않다면 계속 탐색
				t = t->left;		//t는 왼쪽을 가리킴
			else                    //t->left==NULL일 때
				t->left = n;		//t->left를 n과 연결

		}

		else						//넣으려 하는 key가  t의 key보다 클때
		{
			if (t->right != NULL)	//비어있지 않다면 계속 탐색
				t = t->right;		//오른쪽 가리킴
			else                    //t->right==NULL일 때
				t->right = n;		//t->right를 n과 연결

			
		}
	} 
	//Q---------->	만약 t=t->right 같은 식으로 이동을 한다면 n을 어떻게 넣어야할까?
	return root; //최상위 노드 리턴
}

// ======================================================================

void print_inorder(NODE * root)//중위탐색법이므로 LDR
{
	if (root != NULL)
	{
		print_inorder(root->left);
		printf("(%d)", root->key);
		print_inorder(root->right);
	}
}

// ======================================================================
int main(void)
{
	int key;
	NODE *t1;

	printf("===== test-tree3 =====\n");

	key = 30;
	printf("insert=%d\n", key);
	t1 = insert_node(NULL, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 80;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 90;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 10;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 70;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 50;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 60;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 20;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	key = 40;
	printf("insert=%d\n", key);
	t1 = insert_node(t1, key);
	printf("tree=");
	print_inorder(t1);
	printf("\n");

	return EXIT_SUCCESS;
}

// ======================================================================
