//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to convert a string to uppercase
char* to_upper(char* str) {
    int len = strlen(str);
    char* upper = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        upper[i] = toupper(str[i]);
    }
    upper[len] = '\0';
    return upper;
}

// Function to convert a string to lowercase
char* to_lower(char* str) {
    int len = strlen(str);
    char* lower = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        lower[i] = tolower(str[i]);
    }
    lower[len] = '\0';
    return lower;
}

// Function to remove all spaces from a string
char* remove_spaces(char* str) {
    int len = strlen(str);
    char* trimmed = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            trimmed[j++] = str[i];
        }
    }
    trimmed[j] = '\0';
    return trimmed;
}

// Function to remove all punctuation from a string
char* remove_punctuation(char* str) {
    int len = strlen(str);
    char* filtered = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (ispunct(str[i])) {
            continue;
        }
        filtered[j++] = str[i];
    }
    filtered[j] = '\0';
    return filtered;
}

// Function to test the string manipulation functions
int main() {
    char* str = "Hello World!";

    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reverse(str));
    printf("Uppercase string: %s\n", to_upper(str));
    printf("Lowercase string: %s\n", to_lower(str));
    printf("Trimmed string: %s\n", remove_spaces(str));
    printf("Filtered string: %s\n", remove_punctuation(str));

    return 0;
}