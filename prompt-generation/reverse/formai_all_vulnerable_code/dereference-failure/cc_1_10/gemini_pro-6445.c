//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverse(char* str) {
    int len = strlen(str);
    char* rev = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char* longest_palindrome(char* str) {
    int len = strlen(str);
    int max_len = 0;
    char* max_palindrome = NULL;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char* substring = malloc(j - i + 1);
            memcpy(substring, str + i, j - i);
            substring[j - i] = '\0';
            if (is_palindrome(substring) && strlen(substring) > max_len) {
                max_len = strlen(substring);
                max_palindrome = substring;
            }
        }
    }
    return max_palindrome;
}

// Main function
int main() {
    // Test the reverse function
    char* str = "Hello, world!";
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reverse(str));

    // Test the is_palindrome function
    str = "racecar";
    printf("String: %s\n", str);
    printf("Is palindrome: %d\n", is_palindrome(str));

    // Test the longest_palindrome function
    str = "12321";
    printf("String: %s\n", str);
    printf("Longest palindrome: %s\n", longest_palindrome(str));

    return 0;
}