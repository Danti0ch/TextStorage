#include <stdio.h>
#include "text_storage.h"
#include "unit_testing.h"

int main(){

	text_storage storage;

	size_t q = 100;

	printf("%d\n", get_text_storage("test.txt", &storage));

	printf("%d|%d|", storage.num_lines, storage.len_buf);
	char *arr2[] = {"bad", "abc"};

	qsort2((void **)arr2, 0, 1, (int (*)(const void *, const void *))strcmp);

	printf("%s\n%s", arr2[0], arr2[1]);
	return 0;
}