/**
 * \file
 * \brief
 * 
 * файл содержит определения функций, объявленных в onegin.h
 *
 */

#include "onegin.h"

enum func_return_codes readlines(FILE *input_file, char *lines[], int n_lines, int *n_readen_lines){

    assert(input_file != NULL);
    assert(lines != NULL);
    assert(n_readen_lines != NULL);

    //проверка на то, что max_size - конечное число
    assert(isfinite(n_lines));
    
    //max_size не должен превышать допустимые пределы памяти
    assert(n_lines <= MAX_ARR_LINES_LEN);

    char buffer[MAX_LINE_LEN];
    char *line_to_write = NULL;
    (*n_readen_lines) = 0;
    int size_buffer = 0;

    for(; fgets(buffer, MAX_LINE_LEN, input_file) != NULL; (*n_readen_lines)++){
        size_buffer = strlen(buffer);

        if((*n_readen_lines) > n_lines){
            return READEN_LINES_OVERFLOW;
        }

        if((line_to_write = (char*)calloc(size_buffer, sizeof(char))) == NULL){
            return MEM_ALLOC_ERROR;
        }
        printf("%d\n", line_to_write);

        strcpy(line_to_write, buffer);
        line_to_write[size_buffer - 1] = '\0';

        lines[(*n_readen_lines)] = line_to_write;
    }

    if((*n_readen_lines) > 0){
        line_to_write[size_buffer - 1] = buffer[size_buffer - 1];
    }

    return OK;
}

int print_lines(FILE *output_file, char *lines[], int n_lines){

    assert(output_file != NULL);
    assert(lines != NULL);
    //проверка, на то, что все строки lines не указывают на ноль

    //проверка на то, что max_size - конечное число
    assert(isfinite(n_lines));

    //max_size не должен превышать допустимые пределы памяти
    //(выдавать ошибка динамически в зависимости от доступной памяти???)
    assert(n_lines <= MAX_ARR_LINES_LEN);

    for(int i = 0; i < n_lines; i++){
        //запись в файл
    }
}