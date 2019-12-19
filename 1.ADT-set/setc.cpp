// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "setc.h"

// ======================================================================

SET *create(void)
{
	SET *NewSet = (SET*)malloc(sizeof(SET));//���� �Ҵ�
	for(int i=0;i<sizeof(NewSet->OneSet)/sizeof(int);i++) //�� ���� ����
		NewSet->OneSet[i] = NULL;
	NewSet->count = 0;
	return NewSet;
}
// ======================================================================
int member(SET * set, int element)
{
	for (int i = 0; i < set->count; )
	{
		if (element == set->OneSet[i])
		{
			return TRUE; //�ϳ��� ����: TRUE ��ȯ
		}

		else if (element != set->OneSet[i])
		{
			i++;
		}
		
	}
	return 0;
}
// ======================================================================

int length(SET * set)
{
	return set->count;//set->count�� ����
}

// ======================================================================

SET *insert(SET * set, int element)
{
	if (member(set, element) == 0)//element�� ������ ������
	{
		set->OneSet[set->count] = element;//�迭�� �� ���� �ϳ� �ִ´�
		set->count ++;//�迭�� ���̸� �ϳ� �ø���
		return set;//�� �迭�� ��ȯ�Ѵ�
	}
	//���� ���� ����
	else
	{
		return set;//���� ���Ұ� �����ϸ� �ȳְ� �� ����
	}

}
// ======================================================================

SET *_delete(SET * set, int element)
{
	for (int i = 0; i<set->count; i++)
	{
		if (set->OneSet[i] == element)
		{
			for (;i<set->count-1;i++)
			{
				set->OneSet[i] = set->OneSet[i + 1];//i+1��°�� i��°�� ����
			}
			set->count--;
		}
	}
	return set;
}
// ======================================================================

SET *sunion(SET * set1, SET * set2)
{
	SET*set3;
	set3 = create();
	for (int i=0; i < set1->count; i++)
	{
		insert(set3,set1->OneSet[i]);
	}
	for (int j=0; j < set2->count; j++)
	{
		insert(set3, set2->OneSet[j]);
	}

	return set3;
}
// =====================================================================
SET *intersection(SET * set1, SET * set2)
{
	SET*set4;
	set4 = create();//set1�� set2�� ������ ������ �װ͸� ���� set4�� ����
	for (int i = 0; i < set1->count; i++)
	{
		for (int j = 0; j < set2->count; j++)
		{
			if (set1->OneSet[i] == set2->OneSet[j])
			{
				insert(set4, set1->OneSet[i]);

			}
		}
	}
	return set4;

}

// ======================================================================

SET *difference(SET * set1, SET * set2)
{
	SET*set5;
	set5 = create();
	
	for (int i = 0; i < set1->count; i++)//set1�� set 5�� �޾ƿ�
	{
		insert(set5,set1->OneSet[i]);
	}
	for (int j = 0; j < set2->count; j++)
	{
		_delete(set5, set2->OneSet[j]);
	}
	return set5;
}

// ======================================================================

void print(SET * set)
{
	printf("{");
	for (int i = 0; i < set->count-1; i++)
	{
		printf("%d, ",set->OneSet[i]);
	}
	printf("%d}\n", set->OneSet[set->count-1]);
}

// ======================================================================

int main(void)
{
	SET *s1, *s2, *s3, *s4, *s5, *s6;

	// s1
	s1 = create();
	s1 = insert(s1, -10);
	s1 = insert(s1, 30);
	s1 = insert(s1, -20);
	s1 = insert(s1, 5);
	s1 = insert(s1, -20);
	s1 = insert(s1, 90);
	s1 = insert(s1, -70);

	printf("s1=");
	print(s1);

	// s2
	s2 = create();
	s2 = insert(s2, 5);
	s2 = insert(s2, -15);
	s2 = insert(s2, -20);
	s2 = insert(s2, -50);
	s2 = insert(s2, 15);
	s2 = insert(s2, -70);
	s2 = insert(s2, 90);
	s2 = insert(s2, -3);
	printf("s2=");
	print(s2);

	// member
	if (member(s1, 30) == TRUE)
		printf("member(s1,30)=TRUE\n");
	else if (member(s1, 30) == FALSE)
		printf("member(s1,30)=FALSE\n");
	else
		printf("member(s1,30)=???\n");

	if (member(s2, 99) == TRUE)
		printf("member(s2,-90)=TRUE\n");
	else if (member(s2, 99) == FALSE)
		printf("member(s2,-90)=FALSE\n");
	else
		printf("member(s2,-90)=???\n");

	// length
	printf("length(s1)=%d\n", length(s1));
	printf("length(s2)=%d\n", length(s2));

	// s3 = s1 U s2
	s3 = sunion(s1, s2);
	printf("s1Us2=");
	print(s3);

	// s4 = s1 ^ s2
	s4 = intersection(s1, s2);
	printf("s1^s2=");
	print(s4);

	// s5 = s1 - s2
	s5 = difference(s1, s2);
	printf("s1-s2=");
	print(s5);

	// s6 = s2 - s1
	s6 = difference(s2, s1);
	printf("s2-s1=");
	print(s6);

	return EXIT_SUCCESS;
}

// ======================================================================
