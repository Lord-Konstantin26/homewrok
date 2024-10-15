#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>
#include<locale.h>

/*
* @brief Функция проверки введенных значений.
* @return Возвращает значение, если выполнено успешно, иначе выдает ошибку.
*/
double Input(void);

/*
* @brief Выставляет по возрастанию числа a, b, c.
* @param a Число a.
* @param b Число b.
* @param c Число c.
* @return Возвращает введенные числа в порядке возрастания.
*/
double GetIncreasing(const double a, const double b, const double c);

/*
* @brief Выставляет по убыванию числа a, b, c.
* @param a Число a.
* @param b Число b.
* @param c Число c.
* @return Возвращает введенные числа в порядке убывания.
*/
double GetDecreasing(const double a, const double b, const double c);

/*
* @brief Точка входа  в программу.
* @return 0 в случае успеха.
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите a:");
	double a = Input();
	puts("Введите b:");
	double b = Input();
	puts("Введите c:");
	double c = Input();

	printf("%lf %lf %lf\n", GetIncreasing(a, b, c));
	printf("%lf %lf %lf", GetDecreasing(a, b, c));

	return 0;
}

double Input(void)
{
	double value = 0.0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Не удается посчитать значение");
		exit(EXIT_FAILURE);
	}
	return value;
}


double GetIncreasing(const double a, const double b, const double c)
{
	if ((a > b) && (b > c))
	{
		printf("%lf %lf %lf", a, b, c);
	}
	else if ((a > c) && (c > b))
	{
		printf("%lf %lf %lf", a, c, b);
	}
	else if ((b > a) && (a > c))
	{
		printf("%lf %lf %lf", b, a, c);
	}
	else if ((b > c) && (c > a))
	{
		printf("%lf %lf %lf", b, c, a);
	}
	else if ((c > a) && (a > b))
	{
		printf("%lf %lf %lf", c, a, b);
	}
	else if ((c > b) && (b > a))
	{
		printf("%lf %lf %lf", c, b, a);
	}

	return 0;
}

double GetDecreasing(const double a, const double b, const double c)
{
	if ((a < b) && (b < c))
	{
		printf("%lf %lf %lf", a, b, c);
	}
	else if ((a < c) && (c < b))
	{
		printf("%lf %lf %lf", a, c, b);
	}
	else if ((b < a) && (a < c))
	{
		printf("%lf %lf %lf", b, a, c);
	}
	else if ((b < c) && (c < a))
	{
		printf("%lf %lf %lf", b, c, a);
	}
	else if ((c < a) && (a < b))
	{
		printf("%lf %lf %lf", c, a, b);
	}
	else if ((c < b) && (b < a))
	{
		printf("%lf %lf %lf", c, b, a);
	}

	return 0;
}