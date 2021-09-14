/**
 * \file
 * \brief
 * 
 * файл содержит обьявления функций, которые ответственны за
 * 1. сортировку строк в лекискографическом порядке
 * 2. считывание строк из файла
 * 3. вывод символьного массива на экран
 */

#ifndef ONEGIN_H
#define ONEGIN_H

#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int MAX_ARR_LINES_LEN = 30000;
const int MAX_LINE_LEN = 10000;

enum func_codes{
    READEN_LINES_OVERFLOW = -1,
    MEM_ALLOC_ERROR       = -2,
    EMPTY_FILE            = -3,
    ERROR_FILE_READING    = -4,
    OK                    =  1
};

struct text_storage{
    char **p_lines = NULL;
    char *buffer = NULL;

    size_t len_buf = 0;
    size_t num_lines = 0;
};


/**
 * считывает строки из файла fp в строковый массив lines
 * 
 * \param fp указатель на файл, в котором содержатся нужные строки для считывания
 * \param lines символьный массив, в который будет производится запись из файла
 * \param max_size максимальное количество строк, которое можно считать из файла
 * \param n_readen_lines переменная для записи количества считанных строк
 * 
 * \return 1, если функций выполнена успешно или код ошибки из readlines_return_codes
 */
enum func_codes get_text_storage(const char *file_name, text_storage *storage);
/**
 * записывает все строки из lines в файл output_file
 *  
 * \param output_file указатель на файл, в котором содержатся нужные строки для считывания
 * \param lines символьный массив, в который будет производится запись из файла
 * \param n_lines количество строк в массиве lines
 * 
 * \return OK, если вывод прошел успешно и ???
 */
int print_lines(FILE *output_file, char *lines[], int n_lines);

enum func_codes get_file_len(const char *file_name, size_t *n_lines, size_t *len);

enum func_codes qsort2(void *arr[], size_t left, size_t right, int (*comparator)(const void *, const void *));

//меняет местами два равных по размеру элемента
void swap(void *p_elem1, void *p_elem2, size_t size_elem);
#endif