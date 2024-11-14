#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <float.h>
#include <locale.h>
#include <stdbool.h> 

/*
* @brief Считает нашу функцию.
* @param x - значение параметра.
* @return Значение функции.
*/
double GetFunctionValue(const double x);

/*
* @brief Проверяет, можно ли вычислить функцию для заданного значения x.
* @param x Значение x, которое требуется проверить.
* @return true, если функцию можно вычислить для данного значения x, false в противном случае.
*/
bool GetCheckX(const double  x);

/*
* @brief Функция проверки ввода.
* @return Возвращает значение, если верное, иначе выдает ошибку.
*/
double Input(void);

/*
* @brief Проверяет коректность заданного интервала.
* @param start_x начальное значение интервала.
* @param finish_x конечное значение интервала.
* @return Возвращает ошибку если интервал задан неверно.
*/
void CheckInterval(const double start_x, const double finish_x);

/*
* @brief Проверяет коректность заданного шага.
* @param step_x значение шага.
* @return Возвращает ошибку если шаг задан неверно.
*/
void CheckStep(const double step_x);

/*
* @brief Точка входа в программу.
* @return Возвращает значение функции с заданным в цикле корнем.
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    puts("Введите начальное значение x:");
    const double start_x = Input();
    puts("Введите конечное значение x:");
    const double finish_x = Input();
    puts("Введите значение шага");
    const double step_x = Input();
    CheckInterval(start_x, finish_x);
    CheckStep(step_x);
    double x = start_x;

    while (x <= finish_x + DBL_EPSILON)
    {
        if (GetCheckX(start_x))
        {
            printf("x = %lf y = % lf\n", x, GetFunctionValue(x));
        }
        else
        {
           printf("X не существет в функции %2lf\n", x);
        }

        x += step_x;
    }
    return 0;
}

bool GetCheckX(const double  x)
{
    return x > 0 + DBL+EPSILON;
}

void CheckInterval(const double start_x, const double finish_x)
{
    if (finish_x - start_x < DBL_EPSILON)
    {
        puts("Ошибка Input");
        exit(EXIT_FAILURE);
    }
}

void CheckStep(const double step_x)
{
    if (step_x <= DBL_EPSILON)
    {
        puts("Ошибка Input");
        exit(EXIT_FAILURE);
    }
}

double Input(void)
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        puts("Ошибка Input");
        exit(EXIT_FAILURE);
    }
    return value;
}

double GetFunctionValue(const double x)
{
    return 3 * pow(log(x), 2) + 6 * log(x) - 5;
}
