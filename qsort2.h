/**
 * \file
 * 
 * \brief файл содержит обьявления функции сортировки произвольного массива
 */
#ifndef QSORT2_H
#define QSORT2_H

#include <stdio.h>
#include "support.h"
#include <assert.h>

/**
 * функция сортирует массив arr по компаратору comparator
 * 
 * \param arr указатель на исходный массив
 * \param left, right индексы левого и правого края подмассива, который нужно отсортировать
 * \param elem_size размер элемента массива
 * \param comparator компаратор
 * 
 * \return код ошибки
 */
enum func_codes qsort2(void *arr[], const int left, const int right, const size_t elem_size, int (*comparator)(void *, void *));
#endif