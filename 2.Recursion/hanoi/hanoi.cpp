// ======================================================================

#include <stdio.h>
#include <stdlib.h>

// ======================================================================

void hanoi(int n, char from, char tmp, char to)
{
	if (n == 1)
	{
		printf("%c -> %c\n", from, to);
	}
	else
	{
		hanoi(n - 1, from, to, tmp);
		printf("%c -> %c\n",from, to);
		hanoi(n - 1, tmp, from, to);
	}
}

// ======================================================================

int main(void)
{
	int r, n;

again:
	printf("n=");
	r = scanf("%d", &n);
	if (r != 1)
		goto again;
	if (n >= 1)
		hanoi(n, 'A', 'B', 'C');

	return EXIT_SUCCESS;
}