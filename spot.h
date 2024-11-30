#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

// Memory management
void *spt_malloc(size_t size);
void spt_free(void **ptr);

// String manipulation
char *spt_strcats(char *str1, char *str2);
char *spt_strrev(char *str);
char *spt_trim(char *str);
void spt_strtoupper(char *str);
void spt_strtolower(char *str);

// Utilities
void spt_swap(int *a, int *b);
int spt_initrand();
int spt_rand(int min, int max);
int spt_randf(float min, float max);

// File Management
int spt_file_exists(const char *filename);
size_t spt_file_size(const char *filename);
int spt_read_file(const char *filename, char *buffer, size_t buffer_size);
int spt_write_file(const char *filename, const char *content);

// Time management
void spt_sleep(int ms);
char *spt_curr_time();
double spt_time_diff(clock_t start, clock_t end);