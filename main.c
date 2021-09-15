#include <stdio.h>
#include "text_storage.h"
#include <string.h>

int main(int argc, char const * const argv[]){

	int is_only_alnum_sorting = 0;

	for(int i = 1; i < argc; i++){
		if(strcmp("-help", argv[i]) == 0){
			show_help();
			return 0;
		}
		else if(strcmp("-alnum", argv[i]) == 0){
			is_only_alnum_sorting = 1;
		}
	}

	text_storage storage;
	
	get_text_storage("test.txt", &storage);
	
	qsort2((void**)storage.p_lines, 0, storage.num_lines-1, sizeof storage.p_lines[0], (int (*)(void*, void*))strcmp);
	
	FILE *output_file = fopen("output.txt", "w");

	fputs("\nSORTED TEXT\n\n", output_file);
    
	write_storage(output_file, &storage);

	qsort2((void**)storage.p_lines, 0, storage.num_lines-1, sizeof storage.p_lines[0], (int (*)(void*, void*))strcmp_reverse);

	fputs("\nREVERSE_SORTED TEXT\n\n", output_file);
    
	write_storage(output_file, &storage);

	fputs("\nORIGINAL TEXT\n\n", output_file);
	write_buffer_of_storage(output_file, &storage);
	
	return 0;
}