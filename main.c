#include "arrays.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define N 10
#define M 100
#define SIZE 100

int main() {
    puts("Лабораторные работы 11, 14, 16: Работа с массивами ===\n");

    int size;
    puts("Укажите размер массива");
    scanf("%d", &size);
    task11();

    task14(size); // для всех заданий лаб. 14

    task16(size);// для всех заданий лаб. 16

    return 0;
}

int task11() {
    setlocale(LC_CTYPE, "RUS");

    float temp;
    float A[N];
    float sum = 0;
    float sr;

    // Задание 1. Заполнение массива
    for (int i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    printf("|---------------------------------------------|\n");
    printf("| индекс | исходное значение | новое значение |\n");

    //заменить нулевые значения элементов массива их порядковым номером
    for (int i = 0; i < N; i++) {
        float new;
        if (A[i] == 0) {
            new = i + 1;
        }
        else {
            new = A[i];
        }

        printf("| %6d | %16f | %15f |\n", i + 1, A[i], new);
    }

    printf("|---------------------------------------------|\n");

    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    sr = sum / N;

    printf("Среднее арифметическое равно %2f\n", sr);

    printf("Кол-во элементов меньше среднего: %d \n", func(A, sr)); //домашнее задвние
    return 0;

    // Задание 2. Массив, заполненный значениями по фенкции и интервалу из лаб. 8
    float A[M];
    float start = 2;
    float end = 4.1;
    float step = (end - start) / (M - 1);

    float possum = 0.0;
    float negsum = 0.0;
    int poscount = 0;
    int negcount = 0;
    float sr = 0.0;

    for (int i = 0; i < M; i++) {
        float x = start + i * step;
        A[i] = calc(x);                 // функция из лаб. 8
        printf("%f\n", A[i]);

        if (A[i] > 0) {
            possum += A[i];
            poscount += 1;
        }
        else {
            negsum += A[i];
            negcount += 1;
        }
    }
    sr = possum / M;

    printf("A[M], сумма положительных - %f, сумма отрицательных - %f,\n", possum, negsum);
    printf("кол-во положительных - %d, кол - во отрицательных - %d, среднее - %f", poscount, negcount, sr);
    return 0;
}

int task14(int size) {
    setlocale(LC_CTYPE, "RUS");

    double* ptr_array;
    int begin, end;
    double element;
    int k;

    // Задание 1. Заполнение массива

    ptr_array = (double*)malloc(size * sizeof(double));

    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    printf("Введите индекс начального элемента: ");
    scanf("%d", &begin);
    printf("Введите индекс конечного элемента: ");
    scanf("%d", &end);
    printf("Введите элемент а: ");
    scanf("%lf", &element);
    printf("Введите позицию K для поиска минимума: ");
    scanf("%d", &k);

    full_elements(ptr_array, size);
    put_elements(ptr_array, size);
    calc_elements(ptr_array, size);
    
    // Задание 2. Обратотка массива

    printf("Сумма элементов с %d по %d: %.4f\n", begin, end, sum_elements(ptr_array, begin, end));

    int index = find_element(ptr_array, size, element);
    printf("Индекс элемента %.4f: %d\n", element, index);

    double min = find_min(ptr_array, size, k);
    printf("Минимальное значение после позиции %d: %.4f\n", k, min);

    free(ptr_array);
    return 0;

}

int task16(int size) {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    double* ptr_array;

    // Задание 1. Заполнение и обработка массива
    printf("=== ЗАДАНИЕ 1 ===\n");

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    full_elements(ptr_array, size);
    put_elements(ptr_array, size);

    calc_elements(ptr_array, size);

    free(ptr_array);

    // Задание 2. Заполнение рандомными значениями от -1 до 1
    printf("\n=== ЗАДАНИЕ 2 ===\n");

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    full_random(ptr_array, size);

    put_elements(ptr_array, size);

    printf("2.1 Удаление двух максимальных элементов:\n");
    int current_size = size;
    delete_two_max(ptr_array, &current_size);
    put_elements(ptr_array, current_size);

    printf("2.2 Вставка -999 перед максимальным элементом:\n");
    insert_before_max(ptr_array, &current_size);
    put_elements(ptr_array, current_size);

    free(ptr_array);

    return 0;
}