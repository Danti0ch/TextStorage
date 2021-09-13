/**
 * \file
 * \brief реализация функций unit_testing.h
 */
#include "unit_testing.h"

void Testing(){

	char group1_names[][test_name_len] = {
						"unit_tests/unit_test11.txt",
						"unit_tests/unit_test12.txt",
						"unit_tests/unit_test13.txt",
						"unit_tests/unit_test14.txt",
						"unit_tests/unit_test15.txt"};
	
	int n_passed = 0;
	int n_tests = 0;

	n_tests = arr_char_len(sizeof group1_names, test_name_len);

	printf("Testing readlines\n");

	for(int n_test = 0; n_test < n_tests; n_test++){
		if(Testing_readlines(group1_names[n_test]) == PASSED){
			printf("Test %d passed\n", n_test + 1);
			n_passed++;
		}
		else{
			printf("\t|Test %d failed\n", n_test + 1);
		}
	}

	printf("\n%d / %d tests passed\n\n", n_passed, n_tests);
	n_passed = 0;


}

enum TestCodes Testing_readlines(char test_path[]){

	FILE *test_file = fopen(test_path, "r");

	char *lines[MAX_ARR_LINES_LEN] = {};
	int n_readen_lines = 0;
	readlines(test_file, lines, MAX_LINE_LEN, &n_readen_lines);

	char new_line[] = "";

	int index_line = 0;
	for(; fgets(new_line, MAX_LINE_LEN, test_file) != NULL; index_line++){
		if(index_line > n_readen_lines || (!strcmp(new_line, lines[index_line]))){
			return FAILED;
		}
	}

	fclose(test_file);

	if(index_line != n_readen_lines){
		return FAILED;
	}

	return PASSED;
}

inline int arr_char_len(size_t size, int line_len){

	assert(isfinite(size));
	assert(size >= 0);

	assert(isfinite(line_len));
	assert(line_len >= 0);

	return size / (line_len * sizeof(char));
}