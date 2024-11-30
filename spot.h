#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

typedef struct spt_vec2
{
    float x;
    float y;
} spt_vec2;

typedef struct spt_vec3
{
    float x;
    float y;
    float z;
} spt_vec3;

typedef struct spt_vec4
{
    float x;
    float y;
    float z;
    float w;
} spt_vec4;

typedef struct spt_stack_node {
    int value;
    struct spt_stack_node *next;
} spt_stack_node;

typedef struct spt_stack {
    spt_stack_node *top;
} spt_stack;

// Memory management
void *spt_malloc(size_t size);
void spt_free(void **ptr);

void stack_init(spt_stack *stack);
void stack_push(spt_stack *stack, int value);
int stack_pop(spt_stack *stack);
int stack_top(spt_stack *stack);
int stack_is_empty(spt_stack *stack);
void stack_free(spt_stack *stack);


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

// Window management
typedef struct spt_window {
    spt_vec2 resolution;
    const char *title;
    void *window_handle;
} spt_window;

typedef enum spt_window_api {
    Default, 
    X11, 
    Win32
} spt_window_api;

int spt_open_window(spt_window *win, const spt_vec2 res, const char* title);
void spt_close_window(spt_window *win);
void spt_set_window_api(spt_window_api api);

#ifdef _WIN32
    
#else
    int sptx11_open_window(spt_window *win, const spt_vec2 res, const char* title);
    void sptx11_close_window(spt_window *win);
#endif