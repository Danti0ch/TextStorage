#include <stdio.h>
#include "text_storage.h"
#include "qsort2.h"
#include <time.h>

// GITHUB PAGES

int main(int argc, char const * const argv[]){

	#ifdef EX_TIME
	clock_t begin = clock();
	#endif

	char file_name[MAX_INPUT_FILE_NAME_LEN] = "roman.txt";

	int is_alnum_sorting = 0;

	get_console_parms(argc, argv, file_name, &is_alnum_sorting);

	text_storage storage = {};

	get_text_storage(file_name, &storage);

	FILE *output_file = fopen("output.txt", "w");

	printf("straight sorting\n");

	#ifdef STAND_QSORT
	if(is_alnum_sorting){
		qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnum);
	}
	else{
		qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_straight);
	}
	#else
	if(is_alnum_sorting){
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnum);
	}
	else{
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_straight);
	}
	#endif

	printf("completed\n\n");

	fputs("\nSORTED TEXT\n\n", output_file);
	
	write_storage(output_file, &storage);

	printf("reverse sorting\n");

	#ifdef STAND_QSORT
	if(is_alnum_sorting){
		qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnumReverse);
	}
	else{
		qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnumReverse);
	}
	#else
	if(is_alnum_sorting){
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_reverse);
	}
	else{
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_reverse);
	}
	#endif

	printf("completed\n\n");

	fputs("\nREVERSE_SORTED TEXT\n\n", output_file);
    
	write_storage(output_file, &storage);
	
	fputs("\nORIGINAL TEXT\n\n", output_file);

	write_buffer_of_storage(output_file, &storage);
	
	clear_mem_storage(&storage);
	
	fclose(output_file);

	#ifdef EX_TIME
	clock_t end = clock();
	printf("Execution time: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
	#endif

	return 0;
}