//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

char *string_copy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *string_concat(char *dst, const char *src) {
    int i = 0;
    int len_dst = string_length(dst);
    while (src[i] != '\0') {
        dst[len_dst + i] = src[i];
        i++;
    }
    dst[len_dst + i] = '\0';
    return dst;
}

int string_length(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char str1[MAX_STR_LEN] = "Hello, ";
    char str2[MAX_STR_LEN] = "World!";

    // Copy str1 to a new string
    char *str1_copy = string_copy(malloc(MAX_STR_LEN), str1);

    // Concatenate str1 and str2
    char *str_concat = string_concat(str1_copy, str2);

    // Print the concatenated string
    printf("%s\n", str_concat);

    // Free the allocated memory
    free(str1_copy);
    free(str_concat);

    return 0;
}