// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "setc.h"

// ======================================================================

SET *create(void)
{
	SET *NewSet = (SET*)malloc(sizeof(SET));//동적 할당
	for(int i=0;i<sizeof(NewSet->OneSet)/sizeof(int);i++) //빈 집합 생성
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
			return TRUE; //하나라도 같음: TRUE 반환
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
	return set->count;//set->count는 길이
}

// ======================================================================

SET *insert(SET * set, int element)
{
	if (member(set, element) == 0)//element와 같은게 없으면
	{
		set->OneSet[set->count] = element;//배열의 맨 끝에 하나 넣는다
		set->count ++;//배열의 길이를 하나 늘린다
		return set;//그 배열을 반환한다
	}
	//동일 원소 존재
	else
	{
		return set;//동일 원소가 존재하면 안넣고 걍 냅둠
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
				set->OneSet[i] = set->OneSet[i + 1];//i+1번째를 i번째에 넣음
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
	set4 = create();//set1과 set2가 같은게 있으면 그것만 빼서 set4에 넣음
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
	
	for (int i = 0; i < set1->count; i++)//set1을 set 5에 받아옴
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
