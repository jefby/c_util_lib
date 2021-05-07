//
// Created by dev on 2021/5/7.
//

#ifndef UNTITLED_C_UTIL_H
#define UNTITLED_C_UTIL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define INPUT 
#define OUTPUT 
#define INOUT

// Get current date time
// return current format time, such as 
// 2021-05-07 14:10:42
// Note: You should free the malloced memory when used
char* getFormatTime();


// Split the source with delimiter
// array_len will return the splitted array length.
// @param source, source string
// @param delimiter, split delimiter
// @param array_len splitted array length
// return splitted array 
char** split(char *source, const char* delimiter, int *array_len);
// split thread_safe version
char** split_r(char *source, const char* delimiter, int *array_len);


bool startswith(char *source, char* find);
#endif//UNTITLED_C_UTIL_H
