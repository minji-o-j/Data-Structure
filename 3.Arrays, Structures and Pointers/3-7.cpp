#include <stdio.h>
typedef struct complex
{
	int real;
	int imag;
}Complex;
Complex complex_add(Complex a, Complex b)//���Ҽ��� ���Ѵ�
{
	Complex Add;
	Add.real = a.real + b.real;
	Add.imag = a.imag + b.imag;
	return Add;
}
int main(void)
{
	Complex NewCom1, NewCom2;
	printf("ù ��° ���Ҽ� x1 + y1 * i����\nx1: ");
	scanf("%d", &NewCom1.real);
	printf("y1: ");
	scanf("%d", &NewCom1.imag);

	printf("�� ��° ���Ҽ� x2 + y2 * i����\nx2: ");
	scanf("%d", &NewCom2.real);
	printf("y2: ");
	scanf("%d", &NewCom2.imag);

	printf("�� ���Ҽ��� ���� %d + %d *i", complex_add(NewCom1, NewCom2).real, complex_add(NewCom1, NewCom2).imag);

	return 0;
}