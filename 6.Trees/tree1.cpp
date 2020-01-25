#include <stdio.h>
#include <stdlib.h>
#include "tree1.h"

// ======================================================================

void init_tree(TREE * t)
{
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		t->data[i] = -1;
	}
}

// ======================================================================

void preorder_tree(TREE * t, int root)//ÀüÀ§Å½»ö, DLR
{
	if ((t->data[root] != ERROR)&&(root<MAX_TREE_SIZE))
	{
		printf("(%d)", t->data[root]);
		preorder_tree(t, root * 2);
		preorder_tree(t, root * 2 + 1);
	}
}

 //======================================================================

void inorder_tree(TREE * t, int root)//ÁßÀ§Å½»ö, LDR
{
	if ((t->data[root] != ERROR) && (root < MAX_TREE_SIZE))
	{
		inorder_tree(t, root * 2);
		printf("(%d)", t->data[root]);
		inorder_tree(t, root * 2 + 1);
	}
}

// ======================================================================

void postorder_tree(TREE * t, int root)//ÈÄÀ§Å½»ö, LRD
{
	if ((t->data[root] != ERROR) && (root < MAX_TREE_SIZE))
	{
		postorder_tree(t, root * 2);
		postorder_tree(t, root * 2 + 1);
		printf("(%d)", t->data[root]);
	}
}

// ======================================================================


// ======================================================================

int main(void)
{
	int i;
	TREE t1;

	printf("===== test-tree1 =====\n");

	init_tree(&t1);
	for (i = 1; i < MAX_TREE_SIZE - 3; i++)
		t1.data[i] = 10 + i;

	printf("preorder=");
	preorder_tree(&t1, 1);
	printf("\n");

	printf("inorder=");
	inorder_tree(&t1, 1);
	printf("\n");

	printf("postorder=");
	postorder_tree(&t1, 1);
	printf("\n");

	return EXIT_SUCCESS;
}

// ======================================================================