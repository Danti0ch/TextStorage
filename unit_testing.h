/**
 * \file
 * \brief
 * 
 * файл содержит объявления функций, предназначенных для тестирования функий onegin.h
 */

#ifndef UNIT_TESTING
#define UNIT_TESTING

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "onegin.h"

enum TestCodes{
    PASSED = 1,
    FAILED = 0
};

const int test_name_len = 40;

void Testing();

enum TestCodes Testing_readlines(char *test_path);

inline int arr_char_len(size_t size, int line_len);

#endif

