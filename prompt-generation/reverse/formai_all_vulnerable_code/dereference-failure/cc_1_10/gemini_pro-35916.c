//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int max_len = 0;
    char *longest = NULL;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char *substr = strndup(str + i, j - i);
            if (is_palindrome(substr) && strlen(substr) > max_len) {
                max_len = strlen(substr);
                longest = substr;
            }
            free(substr);
        }
    }
    return longest;
}

int main() {
    // Test the functions
    char *str1 = "Hello";
    char *str2 = "racecar";
    char *str3 = "banana";

    printf("Original string: %s\n", str1);
    printf("Reversed string: %s\n", reverse(str1));
    printf("Is palindrome: %d\n", is_palindrome(str2));
    printf("Is palindrome: %d\n", is_palindrome(str3));
    printf("Longest palindrome: %s\n", longest_palindrome(str3));

    return 0;
}