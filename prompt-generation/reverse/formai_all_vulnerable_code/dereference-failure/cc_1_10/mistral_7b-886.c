//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void strcpy_inv(char *dest, char *src) {
    char *temp = dest;
    while (*dest++ = *src++) {}
    dest--;
    while (dest > temp) {
        if (*dest == '\0') break;
        if (*--dest == *src) *dest = '\0';
    }
}

int strcmp_inv(char *str1, char *str2) {
    char *end = str1;
    while (*--end != '\0') {
        if (*end != *++str2) return 1;
    }
    return 0;
}

void find_and_replace(char *str, char *find, char *replace) {
    int len_find = 0;
    int len_replace = 0;
    int i = 0;

    while (find[len_find] != '\0') len_find++;
    while (replace[len_replace] != '\0') len_replace++;

    char temp[MAX_SIZE];
    strcpy_inv(temp, str);

    while (i <= (len_find + len_replace) * 2) {
        if (strcmp_inv(&temp[i], find) == 0) {
            int j = 0;
            while (replace[j] != '\0') temp[i + len_find + j++] = replace[j];
            i += len_find + len_replace;
        } else {
            i++;
        }
    }

    strcpy_inv(str, &temp[0]);
}

int main() {
    char input[MAX_SIZE];
    char find[MAX_SIZE] = "apple";
    char replace[MAX_SIZE] = "orange";

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("String before replacement: %s\n", input);

    find_and_replace(input, find, replace);

    printf("String after replacement: %s\n", input);

    return 0;
}