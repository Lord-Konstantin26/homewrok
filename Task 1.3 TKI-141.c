#include <stdio.h>
#include <math.h>

/*
* @brief Считывает вещественное число.
* @return Вещественое число.
*/
double Input(void);

/*
* @brief Рассчитывает расстояние между двумя одинаковыми шарами.
* @param weight Масса шаров.
* @return Расстояние между шарами.
*/
double GetDistance(const double weight);

/*
* @brief Точкак входа в программу.
* @return \c 0 в случае выполнения без ошибок.
*/
int main()
{
	puts("Введите массу шаров");
	double weight = Input();
	printf_s("Расстояние %lf", GetDistance(weight));

	return 0;
}

double Input(void)
{
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}

double GetDistance(const double weight)
{
	const double F = pow(10, -5);
	const double G = 6.67 * pow(10, -11);
	return sqrt((G * weight * weight) / F);
}