//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 1024

void reverse_string(char *str) {
    char tmp;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void concat_strings(char *dest, const char *src1, const char *src2) {
    int len1 = strlen(src1);
    int len2 = strlen(src2);
    int len = len1 + len2;

    strncpy(dest, src1, len);
    strncat(dest, src2, len - len1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s string1 string2\n", argv[0]);
        exit(1);
    }

    char str1[MAX_LENGTH] = {0};
    char str2[MAX_LENGTH] = {0};
    char result[MAX_LENGTH] = {0};

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    reverse_string(str1);
    reverse_string(str2);

    printf("Reversed String 1: %s\n", str1);
    printf("Reversed String 2: %s\n", str2);

    concat_strings(result, str1, str2);

    printf("Concatenated Reversed Strings: %s\n", result);

    return 0;
}