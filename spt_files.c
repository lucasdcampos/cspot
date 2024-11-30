#include "spot.h"

int spt_file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

size_t spt_file_size(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return 0;

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fclose(file);

    return size+1;
}

int spt_read_file(const char *filename, char *buffer, size_t buffer_size) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;

    size_t read_size = fread(buffer, 1, buffer_size - 1, file);
    buffer[read_size] = '\0';

    fclose(file);
    return (int)read_size;
}

int spt_write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) return -1;

    int result = fputs(content, file);
    fclose(file);

    return (result != EOF) ? 0 : -1;
}