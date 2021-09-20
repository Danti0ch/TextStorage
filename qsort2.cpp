/**
 * \file
 * 
 * \brief файл содержит определения функций, обьявленных в qsort2.h
 */

#include "qsort2.h"
#include "text_storage.h"

enum func_codes qsort2(void *arr, const size_t arr_len, const size_t elem_size, int (*comparator)(const void *, const void *)){

  if(arr_len <= 1){
      return OK;
   }

   assert(arr != NULL);

   assert(elem_size > 0);

   assert(comparator != NULL);

   char *p_left = (char*)arr;

   char *p_right = p_left + (arr_len - 1) * elem_size;
   
   swap(p_left, p_left + ((arr_len - 1) / 2) * elem_size, elem_size);

   char *left_subarr_limit = p_left;

   for(char *p_elem = p_left; p_elem <= p_right; p_elem += elem_size){
      // если нашелся arr[p_elem] < arr[left]
      if((*comparator)(p_left, p_elem) > 0){
         left_subarr_limit += elem_size;
         swap(left_subarr_limit, p_elem, elem_size);
      }
   }

   swap(left_subarr_limit, p_left, elem_size);

   size_t left_subarr_len = (left_subarr_limit - p_left + elem_size) / elem_size;

   qsort2(arr, left_subarr_len, elem_size, comparator);
   qsort2(left_subarr_limit + elem_size, arr_len - left_subarr_len, elem_size, comparator);

   return OK;
}
