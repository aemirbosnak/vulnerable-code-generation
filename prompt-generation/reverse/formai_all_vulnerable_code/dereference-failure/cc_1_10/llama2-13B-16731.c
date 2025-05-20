//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10
#define MAX_STRLEN 100

void rec_print(char *str, int depth);
void rec_concat(char *str1, char *str2, int depth);

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char result[MAX_STRLEN];

    rec_concat(str1, str2, 0);
    printf("%s\n", result);

    return 0;
}

void rec_print(char *str, int depth) {
    if (depth == 0) {
        printf("%s\n", str);
        return;
    }

    for (int i = 0; i < depth; i++) {
        putchar('-');
    }

    rec_print(str + 1, depth - 1);

    for (int i = 0; i < depth; i++) {
        putchar('-');
    }
}

void rec_concat(char *str1, char *str2, int depth) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1 + len2;

    if (len > MAX_STRLEN) {
        rec_concat(str1, str2, depth + 1);
    } else {
        char *new_str = malloc(len + 1);
        strcpy(new_str, str1);
        strcat(new_str, str2);
        rec_print(new_str, depth);
        free(new_str);
    }
}