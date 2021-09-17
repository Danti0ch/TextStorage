#include <stdio.h>
#include "text_storage.h"
#include "qsort2.h"

int main(int argc, char const * const argv[]){

	int is_alnum_sorting = 0;
	
	if((argc == 2) && strcmp("-help", argv[1]) == 0){
		show_help();
		return 0;
	}

	for(int i = 1; i < argc; i++){
		if(strcmp("-alnum", argv[i]) == 0){
			is_alnum_sorting = 1;
		}
		else{
			printf("wrong flag\n");
			return 0;
		}
	}

	text_storage storage = {};

	get_text_storage("roman.txt", &storage);

	printf("straigh sorting\n");

	if(is_alnum_sorting){
		qsort2((void*)storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], (int (*)(const void*, const void*))string_cmp_alnum);
	}
	else{
		qsort2((void*)storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], (int (*)(const void*, const void*))string_cmp_straight);
	}
	printf("completed\n\n");
	FILE *output_file = fopen("output.txt", "w");

	fputs("\nSORTED TEXT\n\n", output_file);
	
	write_storage(output_file, &storage);

	printf("reverse sorting\n");

	if(is_alnum_sorting){
		qsort2((void*)storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], (int (*)(const void*, const void*))string_cmp_alnumReverse);
	}
	else{
		qsort2((void*)storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], (int (*)(const void*, const void*))string_cmp_reverse);
	}

	printf("completed\n\n");

	fputs("\nREVERSE_SORTED TEXT\n\n", output_file);
    
	write_storage(output_file, &storage);
	
	fputs("\nORIGINAL TEXT\n\n", output_file);

	write_buffer_of_storage(output_file, &storage);
	
	clear_mem_storage(&storage);
	
	fclose(output_file);

	return 0;
}