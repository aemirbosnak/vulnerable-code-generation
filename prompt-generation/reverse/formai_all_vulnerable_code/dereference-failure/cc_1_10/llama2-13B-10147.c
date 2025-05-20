//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

// Function to copy a string without modifying the original
void strcpy_safe(char *dest, const char *src) {
    size_t len = strlen(src);
    memcpy(dest, src, len + 1);
}

// Function to concatenate two strings without modifying the original
char *strcat_safe(char *dest, const char *src) {
    size_t len = strlen(dest);
    size_t src_len = strlen(src);
    char *new_dest = realloc(dest, len + src_len + 1);
    if (new_dest == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    memcpy(new_dest + len, src, src_len + 1);
    return new_dest;
}

// Function to reverse a string without modifying the original
char *strrev_safe(char *str) {
    size_t len = strlen(str);
    char *new_str = malloc(len + 1);
    if (new_str == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        new_str[i] = str[len - i - 1];
    }
    new_str[len] = '\0';
    return new_str;
}

int main() {
    char str1[] = "Hello";
    char str2[] = " World";
    char str3[MAX_STR_LEN];

    // Copy string without modifying the original
    strcpy_safe(str3, str1);
    printf("Original: %s\n", str1);
    printf("Copied: %s\n", str3);

    // Concatenate strings without modifying the original
    strcat_safe(str3, str2);
    printf("Original: %s\n", str1);
    printf("Concatenated: %s\n", str3);

    // Reverse a string without modifying the original
    strrev_safe(str3);
    printf("Original: %s\n", str3);
    printf("Reversed: %s\n", str3);

    return 0;
}