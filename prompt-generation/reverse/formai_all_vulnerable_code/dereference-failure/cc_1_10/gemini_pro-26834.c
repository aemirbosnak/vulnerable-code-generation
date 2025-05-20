//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Decentralized string manipulation functions
char *str_cat(char *s1, char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    strcpy(result, s1);
    strcpy(result + len1, s2);
    return result;
}

char *str_dup(char *s) {
    size_t len = strlen(s);
    char *result = malloc(len + 1);
    strcpy(result, s);
    return result;
}

char *str_find(char *s, char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return &s[i];
        }
    }
    return NULL;
}

int str_len(char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char *str_rev(char *s) {
    size_t len = strlen(s);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = s[len - i - 1];
    }
    result[len] = '\0';
    return result;
}

int main() {
    // Example usage
    char *s1 = "Hello";
    char *s2 = "World";

    // Concatenate strings
    char *s3 = str_cat(s1, s2);
    printf("Concatenated string: %s\n", s3);

    // Duplicate string
    char *s4 = str_dup(s1);
    printf("Duplicated string: %s\n", s4);

    // Find character in string
    char *pos = str_find(s1, 'e');
    printf("Character found at position: %d\n", pos - s1);

    // Get string length
    int len = str_len(s1);
    printf("String length: %d\n", len);

    // Reverse string
    char *s5 = str_rev(s1);
    printf("Reversed string: %s\n", s5);

    // Free allocated memory
    free(s3);
    free(s4);
    free(s5);

    return 0;
}