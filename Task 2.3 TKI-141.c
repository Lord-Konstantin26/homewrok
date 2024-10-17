#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <locale.h>

/*
* @brief Проверка введеных чисел.
* @return Возвращает введенное число, если выполнено успешно, иначе выдает ошибку.
*/
double Input(void);

/*
* @brief Выставляет фунции cos_x, sin_x, ln_x в порядке возрастания, если при каком то значении x функция не имеет смысла выодит только те которые имеют смысл.
* @param x Число x.
* @return Выводит заданные функции в порядке возрастания.
*/
double GetFunctionsInAscendingOrder(const double x);

/*
* @brief Точка входа в программу.
* @return 0 в случае вополнения без ошибок.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    puts("Введите x:");
    double x = Input();

    printf("%lf %lf %lf", GetFunctionsInAscendingOrder(x));

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

double GetFunctionsInAscendingOrder(const double x)
{
    double sin_x = sin(x);
    double cos_x = cos(x);
    double ln_x = log(x);
    if ((x < 0) || (x == 0))
    {
        if (sin_x > cos_x)
        {
            printf("ln_x не имеет смысла");
            printf("%lf %lf", cos_x, sin_x);
        }
        else
        {
            printf("ln_x не имеет смысла");
            printf("%lf %lf", sin_x, cos_x);
        }
        return 0;
    }
    if (x > 0)
    {
        if ((sin_x > cos_x) && (cos_x > ln_x))
        {
            printf("%lf %lf %lf", sin_x, cos_x, ln_x);
        }
        if ((sin_x > cos_x) && (ln_x > cos_x))
        {
            printf("%lf %lf %lf", sin_x, ln_x, cos_x);
        }
        if ((cos_x > sin_x) && (sin_x > ln_x))
        {
            printf("%lf %lf %lf", cos_x, sin_x, ln_x);
        }
        if ((cos_x > ln_x) && (ln_x > sin_x))
        {
            printf("%lf %lf %lf", cos_x, ln_x, sin_x);
        }
        if ((ln_x > sin_x) && (sin_x > cos_x))
        {
            printf("%lf %lf %lf", ln_x, sin_x, cos_x);
        }
        if ((ln_x > cos_x) && (cos_x > sin_x))
        {
            printf("%lf %lf %lf", ln_x, cos_x, sin_x);
        }
        return 0;
    }
    return 0;
}