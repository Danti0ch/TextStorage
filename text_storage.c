/**
 * \file
 * \brief  файл содержит определения функций, объявленных в text_storage.h
 *
 */

#include "text_storage.h"

enum func_codes storage_destructor(text_storage *storage){

    assert(storage != NULL);
    
    free(storage->p_lines);
    free(storage->buffer);
}

enum func_codes storage_constructor(text_storage *storage){
    assert(storage != NULL);

    assert(storage->len_buf > 0);
    assert(storage->num_lines > 0);
    
    storage_destructor(storage);

    storage->buffer = (char*)calloc(storage->len_buf, sizeof(char));
    storage->p_lines = (char**)calloc(storage->num_lines, sizeof(char*));

    if((storage->buffer == NULL) || (storage->p_lines == NULL)){
        return MEM_ALLOC_ERROR;
    }

    return OK;
}

enum func_codes get_text_storage(const char *file_name, text_storage *storage){

    assert(storage != NULL);
    
    assert(file_name != NULL);

    //обработка ошибок
    enum func_codes getting_len_result = get_file_len(file_name, &(storage->num_lines), &(storage->len_buf));

    if(getting_len_result != OK){
        return getting_len_result;
    }

    if(storage->len_buf == 0){
        return EMPTY_FILE;
    }

    enum func_codes mem_for_storage_result = storage_constructor(storage);

    if(mem_for_storage_result != OK){
        return mem_for_storage_result;
    }

    if((storage->buffer == NULL) || (storage->p_lines == NULL)){
        return MEM_ALLOC_ERROR;
    }

    FILE *input_file = fopen(file_name, "r");

    if(input_file == NULL){
        return ERROR_FILE_READING;
    }

    int reading_status = fread(storage->buffer, sizeof storage->buffer[0], storage->len_buf, input_file);
    assert(reading_status >= 0);

    fclose(input_file);

    int is_new_line = 1;
    size_t num_line = 0;

    for(int ind_buf = 0; ind_buf < storage->len_buf; ind_buf++){
        if(is_new_line){
            storage->p_lines[num_line] = &storage->buffer[ind_buf];
            is_new_line = 0;
        }
        if(storage->buffer[ind_buf] == '\n'){
            storage->buffer[ind_buf] = '\0';
            is_new_line = 1;
            num_line++;
        }
    }

    if(is_new_line){
            storage->p_lines[num_line] = &storage->buffer[storage->len_buf-1];
            is_new_line = 0;
        }

    return OK;
}


enum func_codes write_storage(FILE *output_file, text_storage *storage){

    assert(storage != NULL);
    assert(output_file != NULL);
    //проверка, на то, что все строки lines не указывают на ноль?

    for(int i = 0; i < storage->num_lines; i++){
        fputs(storage->p_lines[i], output_file);
        fputc('\n', output_file);
    }
    return OK;
}

enum func_codes write_buffer_of_storage(FILE *output_file, text_storage *storage){

    assert(storage != NULL);
    assert(output_file != NULL);

    char *n_symb = storage->buffer;

    for(int n_line = 0; n_line < storage->num_lines; n_line++, n_symb++){
        for(; *n_symb != '\0'; n_symb++){
            fputc(*n_symb, output_file);
        }
        fputc('\n', output_file);
    }

    return OK;
}