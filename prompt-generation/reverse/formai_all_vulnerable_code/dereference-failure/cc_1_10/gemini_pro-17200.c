//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Get the length of a string without using strlen()
int str_len(char *str) {
    int len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

// Copy a string without using strcpy()
char *str_cpy(char *dest, char *src) {
    int len = str_len(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

// Concatenate two strings without using strcat()
char *str_cat(char *dest, char *src) {
    int len_dest = str_len(dest);
    int len_src = str_len(src);
    for (int i = 0; i < len_src; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + len_src] = '\0';
    return dest;
}

// Find the first occurrence of a character in a string without using strchr()
char *str_chr(char *str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

// Find the last occurrence of a character in a string without using strrchr()
char *str_rchr(char *str, char c) {
    char *last_occurrence = NULL;
    while (*str != '\0') {
        if (*str == c) {
            last_occurrence = str;
        }
        str++;
    }
    return last_occurrence;
}

// Compare two strings without using strcmp()
int str_cmp(char *str1, char *str2) {
    int len1 = str_len(str1);
    int len2 = str_len(str2);
    if (len1 != len2) {
        return len1 - len2;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
    }
    return 0;
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World";

    printf("Length of str1: %d\n", str_len(str1));
    printf("Copy of str1: %s\n", str_cpy("turing", str1));
    printf("Concatenation of str1 and str2: %s\n", str_cat(str1, str2));
    printf("First occurrence of 'l' in str1: %s\n", str_chr(str1, 'l'));
    printf("Last occurrence of 'l' in str1: %s\n", str_rchr(str1, 'l'));
    printf("Comparison of str1 and str2: %d\n", str_cmp(str1, str2));

    return 0;
}