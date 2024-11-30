#include "spot.h"

void spt_sleep(int ms) {
    #ifdef _WIN32
        Sleep(ms);
    #else
        #include <unistd.h>
        usleep(ms * 1000);
    #endif
}

char *spt_curr_time() {
    static char buffer[9]; // HH:MM:SS -> 8 chars + '\0'
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (t) {
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
    } else {
        snprintf(buffer, sizeof(buffer), "00:00:00");
    }

    return buffer;
}

double spt_time_diff(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}