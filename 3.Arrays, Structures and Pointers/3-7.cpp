#include <stdio.h>
typedef struct complex
{
	int real;
	int imag;
}Complex;
Complex complex_add(Complex a, Complex b)//복소수를 더한다
{
	Complex Add;
	Add.real = a.real + b.real;
	Add.imag = a.imag + b.imag;
	return Add;
}
int main(void)
{
	Complex NewCom1, NewCom2;
	printf("첫 번째 복소수 x1 + y1 * i에서\nx1: ");
	scanf("%d", &NewCom1.real);
	printf("y1: ");
	scanf("%d", &NewCom1.imag);

	printf("두 번째 복소수 x2 + y2 * i에서\nx2: ");
	scanf("%d", &NewCom2.real);
	printf("y2: ");
	scanf("%d", &NewCom2.imag);

	printf("두 복소수의 합은 %d + %d *i", complex_add(NewCom1, NewCom2).real, complex_add(NewCom1, NewCom2).imag);

	return 0;
}