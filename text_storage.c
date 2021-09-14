/**
 * \file
 * \brief
 * 
 * файл содержит определения функций, объявленных в onegin.h
 *
 */

#include "text_storage.h"

enum func_codes get_text_storage(const char *file_name, text_storage *storage){

    assert(storage != NULL);
    
    assert(file_name != NULL);

    //обработка ошибок
    get_file_len(file_name, &(storage->num_lines), &(storage->len_buf));

    FILE *input_file = fopen(file_name, "r");

    if(input_file == NULL){
        return ERROR_FILE_READING;
    }

    if(storage->len_buf == 0){
        return EMPTY_FILE;
    }

    storage->buffer = (char*)calloc(storage->len_buf, sizeof(char));
    storage->p_lines = (char**)calloc(storage->num_lines, sizeof(char*));

    if((storage->buffer == NULL) || (storage->p_lines == NULL)){
        return MEM_ALLOC_ERROR;
    }

    int reading_status = fread(storage->buffer, sizeof storage->buffer[0], storage->len_buf, input_file);

    assert(reading_status >= 0);

    for(int ind_buf = 0; ind_buf < storage->len_buf; ind_buf++){
        if(storage->buffer[ind_buf] == '\n'){
            storage->buffer[ind_buf] = '\0';
        }
    }
    fclose(input_file);
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


enum func_codes qsort2(char *arr[], const size_t left, const size_t right, int (*comparator)(const void *, const void *)){
    assert(arr != NULL);

    if(right <= left){

        return OK;
    }

    size_t pivot = left;

    size_t l_limit = left;
    size_t r_limit = right;

    while(l_limit <= r_limit){
        for(; (l_limit <= r_limit) && (*comparator)(arr[pivot], arr[l_limit]) >= 0; l_limit++){
            ;
        }

        for(; (l_limit <= r_limit) && (*comparator)(arr[r_limit], arr[pivot]) >= 0; r_limit--){
            ;
        }
        if(l_limit <= r_limit){
            swap2(arr[l_limit], arr[r_limit], sizeof arr[l_limit]);
        }
    }

    swap2(arr[pivot], arr[r_limit], sizeof arr[l_limit]);

    pivot = r_limit;

    if(pivot > left + 1){
        qsort2(arr, left, pivot-1, comparator);
    }
    printf("WELL");

    if(right > pivot+1){
        qsort2(arr, pivot+1, right, comparator);
    }
    printf("\n\t\tCOOL\n");
    return OK;
}
/**
 * возвращает количество символов и количество строк без учета символов переноса каретки(
 * если они стоят перед '\n')
 */

enum func_codes get_file_len(const char *file_name, size_t *n_lines, size_t *len){

    FILE *text_file = fopen(file_name, "r");

    assert(text_file != NULL);
    assert(n_lines != NULL);
    assert(len != NULL);
    assert(len != n_lines);
    
    (*len) = 0;

    int c = 0;
    int c_prev = 0;
    *n_lines = 0;

    for(; (c = fgetc(text_file)) != EOF; (*len)++, c_prev = c){
        if(c == '\n'){
            (*n_lines)++;
        }
    }

    // если на последней строчке нет символа переноса
    if(c_prev > 0){
        (*n_lines)++;
    }
    fclose(text_file);

    return OK;
}


//меняет местами два равных по размеру элемента
void swap(void *p_elem1, void *p_elem2, size_t size_elem){

   assert(p_elem1 != NULL);
   assert(p_elem2 != NULL);

   assert(p_elem1 != p_elem2);

   long long int big_storage = 0;
   
   long long int *bstepper_elem1 = (long long int *)p_elem1;
   long long int *bstepper_elem2 = (long long int *)p_elem2;

   for(; ((char*)(bstepper_elem1 + 1) - (char *)p_elem1 <= size_elem) && ((char*)(bstepper_elem2 + 1) - (char *)p_elem2 <= size_elem); bstepper_elem1++, bstepper_elem2++){
      big_storage = *bstepper_elem2;
      *bstepper_elem2 = *bstepper_elem1;
      *bstepper_elem1 = big_storage;
   }

   //разные размеры переменных
   assert(!(((char*)(bstepper_elem1 + 1) - (char *)p_elem1 <= size_elem) && ((char*)(bstepper_elem2 + 1) - (char *)p_elem2 <= size_elem)));

   char small_temp = 0;

   char *sstepper_elem1 = (char *)bstepper_elem1;
   char *sstepper_elem2 = (char *)bstepper_elem2;
   
   for(; (sstepper_elem1 - (char *)p_elem1 < size_elem) && (sstepper_elem2 - (char *)p_elem2 < size_elem); sstepper_elem1++, sstepper_elem2++){
      small_temp = *sstepper_elem2;
      *sstepper_elem2 = *sstepper_elem1;
      *sstepper_elem1 = small_temp;
   }

   //разные размеры переменных
   assert(!((sstepper_elem1 - (char *)p_elem1 < size_elem) && (sstepper_elem2 - (char *)p_elem2 < size_elem)));
}
