#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <float.h> 

/**
*@brief Функция подсчета реккурентной функции.
*@param k значение параметра k.
*@return Возвращает k.
*/
double Recurrent(const double k);

/**
*@brief Функция счета суммы по n-ому члену
*@param n - переменна заданная пользователем
*@return Фукнция возвращает значение суммы по n-ому члену
*/
double SummaN(const double n);

/**
*@brief Функция проверки ввода.
*@return Возвращает значение, если верное, иначе выдает ошибку.
*/
double Input(void);

/**
*@brief Функция проверки на ноль.
*@return Возвращает значение, если верное, иначе выдает ошибку.
*/
double CheckZero(void);

/**
*@brief Функция подсчёта суммы ряда.
*@param n значение параметр n.
*@return Возвращает значение суммы.
*/
double SummaE(const int e);

/**
*@brief Фукнция счета суммы с погрешностью e
*@return Возвращает значение посчитанной функции
*/
double InputE(void);

/**
*@brief Функция проверки ввода.
*@return Возвращает значение, если верное, иначе выдает ошибку.
*/
double CheckE(void);

/**
*@brief Точка входа.
*@return Возвращает значение функции с кодом ошибки 0.
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");

	puts("Введите верхний порог");
	int n = CheckZero();
	puts("Введите погрешность");
	double e = CheckE();
	printf("Сумма %d членов: %lf\n", n, SummaN(n));
	printf("Сумма членов с погрешностью: %lf\n", SummaE(e));
	return 0;
}

double Recurrent(const double k)
{
	return -1 / (4 * pow(k, 2) + 6 * k + 2);
}

double SummaN(const double n)
{
	double current = 1;
	double sum = current;

	for (int i = 1; i < n; ++i)
	{
		current *= Recurrent(i);
		sum += current;
	}

	return sum;

}

double SummaE(const int e)
{
	double current = 1;
	double sum = 0;

	for (int i = 1; fabs(current) >= e + DBL_EPSILON; ++i)
	{
		current *= Recurrent(i);
		sum += current;
	}

	return sum;

}

double Input(void)
{
	double input = 0.0;

	if (scanf_s("%lf", &input) != 1)
	{
		printf("Ошибка Input");
		exit(EXIT_FAILURE);
	}

	return input;

}

double CheckZero(void)
{
	int input = Input();

	if (input < DBL_EPSILON)
	{
		printf("Ошибка Input");
		exit(EXIT_FAILURE);
	}

	return input;
}

double InputE(void)
{
	double input = 0.0;
	if (scanf_s("%lf", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

double CheckE(void)
{
	double input = InputE();
	if (input < DBL_EPSILON)
	{
		puts("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}