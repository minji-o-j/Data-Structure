# include <stdio.h>
# include <math.h>
int main(void)
{
	int two[10] = { NULL };
	for(int i=0;i<10;i++)
	{
		two[i] = (int)pow(2, i);
	}
	

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", two[i]);
	}
	//printf("{");
	//for (int j = 0; j < 9; j++)
	//{
	//	printf("%d, ", two[j]);
	//	
	//}
	//printf("%d}", two[9]);
	//printf("%d", sizeof(two));
	return 0;

}