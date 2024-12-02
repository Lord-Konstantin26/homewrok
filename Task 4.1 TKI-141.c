#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
* @brief Выделяет память под массив целых чисел.
* @param size Размер массива.
* @return Указатель на выделенную память под массив.
*/
int* IntArray(const size_t size);

/*
* @brief Функция проверки ввода.
* @return Возвращает значение, если верное, иначе выдает ошибку.
*/
int Input(void);

/*
* @brief Функция проверки ввода размера массива.
* @return Возвращает значение размера массива, если верное, иначе выдает ошибку.
*/
int InputArray(void);

/**
* @brief Функция проверки массива.
* @param arr - массив, который мы проверяем на NULL.
* @return При непрохождении проверки выдает ошибку.
*/
void CheckArray(int* const arr);

/**
* @brief Заполняет массив случайными или введенными с клавиатуры числами.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void FillingArray(int* arr, const size_t size);

/**
* @brief Заполняет массив, считывая значения с клавиатуры.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void FillingArrayKeyboard(int* arr, const size_t size);

/**
* @brief Заполняет массив случайными числами в заданном диапазоне.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void FullRandomArray(int* arr, const size_t size);

/**
* @brief Выводит массив на экран.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void PrintArray(const int* arr, const size_t size);

/**
* @brief Выполняет задание 1: перемножает четные элементы, значение модуля которых меньше пяти.
* @param arr Указатель на массив.
* @param size Размер массива.
* @return Произведение четных элементов, значение модуля которых меньше пяти, если таких элементов нет возвращает ноль.
*/
int MultiEvenElements(const int* arr, const size_t size);

/**
* @brief Выполняет задание 2: находит количество нечетных элементов, значение модуля которых больше заданного числа.
* @param arr Указатель на массив.
* @param size Размер массива.
* @return Количество нечетных элементов, значение модуля которых больше заданного числа,если таких элементов нет возвращает ноль.
*/
int CountOddElements(const int* arr, const size_t size);

/**
* @brief Выполняет задание 3: умножает нечетные и кратные трем элементы на их номер.
* @param arr Указатель на массив.
* @param arr2 Указатель на массив, в который будут записаны результаты умножения.
* @param size Размер массива.
* @return Новый массив после выполнения задания 3.
*/
int* SecondArrayTask3(const int* arr, int* arr2, const size_t size);

/**
* @brief Перечисление для выбора способа заполнения массива.
*/
enum TASK {
    RANDOM,
    KEYBOARD
};

/*
* @brief Точка входа в программу.
* @return Возвращает значение функции с заданным в цикле корнем.
*/
int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    puts("Введите количество элементов в массиве: ");
    size_t size = InputArray();

    int* arr = IntArray(size);
    FillingArray(arr, size);

    printf("\nИсходный массив: ");
    PrintArray(arr, size);

    printf("\nПроизведение четных элементов, значение модуля которых меньше пяти: %d\n", MultiEvenElements(arr, size));

    printf("\nКоличество нечетных элементов, значения модуля которых больше заданного числа: %d\n", CountOddElements(arr, size));

    printf("\nМассив после умножения нечетных элементов кратных трем на их номер: ");
    int* arr2 = IntArray(size);
    PrintArray(SecondArrayTask3(arr, arr2, size), size);

    free(arr);
    free(arr2);

    return 0;
}

int Input(void)
{
    int input;
    if (scanf_s("%d", &input) != 1)
    {
        puts("Ошибка ввода\a");
        exit(EXIT_FAILURE);
    }

    return input;
}

int InputArray(void)
{
    int value = Input();
    if (value <= 0)
    {
        puts("Размер массива должен быть больше нуля.\a");
        exit(EXIT_FAILURE);
    }

    return value;
}

void CheckArray(int* const arr)
{
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
}

int* IntArray(const size_t size)
{
    int* arr = (int*)malloc(size * sizeof(int));
    CheckArray(arr);
    return arr;
}

void FullRandomArray(int* arr, const size_t size)
{
    puts("Введите минимальную границу случайных чисел: ");
    const int DownBound = Input();
    puts("Введите максимальную границу случайных чисел: ");
    const int UpBound = Input();

    if (DownBound > UpBound)
    {
        puts("Неправильно введена граница чисел!\a");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (UpBound - DownBound + 1) + DownBound;
    }
}

void FillingArrayKeyboard(int* arr, const size_t size)
{
    printf("\nВведите %zu целых чисел для заполнения массива: ", size);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = Input();
    }
}

void FillingArray(int* arr, const size_t size)
{
    printf("\nКаким способом вы хотите заполнить массив?\n"
        "Случайные числа - %d\n"
        "Ввод с клавиатуры - %d\n", RANDOM, KEYBOARD);

    int a = Input();
    enum TASK choice = (enum TASK)a;

    switch (choice) {
    case RANDOM:
        FullRandomArray(arr, size);
        break;
    case KEYBOARD:
        FillingArrayKeyboard(arr, size);
        break;
    default:
        printf("Неправильный номер задания!\a");
        exit(EXIT_FAILURE);
    }
}

void PrintArray(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int MultiEvenElements(const int* arr, const size_t size)
{
    int com = 1;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0 && abs(arr[i]) < 5)
        {
            com *= arr[i];
        }
        else
        {
            return 0;
        }
    }

    return com;

}

int CountOddElements(const int* arr, const size_t size)
{
    puts("Ввидите любое целое число: ");
    int number = Input();
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0 && abs(arr[i]) > number)
        {
            count++;
        }
        else
        {
            return 0;
        }
    }
    return count;
}

int* SecondArrayTask3(const int* arr, int* arr2, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0 && arr[i] % 3 == 0)
        {
            arr2[i] = arr[i] * i;
        }
        else
        {
            arr2[i] = arr[i];
        }
    }
    return arr2;
}
