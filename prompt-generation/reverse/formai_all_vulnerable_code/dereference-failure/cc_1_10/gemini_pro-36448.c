//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *reversedString = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversedString[i] = str[j];
    }
    reversedString[len] = '\0';
    return reversedString;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest substring that is a palindrome
char *longestPalindrome(char *str) {
    int len = strlen(str);
    int maxLen = 1;
    int start = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int len = j - i + 1;
            if (len > maxLen && isPalindrome(str + i)) {
                maxLen = len;
                start = i;
            }
        }
    }
    return strndup(str + start, maxLen);
}

// Function to find the longest common substring of two strings
char *longestCommonSubstring(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int len = 0;
            while (str1[i + len] == str2[j + len] && i + len < len1 && j + len < len2) {
                len++;
            }
            if (len > maxLen) {
                maxLen = len;
                start = i;
            }
        }
    }
    return strndup(str1 + start, maxLen);
}

// Function to find the longest repeating substring of a string
char *longestRepeatingSubstring(char *str) {
    int len = strlen(str);
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int len = 0;
            while (str[i + len] == str[j + len] && i + len < len && j + len < len) {
                len++;
            }
            if (len > maxLen) {
                maxLen = len;
                start = i;
            }
        }
    }
    return strndup(str + start, maxLen);
}

int main() {
    char *str = "Hello, world!";

    // Reverse the string
    char *reversedString = reverseString(str);
    printf("Reversed string: %s\n", reversedString);

    // Check if the string is a palindrome
    int isPal = isPalindrome(str);
    printf("Is the string a palindrome? %s\n", isPal ? "Yes" : "No");

    // Find the longest substring that is a palindrome
    char *longestPal = longestPalindrome(str);
    printf("Longest palindrome substring: %s\n", longestPal);

    // Find the longest common substring of two strings
    char *str1 = "Hello, world!";
    char *str2 = "Hello, universe!";
    char *longestCommon = longestCommonSubstring(str1, str2);
    printf("Longest common substring: %s\n", longestCommon);

    // Find the longest repeating substring of a string
    char *longestRepeating = longestRepeatingSubstring(str);
    printf("Longest repeating substring: %s\n", longestRepeating);

    // Free the allocated memory
    free(reversedString);
    free(longestPal);
    free(longestCommon);
    free(longestRepeating);

    return 0;
}