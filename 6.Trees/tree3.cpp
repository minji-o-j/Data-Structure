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


	if (root == NULL)//root�� ���������
	{
		root = n; //root�� n�� ����Ŵ(n�� �ֻ��� ���)
	}
	NODE*t = root;//������ t�� root�� ����Ŵ

	while (t!=NULL)					//t�� NULL����Ű�� �ʴ´ٸ� ��� �ݺ���
	{
		if (key == t->key)			//t�� key�� �������� �ϴ� key�� ���ٸ�
		{
			return root;			//root ��ȯ(t�� ��ġ:root)
		}

		else if (key < t->key)		//������ �ϴ� key��  t�� key���� ������
		{	
			if (t->left != NULL)	//������� �ʴٸ� ��� Ž��
				t = t->left;		//t�� ������ ����Ŵ
			else                    //t->left==NULL�� ��
				t->left = n;		//t->left�� n�� ����

		}

		else						//������ �ϴ� key��  t�� key���� Ŭ��
		{
			if (t->right != NULL)	//������� �ʴٸ� ��� Ž��
				t = t->right;		//������ ����Ŵ
			else                    //t->right==NULL�� ��
				t->right = n;		//t->right�� n�� ����

			
		}
	} 
	//Q---------->	���� t=t->right ���� ������ �̵��� �Ѵٸ� n�� ��� �־���ұ�?
	return root; //�ֻ��� ��� ����
}

// ======================================================================

void print_inorder(NODE * root)//����Ž�����̹Ƿ� LDR
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
