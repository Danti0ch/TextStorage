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
 * \param arr указатель на начало массива
 * \param arr_len длина массива
 * \param elem_size размер элемента массива
 * \param comparator компаратор
 * 
 * \return код возвращаемого значения из func_codes
 */
enum func_codes qsort2(void *arr, const size_t arr_len, const size_t elem_size, int (*comparator)(const void *, const void *));
#endif