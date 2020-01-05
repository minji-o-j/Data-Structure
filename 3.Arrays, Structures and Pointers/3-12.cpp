#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct q12 {
	char str[15] = { 0 };
	int num;
}Q12;
int main(void)
{
	Q12*s1 = (Q12*)malloc(sizeof(Q12));
	s1->num = 100;
	strcpy(s1->str,"just testing");
	printf("%d, %s", s1->num, s1->str);
	free(s1);
	return 0;
}