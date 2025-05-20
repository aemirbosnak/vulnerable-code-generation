//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_STRLEN 32
#define MAX_STRLEN 1024

// Function to check if a string is empty
inline int is_empty(const char *str) {
    return *str == '\0';
}

// Function to check if a string is not empty
inline int is_not_empty(const char *str) {
    return *str != '\0';
}

// Function to reverse a string
char *reverse_string(char *str) {
    size_t len = strlen(str);
    char *rev = malloc(len * sizeof(char));
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    free(str);
    return rev;
}

// Function to trim leading and trailing whitespaces from a string
char *trim_whitespace(char *str) {
    size_t len = strlen(str);
    char *trimmed = malloc(len * sizeof(char));
    for (size_t i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            trimmed[i] = str[i];
        }
    }
    free(str);
    return trimmed;
}

// Function to find the longest common prefix of two strings
char *find_lcp(char *str1, char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *lcp = malloc(len1 + len2 * sizeof(char));
    size_t i = 0;
    for (; i < len1 && i < len2; i++) {
        if (str1[i] == str2[i]) {
            lcp[i] = str1[i];
        } else {
            break;
        }
    }
    return lcp;
}

int main() {
    char *str1 = "Hello, World!";
    char *str2 = "World, Hello!";
    char *rev_str1 = reverse_string(str1);
    char *rev_str2 = reverse_string(str2);
    char *lcp = find_lcp(str1, str2);
    printf("LCP: %s\n", lcp);
    printf("Reversed str1: %s\n", rev_str1);
    printf("Reversed str2: %s\n", rev_str2);
    free(rev_str1);
    free(rev_str2);
    free(lcp);
    return 0;
}