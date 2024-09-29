#include <stdio.h>
#include <stdlib.h>

double Input(void);

double GetInch(const double cantimetre);

int main()
{
	puts("Введите количество сантиметров");
	double cantimetre = Input();
	printf_s("Количество дюймов %lf", GetInch(cantimetre));

	return 0;
}

double Input(void)
{
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}

double GetInch(const double cantimetre)
{
	return cantimetre / 2.5;
}