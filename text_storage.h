/**
 * \file
 * \brief файл содержит структуру для работы с группой строк, ее методы
 */

#ifndef ONEGIN_H
#define ONEGIN_H

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "support.h"

struct text_storage{
    char **p_lines = NULL;
    char *buffer = NULL;

    size_t len_buf = 0;
    size_t num_lines = 0;
};


/**
 * считывает 
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

enum func_codes write_storage(FILE *output_file, text_storage *storage);

int qsort2(void *arr[], const int left, const int right, const size_t elem_size, int (*comparator)(void *, void *));

enum func_codes storage_destructor(text_storage *storage);

enum func_codes storage_constructor(text_storage *storage);

enum func_codes write_buffer_of_storage(FILE *output_file, text_storage *storage);

#endif