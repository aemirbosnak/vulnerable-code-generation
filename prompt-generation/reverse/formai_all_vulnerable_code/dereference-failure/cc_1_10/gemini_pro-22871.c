//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *newstr = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        newstr[i] = str[j];
    }
    newstr[len] = '\0';
    return newstr;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest substring without repeating characters
char *longest_substring_without_repeats(char *str) {
    int len = strlen(str);
    int max_len = 0;
    int start = 0;
    int end = 0;
    int i, j;
    int char_index[256];
    for (i = 0; i < 256; i++) {
        char_index[i] = -1;
    }
    for (i = 0; i < len; i++) {
        if (char_index[str[i]] != -1) {
            if (char_index[str[i]] >= start) {
                start = char_index[str[i]] + 1;
            }
        }
        char_index[str[i]] = i;
        if (i - start + 1 > max_len) {
            max_len = i - start + 1;
            end = i;
        }
    }
    char *substring = malloc(max_len + 1);
    for (i = 0, j = start; j <= end; i++, j++) {
        substring[i] = str[j];
    }
    substring[max_len] = '\0';
    return substring;
}

int main() {
    char *str = "Hello, world!";

    // Reverse the string
    char *reversed_str = reverse(str);
    printf("Reversed string: %s\n", reversed_str);
    free(reversed_str);

    // Check if the string is a palindrome
    int is_palindrome_result = is_palindrome(str);
    printf("Is the string a palindrome? %s\n", is_palindrome_result ? "Yes" : "No");

    // Find the longest substring without repeating characters
    char *longest_substring_without_repeats_result = longest_substring_without_repeats(str);
    printf("Longest substring without repeating characters: %s\n", longest_substring_without_repeats_result);
    free(longest_substring_without_repeats_result);

    return 0;
}