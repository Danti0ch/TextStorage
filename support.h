/**
 * \file
 * 
 * \brief файл содержит обьявления вспомогательных функций и констант, необходимых в других файлах
 * 
 */
#ifndef SUPP_H
#define SUPP_H

#include <stdio.h>
#include <assert.h>

/// коды ошибок для функций
enum func_codes{ 
    MEM_ALLOC_ERROR       = -100,  ///< ошибка обращения к памяти
    EMPTY_FILE            = -99,   ///< ошибка работы с пустым файлом
    IDENTICAL_POINTERS    = -98,   ///< идентичные указатели
    ERROR_FILE_READING    = -97,   ///< ошибка чтения файла
    OK                    =  1     ///< успешное завершение
};

/// максимальная длина строки для чтения readme.txt
const int MAX_README_LINE_LEN = 1000;

/// выводит содержимое файла "readme.txt" в консоль
void show_help(void);

/**
 *  меняет значения обьектов на которые указывают p_elem1, p_elem2.
 * Обьекты должны быть одного размера.
 * 
 * \param p_elem1, p_elem2 указатели на обьекты, которые надо поменять
 * \param size_elem размер обьекта p_elem1(p_elem2)
 * 
 * \return код ошибки
 */
enum func_codes swap(void *p_elem1, void *p_elem2, size_t size_elem);

/**
 * считывает данные из файла, записывает количество строк и символов
 * 
 * \param file_name имя файла, размер которого нужно узнать
 * \param n_lines количество строк в файле
 * \param len количество символов в файле
 * 
 * \return код ошибки
 */
enum func_codes get_file_len(const char *file_name, size_t *n_lines, size_t *len);

/**
 * сравнивает строки в обратном лексикографическом порядке
 * 
 * \param string1, string2 исходные строки
 * 
 * \return 1 если string1 > string2
 * \return -1 если string1 < string2
 * \return 0 если string1 == string2
 */
int strcmp_reverse(const char * string1, const char * string2);
#endif