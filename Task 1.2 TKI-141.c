#include <stdio.h>

/*
* @brief Считывает вещественное число.
* @return Вещественное число.
*/ 
double Input(void);

/*
* @brief Рассчитывет количестуво дюймов.
* @param cantimetre Количество сантиметров.
* @return Количество дюймов
*/
double GetInch(const double cantimetre);

/*
* @brief Точка входа в программу.
* @return \c 0 в случае выполнения без ошибок.
*/
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
	const double toInch = 2.5
	return cantimetre / toInch;
}