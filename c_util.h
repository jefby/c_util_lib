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
#include <math.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

extern pthread_mutex_t g_lock_print;

//#define PRINT_INFO(fmt, arg ...) do { pthread_mutex_lock(&g_lock_print); printf("[%s:%d] : " fmt, __FILE__, __LINE__, ## arg); fflush(stdout); pthread_mutex_unlock(&g_lock_print); } while(0)
#define PRINT_INFO(fmt, arg ...) do { printf("[%s:%d] : " fmt, __FILE__, __LINE__, ## arg);} while(0)

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
// split thread_safe version
char** split(char *source, const char* delimiter, int *array_len);


bool contains(const char *source, char *find);

int myusleep(useconds_t us);

bool startswith(char *source, char* find);
#endif//UNTITLED_C_UTIL_H
