//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        reversed[len - i - 1] = str[i];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest common substring between two strings
char* longestCommonSubstring(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLen = 0;
    int start = 0;
    int i, j;
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            int k = 0;
            while (str1[i + k] == str2[j + k] && i + k < len1 && j + k < len2) {
                k++;
            }
            if (k > maxLen) {
                maxLen = k;
                start = i;
            }
        }
    }
    char* lcs = malloc(maxLen + 1);
    strncpy(lcs, str1 + start, maxLen);
    lcs[maxLen] = '\0';
    return lcs;
}

// Function to find the longest common prefix between two strings
char* longestCommonPrefix(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = len1 < len2 ? len1 : len2;
    int i;
    for (i = 0; i < minLen; i++) {
        if (str1[i] != str2[i]) {
            break;
        }
    }
    char* lcp = malloc(i + 1);
    strncpy(lcp, str1, i);
    lcp[i] = '\0';
    return lcp;
}

// Function to find the longest common suffix between two strings
char* longestCommonSuffix(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = len1 < len2 ? len1 : len2;
    int i;
    for (i = 0; i < minLen; i++) {
        if (str1[len1 - i - 1] != str2[len2 - i - 1]) {
            break;
        }
    }
    char* lcs = malloc(i + 1);
    strncpy(lcs, str1 + len1 - i, i);
    lcs[i] = '\0';
    return lcs;
}

// Function to find the longest palindrome in a string
char* longestPalindrome(char* str) {
    int len = strlen(str);
    int maxLen = 0;
    int start = 0;
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            int k = 0;
            while (str[i + k] == str[j - k] && i + k < len && j - k >= 0) {
                k++;
            }
            if (k > maxLen) {
                maxLen = k;
                start = i;
            }
        }
    }
    char* palindrome = malloc(maxLen + 1);
    strncpy(palindrome, str + start, maxLen);
    palindrome[maxLen] = '\0';
    return palindrome;
}

// Function to test the string manipulation functions
int main() {
    char* str1 = "hello";
    char* str2 = "world";

    printf("Reversed string: %s\n", reverseString(str1));
    printf("Is palindrome: %d\n", isPalindrome(str1));
    printf("Longest common substring: %s\n", longestCommonSubstring(str1, str2));
    printf("Longest common prefix: %s\n", longestCommonPrefix(str1, str2));
    printf("Longest common suffix: %s\n", longestCommonSuffix(str1, str2));
    printf("Longest palindrome: %s\n", longestPalindrome(str1));

    return 0;
}