#include "spot.h"

void spt_swap(int *a, int *b) {
    if (!a || !b) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int spt_rand(int min, int max) {
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    return rand() % (max - min + 1) + min;
}

int spt_initrand() {
    srand(time(NULL));
}