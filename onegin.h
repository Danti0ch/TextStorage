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
const int MAX_LINE_LEN = 1000;

enum func_return_codes{
    READEN_LINES_OVERFLOW = -1,
    MEM_ALLOC_ERROR       = -2,
    OK                    =  1
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
enum func_return_codes readlines(FILE *input_file, char *lines[], int n_lines, int *n_readen_lines);

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
#endif