#include <stdio.h>
#include <stdlib.h>

long fib_log(long n);

// ======================================================================

long fib(long n)
{
	if (n == 0) 
		return 0;
	if (n == 1)
		return 1;
	else
		return (fib_log(n - 2) + fib_log(n - 1));

	//반복문 이용

	//if (n == 0) return 0;
	//if (n == 1) return 1;
	//int pp = 0;
	//int p = 1;
	//int result = 0;
	//for (int i = 2; i <= n; i++) {
	//	result = p + pp;
	//	pp = p;
	//	p = result;
	//}
		
}

// ======================================================================

long fib_log(long n)
{
	long i, result;
	static int tabs = 0;

	tabs++;
	for (i = 0; i < tabs; i++)
		printf("+");
	printf(" fib(%ld)\n", n);
	result = fib(n);
	for (i = 0; i < tabs; i++)
		printf("-");
	tabs--;
	printf(" fib(%ld)=%ld\n", n, result);

	return result;
}

// ======================================================================

int main(void)
{
	int r;
	long n;

again:
	printf("n=");
	r = scanf("%ld", &n);
	if (r != 1)
		goto again;
	if (n >= 0)
		fib_log(n);

	return EXIT_SUCCESS;
}

// ======================================================================