#include "spot.h"

char *spt_strrev(char *str) {
    if (!str) return NULL;
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

char *spt_strcats(char *str1, char *str2) {
    if (!str1 || !str2) return NULL; 

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *result = (char *)malloc(len1 + len2 + 2);

    if (!result) return NULL;

    strcpy(result, str1);

    result[len1] = ' ';

    strcpy(result + len1 + 1, str2);

    return result;
}

char *spt_trim(char *str) {
    if (!str) return NULL;
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';

    return str;
}

void spt_strtoupper(char *str) {
    if (!str) return;
    for (; *str; str++) {
        *str = toupper((unsigned char)*str);
    }
}

void spt_strtolower(char *str) {
    if (!str) return;
    for (; *str; str++) {
        *str = tolower((unsigned char)*str);
    }
}