#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <locale.h>

/*
* @brief Проверка введеных чисел.
* @return Возвращает введенное число, если выполнено успешно, иначе выдает ошибку.
*/
double Input(void);

/*
* @brief Рассчитывает функцию.
* @param a Известная константа.
* @param x Введенное значение.
* @return Возвращает значение функции.
*/
double Get_function(const double a, const double x);

/*
* @brief Точка входа в программу.
* @return 0 в случае успеха
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	const double a = 2.5;
	puts("Введите х: ");
	double x = Input();
	printf("y = %lf", Get_function(a, x));

	return 0;
}

double Input(void)
{
	double value = 0.0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Не удалось считать число");
		exit(EXIT_FAILURE);
	}

	return value;
}

double Get_function(const double a, const double x)
{
	if (x < 0.5)
	{
		return sqrt(a * (x * x) + 1);
	}
	else if (x == 0.5)
	{
		return a * x + 3;
	}
	else
	{
		return sqrt((a * a) * x - 1);
	}
}