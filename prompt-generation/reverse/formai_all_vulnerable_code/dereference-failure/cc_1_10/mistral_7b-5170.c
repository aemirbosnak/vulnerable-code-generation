//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1024
#define MIN_STRING_SIZE 5

void str_reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *str_concat(char *dest, char *src1, char *src2) {
    int len1 = strlen(src1);
    int len2 = strlen(src2);
    int total_len = len1 + len2 + 1;

    if (dest == NULL) {
        dest = (char *) malloc(total_len * sizeof(char));
    }

    strncpy(dest, src1, len1);
    strncat(dest, src2, len2 + 1);

    return dest;
}

int main() {
    char str1[MAX_STRING_SIZE] = "Hello, World!";
    char str2[MAX_STRING_SIZE] = "Linus Torvalds is a genius.";
    char *str3 = NULL;
    char *str4 = NULL;

    printf("Original strings:\n");
    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);

    printf("\nReverse Str1:\n");
    str_reverse(str1, 0, strlen(str1) - 1);
    printf("Str1: %s\n", str1);

    printf("\nConcatenate Str1 and Str2:\n");
    str3 = (char *) malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    str4 = str_concat(str3, str1, str2);
    printf("Str3: %s\n", str3);
    printf("Str4: %s\n", str4);

    free(str3);

    printf("\nSwap Str1 and Str2:\n");
    char temp[MAX_STRING_SIZE];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);

    return 0;
}