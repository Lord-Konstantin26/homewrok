#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

/*
* @brief Проверка введеных чисел.
* @return Возвращает введенное число, если выполнено успешно, иначе выдает ошибку.
*/
double Input(void);

/*
* @brief Ищет максимальное число из двух чисел.
* @param a Число a.
* @param b Число b.
* @return Возвращает максимальное число из двух чисел.
*/
double GetMax(const double a, const double b);

/*
* @brief Ищет минимальное число из двух чисел.
* @param a Число a.
* @param b Число b.
* @return Возвращает минимальное число из двух чисел.
*/
double GetMin(const double a, const double b);

/*
* @brief Выставляет фунции cos_x, sin_x, ln_x в порядке возрастания, если при каком то значении x функция не имеет смысла выодит только те которые имеют смысл.
* @param x Число x.
* @return Выводит заданные функции в порядке возрастания.
*/
void GetFunctionsInAscendingOrder(const double x);

/*
* @brief Точка входа в программу.
* @return 0 в случае вополнения без ошибок.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    puts("Введите x:");
    double x = Input();

    printf("%lf", GetFunctionsInAscendingOrder(x));

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

double GetMax(const double a, const double b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

double GetMin(const double a, const double b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void GetFunctionsInAscendingOrder(const double x)
{
    if (x > 0)
    {
        double max = GetMax(GetMax(sin(x), cos(x)), log(x));
        double middle = GetMin(GetMin(GetMax(sin(x), cos(x)), GetMax(cos(x), log(x))), GetMin(GetMax(sin(x), log(x)), GetMax(cos(x), log(x))));
        double min = GetMin(GetMin(sin(x), cos(x)), log(x));

        printf("%lf %lf %lf", min, middle, max);
    }
    else
    {
        if (sin(x) > cos(x))
        {
            printf("ln_x не имеет смысла\n");
            printf("%lf %lf", sin(x), cos(x));
        }
        else
        {
            printf("ln_x не имеет смысла\n");
            printf("%lf %lf", cos(x), sin(x));
        }
    }
}
