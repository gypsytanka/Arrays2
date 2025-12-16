#ifndef ARRAYS_H
#define ARRAYS_H


double calc(double x);  // функция для получения значений как в работе 8

/**
 * Заполнение массива значениями
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Обработка элементов массива согласно индивидуальному варианту
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на обработанный массив
 */
double* calc_elements(double* ptr_array, int n);

/**
 * Вычисление суммы элементов массива в диапазоне [begin, end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return сумма элементов
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Поиск элемента в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param element искомый элемент
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Определение минимального значения среди элементов, находящихся после заданной позиции K
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param k заданная позиция
 * @return значение минимального элемента после K
 */
double find_min(double* ptr_array, int n, int k);

/**
 * Удаление элемента
 * @param ptr_array указатель на массив
 * @param size число элементов
 * @param k индекс удаляемого элемента
 * @return кол-во элементов без удаленного
 */
int delete_k(double* ptr_arr, int size, int k);

/**
 * Определение максимального значеня
 * @param ptr_array указатель на массив
 * @param size число элементов
 * @return значение максимального элемента
 */
int find_max_index(double* ptr_arr, int size);

/**
 * Вставкф значения в массив перед указанным индексом
 * @param ptr_array указатель на массив
 * @param size число элементов
 * @param index позиция, перед которой будет вставлено новое значение
 * @param value значение для вставки
 * @return новый размер массива
 */
int insert_before(double* ptr_arr, int size, int index, double value);

/**
 * Удаление двух максимальных элементов
 * @param ptr_array указатель на массив
 * @param size указатель на размер массива
 */
void delete_two_max(double* ptr_arr, int* size);

/**
 * Вставка -999 перед максимальным элементом
 * @param ptr_array указатель на массив
 * @param size указатель на размер массива
 */
void insert_before_max(double* ptr_arr, int* size);

#endif
