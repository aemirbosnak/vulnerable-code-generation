//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverseString(char* str)
{
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversed[i] = str[j];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest common substring of two strings
char* longestCommonSubstring(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxlen = 0;
    int start = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int k = 0;
            while (str1[i + k] == str2[j + k] && i + k < len1 && j + k < len2) {
                k++;
            }
            if (k > maxlen) {
                maxlen = k;
                start = i;
            }
        }
    }
    return strndup(str1 + start, maxlen);
}

// Function to find the longest palindrome in a string
char* longestPalindrome(char* str)
{
    int len = strlen(str);
    int maxlen = 1;
    int start = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int k = 0;
            while (str[i + k] == str[j - k] && i + k < j - k) {
                k++;
            }
            if (k > maxlen) {
                maxlen = k;
                start = i;
            }
        }
    }
    return strndup(str + start, maxlen);
}

int main()
{
    // Create a string
    char* str = "Hello World!";

    // Reverse the string
    char* reversed = reverseString(str);

    // Check if the string is a palindrome
    int is_palindrome = isPalindrome(str);

    // Find the longest common substring of two strings
    char* substring = longestCommonSubstring("Hello", "World");

    // Find the longest palindrome in a string
    char* palindrome = longestPalindrome(str);

    // Print the results
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reversed);
    printf("Is the string a palindrome? %s\n", is_palindrome ? "Yes" : "No");
    printf("Longest common substring: %s\n", substring);
    printf("Longest palindrome: %s\n", palindrome);

    // Free the allocated memory
    free(reversed);
    free(substring);
    free(palindrome);

    return 0;
}