//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define a macro to check if a character is a whitespace character
#define IS_WHITESPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')

// Define a macro to check if a character is a punctuation character
#define IS_PUNCTUATION(c) ((c) == '.' || (c) == ',' || (c) == ';' || (c) == '!' || (c) == '?' || (c) == ':' || (c) == '(' || (c) == ')' || (c) == '[' || (c) == ']' || (c) == '{' || (c) == '}' || (c) == '\'' || (c) == '"')

// Define a function to remove all whitespace characters from a string
char *remove_whitespace(char *str) {
    char *new_str = malloc(strlen(str) + 1);
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!IS_WHITESPACE(str[i])) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Define a function to remove all punctuation characters from a string
char *remove_punctuation(char *str) {
    char *new_str = malloc(strlen(str) + 1);
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!IS_PUNCTUATION(str[i])) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Define a function to convert a string to lowercase
char *to_lowercase(char *str) {
    char *new_str = malloc(strlen(str) + 1);
    for (int i = 0; str[i] != '\0'; i++) {
        new_str[i] = tolower(str[i]);
    }
    new_str[strlen(str)] = '\0';
    return new_str;
}

// Define a function to reverse a string
char *reverse_string(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        new_str[i] = str[j];
    }
    new_str[len] = '\0';
    return new_str;
}

// Define a function to print a string in a box
void print_in_box(char *str) {
    int len = strlen(str);
    printf("+");
    for (int i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("+\n");
    printf("| %s |\n", str);
    printf("+");
    for (int i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

// Define a function to test the string manipulation functions
void test_string_manipulation_functions() {
    char *str = "This is a test string.";
    printf("Original string: %s\n", str);
    printf("String without whitespace: %s\n", remove_whitespace(str));
    printf("String without punctuation: %s\n", remove_punctuation(str));
    printf("String in lowercase: %s\n", to_lowercase(str));
    printf("Reversed string: %s\n", reverse_string(str));
    print_in_box(str);
}

int main() {
    test_string_manipulation_functions();
    return 0;
}