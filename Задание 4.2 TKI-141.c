#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

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
 * @brief Находит индекс последнего, отрицательного элемента в массиве.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 * @return Индекс первого отрицательного элемента или -1, если такого нет.
 */
size_t LastNegativElement(const int* arr, const size_t size);

/**
 * @brief Заменяет последний отрицательный элемент массива на модуль первого элемента массива.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат замены.
 * @param size Размер исходного массива.
 * @return Новый массив после замены минимального по модулю отрицательного элемента.
 */
void ReplaceTask1(const int* arr, int* arr2, const size_t size);

/**
 * @brief Проверяет есть ли в числе повторяющиеся цифры.
 * @param number Целое число, которое необходимо проверить на наличие повторяющихся цифр.
 * @return true Если в числе есть повторяющиеся цифры, иначе false.
 */
bool CountFigure(int number);

/**
 * @brief Подсчитывает количество элементов, которые не содержат повторяющиеся цифры.
 * @param arr Указатель на исходный массив.
 * @param size Количество элементов в массиве.
 * @return Количество элементов, которые не содержат повторяющиеся цифры.
 */
size_t CountElementsNotRepeat(const int* arr, const size_t size);


/**
 * @brief Удаляет элементы с повторяющимися цифрами из массива.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будут скопированы элементы после удаления.
 * @param size Размер исходного массива.
 * @return Новый массив после удаления элементов с повторяющимися цифрами.
 */
void RemoveElementsNotRepeat(const int* arr, int* arr2, const size_t size);

/**
 * @brief Преобразует массив по правилу: если номер четный, то Mi=i*Pi , если нечетный, то Mi=-Pi.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат преобразования.
 * @param size Размер исходного массива.
 * @return Новый массив после преобразования.
 */
void ChangeArray(const int* arr, int* arr2, const size_t size);

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
    size_t size = (size_t)InputArray();

    int* arr = IntArray(size);
    FillingArray(arr, size);

    printf("\nИсходный массив: ");
    PrintArray(arr, size);

    printf("Массив после замены минимального по модулю отрицательного элемента: ");
    int* arr2 = IntArray(size);
    ReplaceTask1(arr, arr2, size);
    PrintArray(arr2, size);

    free(arr2);

    size_t newsize = CountElementsNotRepeat(arr, size);
    printf("Массив после удаления элементов с повторяющимися цифрами: ");
    int* arr3 = IntArray(newsize);
    RemoveElementsNotRepeat(arr, arr3, size);
    PrintArray(arr3, newsize);

    free(arr3);

    printf("Массив M после преобразований: ");
    int* arr4 = IntArray(size);
    ChangeArray(arr, arr4, size);
    PrintArray(arr4, size);

    free(arr4);
    free(arr);

    return 0;
}

int Input(void)
{
    int input = 0;
    if (scanf("%d", &input) != 1)
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

void FullRandomArray(int* const arr, const size_t size)
{
    CheckArray(arr);
    puts("Введите минимальную границу случайных чисел: ");
    const int downBound = Input();
    puts("Введите максимальную границу случайных чисел: ");
    const int upBound = Input();

    if (downBound > upBound)
    {
        puts("Неправильно введена граница чисел!\a");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (upBound - downBound + 1) + downBound;
    }
}

void FillingArrayKeyboard(int* arr, const size_t size)
{
    CheckArray(arr);
    printf("\nВведите %zu целых чисел для заполнения массива: ", size);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = Input();
    }
}

void FillingArray(int* arr, const size_t size)
{
    CheckArray(arr);
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
        free(arr);
        exit(EXIT_FAILURE);
    }
}

void PrintArray(const int* arr, const size_t size)
{
    CheckArray(arr);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

size_t LastNegativElement(const int* arr, const size_t size)
{
    CheckArray(arr);
    for (size_t i = size - 1; i-->0)
    {
        if (arr[i] < 0)
        {
            return = i;
        }
    }
    return size;
}

void ReplaceTask1(const int* arr, int* arr2, const size_t size)
{
    CheckArray(arr);
    CheckArray(arr2);
    int result = LastNegativElement(arr, size);
    for (size_t i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    if (result < size)
    {
        arr2[LastNegativElement(arr, size)] = abs(arr[0]);
    }
}

bool CountFigure(int number)
{
    int count[10] = { 0 };

    while (abs(number) > 0)
    {
        int last = number % 10;
        count[last]++;

        if (count[last] > 1)
        {
            return true;
        }

        number /= 10;
    }

    return false;
}

size_t CountElementsNotRepeat(const int* arr, const size_t size)
{
    CheckArray(arr);
    size_t newSize = 0;
    for (size_t i = 0; i < size; i++) {
        if (!CountFigure(arr[i]))
        {
            newSize++;
        }
    }

    return newSize;
}

void RemoveElementsNotRepeat(const int* arr, int* arr2, const size_t size)
{
    CheckArray(arr);
    CheckArray(arr2);
    size_t index = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (!CountFigure(arr[i]))
        {
            arr2[index] = arr[i];
            index++;
        }
    }
}

void ChangeArray(const int* arr, int* arr2, const size_t size)
{
    CheckArray(arr);
    CheckArray(arr2);
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr2[i] = i * arr[i];
        }
        else
        {
            arr2[i] = -arr[i];
        }
    }
}
