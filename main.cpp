#include <stdio.h>
#include "text_storage.h"
#include "qsort2.h"
#include <time.h>

// GITHUB PAGES

int main(int argc, char const * const argv[]){

	#ifdef EX_TIME
	clock_t begin = clock();
	#endif

	int is_alnum_sorting = 0;
	int argc_current = 1;

	if((argc == 2) && strcmp("--help", argv[argc_current]) == 0){
		show_help();
		return 0;
	}

	char file_name[MAX_INPUT_FILE_NAME_LEN] = "roman.txt";

	if((argc > 1) && (argv[argc_current][0] != '-') && (strlen(argv[argc_current]) < MAX_INPUT_FILE_NAME_LEN)){
		strcpy(file_name, argv[argc_current]);
		argc_current++;
	}

	// checking the correction of file
	FILE *input_file = fopen(file_name, "r");
	if(input_file == NULL){
		printf("No file found\n");
		return 0;
	}
	fclose(input_file);

	for(; argc_current < argc; argc_current++){
		if(strcmp("--alnum", argv[argc_current]) == 0){
			is_alnum_sorting = 1;
		}
		else{
			printf("wrong flag\n");
			return 0;
		}
	}

	text_storage storage = {};

	get_text_storage(file_name, &storage);

	printf("straight sorting\n");

	if(is_alnum_sorting){
		#ifdef STAND_QSORT
		//qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnum);
		#else
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnum);
		#endif
	}
	else{
		#ifdef STAND_QSORT
		//qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_straight);
		#else
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_straight);
		#endif
	}

	printf("completed\n\n");

	FILE *output_file = fopen("output.txt", "w");

	fputs("\nSORTED TEXT\n\n", output_file);
	
	write_storage(output_file, &storage);

	printf("reverse sorting\n");

	if(is_alnum_sorting){
		#ifdef STAND_QSORT
		//qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnumReverse);
		#else
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_alnumReverse);
		#endif
	}
	else{
		#ifdef STAND_QSORT
		//qsort(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_reverse);
		#else
		qsort2(storage.p_lines, storage.num_lines, sizeof storage.p_lines[0], string_cmp_reverse);
		#endif
	}

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