/**
 * \file
 * 
 * \brief файл содержит определения функций, обьявленных в qsort2.h
 */

#include "qsort2.h"

enum func_codes qsort2(void *arr[], const int left, const int right, const size_t elem_size, int (*comparator)(void *, void *)){

   assert(arr != NULL);
   assert(comparator != NULL);

   assert(elem_size>0);

   if(right <= left){
      return OK;
   }
   assert((left >= 0) && (right >= 0));

   assert(arr[left] != NULL);
   assert(arr[right] != NULL);

   int pivot = (left + right)/2;
   swap(&arr[left], &arr[pivot], elem_size);
         
   int right_lower_pivot = left;
   for(int ind = left + 1; ind <= right; ind++){
      // если нашелся arr[ind] < arr[left]
      if((*comparator)(arr[left], arr[ind]) > 0){
         swap(&arr[++right_lower_pivot], &arr[ind], elem_size);
      }
   }

   swap(&arr[right_lower_pivot], &arr[left], elem_size);

   qsort2(arr, left, right_lower_pivot, elem_size, comparator);
   qsort2(arr, right_lower_pivot + 1, right, elem_size, comparator);

   return OK;
}
