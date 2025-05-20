//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    if (str == NULL) {
        return 0;
    }

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

// Function to reverse a string
void reverse_string(char *str) {
    if (str == NULL) {
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Function to find the longest palindromic substring in a string
char *longest_palindromic_substring(char *str) {
    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    int max_len = 0;
    char *longest_substring = NULL;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char *substring = strndup(str + i, j - i);

            if (is_palindrome(substring)) {
                int substring_len = strlen(substring);

                if (substring_len > max_len) {
                    max_len = substring_len;
                    longest_substring = substring;
                }
            }

            free(substring);
        }
    }

    return longest_substring;
}

int main() {
    char *str = "racecar";

    printf("Is '%s' a palindrome? %s\n", str, is_palindrome(str) ? "Yes" : "No");

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    char *longest_substring = longest_palindromic_substring(str);
    printf("Longest palindromic substring: %s\n", longest_substring);

    free(longest_substring);

    return 0;
}