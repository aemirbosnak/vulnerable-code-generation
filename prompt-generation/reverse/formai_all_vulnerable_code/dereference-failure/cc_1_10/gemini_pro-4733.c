//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to concatenate two strings
char *concat(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = malloc(len1 + len2 + 1);  // +1 for the null-terminator
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);  // +1 for the null-terminator
    for (int i = 0; i < len; i++) {
        result[i] = str[len - i - 1];
    }
    result[len] = '\0';  // Add null-terminator
    return result;
}

// Function to convert a string to uppercase
char *touppercase(char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);  // +1 for the null-terminator
    for (int i = 0; i < len; i++) {
        result[i] = toupper(str[i]);
    }
    result[len] = '\0';  // Add null-terminator
    return result;
}

// Function to convert a string to lowercase
char *tolowercase(char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);  // +1 for the null-terminator
    for (int i = 0; i < len; i++) {
        result[i] = tolower(str[i]);
    }
    result[len] = '\0';  // Add null-terminator
    return result;
}

// Function to check if a string is a palindrome
int ispalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Palindrome
}

int main() {
    char *str1 = "Hello";
    char *str2 = "World";

    // Concatenate the two strings
    char *result = concat(str1, str2);
    printf("Concatenated string: %s\n", result);

    // Reverse the concatenated string
    result = reverse(result);
    printf("Reversed string: %s\n", result);

    // Convert the reversed string to uppercase
    result = touppercase(result);
    printf("Uppercase string: %s\n", result);

    // Convert the uppercase string to lowercase
    result = tolowercase(result);
    printf("Lowercase string: %s\n", result);

    // Check if the lowercase string is a palindrome
    if (ispalindrome(result)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    // Free the allocated memory
    free(result);

    return 0;
}