#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<errno.h>
#include<locale.h>

/*
* @brief Функция проверки введенных значений.
* @return Возвращает значение, если выполнено успешно, иначе выдает ошибку.
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

    printf("%lf\n", GetIncreasing(a, b, c));
    printf("%lf", GetDecreasing(a, b, c));

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

double GetIncreasing(const double a, const double b, const double c)
{
    double max = GetMax(GetMax(a, b), c);
    double middle = GetMin(GetMin(GetMax(a, b), GetMax(b, c)), GetMin(GetMax(a, c), GetMax(b, c)));
    double min = GetMin(GetMin(a, b), c);

    printf("%lf %lf %lf", min, middle, max);
}

double GetDecreasing(const double a, const double b, const double c)
{
    double max = GetMax(GetMax(a, b), c);
    double middle = GetMin(GetMin(GetMax(a, b), GetMax(b, c)), GetMin(GetMax(a, c), GetMax(b, c)));
    double min = GetMin(GetMin(a, b), c);

    printf("%lf %lf %lf", max, middle, min);
}