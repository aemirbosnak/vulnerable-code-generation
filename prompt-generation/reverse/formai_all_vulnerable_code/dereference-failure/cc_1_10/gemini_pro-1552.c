//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        newStr[len - i - 1] = str[i];
    }
    newStr[len] = '\0';
    return newStr;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest substring of a string that is a palindrome
char *longestPalindromeSubstring(char *str) {
    int len = strlen(str);
    int i, j, k;
    int maxLength = 0;
    int start = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            for (k = 0; k < (j - i + 1) / 2; k++) {
                if (str[i + k] != str[j - k]) {
                    break;
                }
            }
            if (k == (j - i + 1) / 2 && j - i + 1 > maxLength) {
                maxLength = j - i + 1;
                start = i;
            }
        }
    }
    char *newStr = malloc(maxLength + 1);
    strncpy(newStr, str + start, maxLength);
    newStr[maxLength] = '\0';
    return newStr;
}

// Function to find the longest common substring of two strings
char *longestCommonSubstring(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j, k;
    int maxLength = 0;
    int start = 0;
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            for (k = 0; k < (len1 - i) && k < (len2 - j); k++) {
                if (str1[i + k] != str2[j + k]) {
                    break;
                }
            }
            if (k > maxLength) {
                maxLength = k;
                start = i;
            }
        }
    }
    char *newStr = malloc(maxLength + 1);
    strncpy(newStr, str1 + start, maxLength);
    newStr[maxLength] = '\0';
    return newStr;
}

// Function to find the longest repeated substring of a string
char *longestRepeatedSubstring(char *str) {
    int len = strlen(str);
    int i, j, k;
    int maxLength = 0;
    int start = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            for (k = 0; k < (len - j) && k < (len - i); k++) {
                if (str[i + k] != str[j + k]) {
                    break;
                }
            }
            if (k > maxLength) {
                maxLength = k;
                start = i;
            }
        }
    }
    char *newStr = malloc(maxLength + 1);
    strncpy(newStr, str + start, maxLength);
    newStr[maxLength] = '\0';
    return newStr;
}

// Main function
int main() {
    char str[] = "Hello, world!";

    printf("Original string: %s\n", str);

    char *reversedString = reverseString(str);
    printf("Reversed string: %s\n", reversedString);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    char *longestPalindrome = longestPalindromeSubstring(str);
    printf("Longest palindrome substring: %s\n", longestPalindrome);

    char str1[] = "Hello";
    char str2[] = "World";

    char *longestCommon = longestCommonSubstring(str1, str2);
    printf("Longest common substring: %s\n", longestCommon);

    char *longestRepeated = longestRepeatedSubstring(str);
    printf("Longest repeated substring: %s\n", longestRepeated);

    return 0;
}