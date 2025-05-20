//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *reversed = malloc(len + 1);
    int i;
    for (i = len - 1; i >= 0; i--) {
        reversed[len - i - 1] = str[i];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int i, j, k, max_len = 0, start_index = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (is_palindrome(str + i) && j - i + 1 > max_len) {
                max_len = j - i + 1;
                start_index = i;
            }
        }
    }
    char *longest = malloc(max_len + 1);
    strncpy(longest, str + start_index, max_len);
    longest[max_len] = '\0';
    return longest;
}

// Function to test the string manipulation functions
int main() {
    char *str1 = "Hello";
    char *str2 = "racecar";
    char *str3 = "kayak";
    char *str4 = "banana";

    printf("Original string: %s\n", str1);
    printf("Reversed string: %s\n", reverse(str1));
    printf("Palindrome? %d\n", is_palindrome(str1));

    printf("Original string: %s\n", str2);
    printf("Reversed string: %s\n", reverse(str2));
    printf("Palindrome? %d\n", is_palindrome(str2));

    printf("Original string: %s\n", str3);
    printf("Reversed string: %s\n", reverse(str3));
    printf("Palindrome? %d\n", is_palindrome(str3));

    printf("Original string: %s\n", str4);
    printf("Reversed string: %s\n", reverse(str4));
    printf("Palindrome? %d\n", is_palindrome(str4));

    printf("Longest palindrome: %s\n", longest_palindrome(str1));
    printf("Longest palindrome: %s\n", longest_palindrome(str2));
    printf("Longest palindrome: %s\n", longest_palindrome(str3));
    printf("Longest palindrome: %s\n", longest_palindrome(str4));

    return 0;
}