#include "spot.h"

void *spt_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void spt_free(void **ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL; // Prevent dangling pointers
    }
}