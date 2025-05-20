//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: authentic
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

// Function to count the number of vowels in a string
int countVowels(char *str) {
    int len = strlen(str);
    int i;
    int count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }
    return count;
}

// Function to find the longest word in a string
char *longestWord(char *str) {
    int len = strlen(str);
    char *word = malloc(len + 1);
    int maxLen = 0;
    int i;
    int j;
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] == ' ') {
            if (j > maxLen) {
                maxLen = j;
                strncpy(word, &str[i - j], j);
            }
            j = 0;
        } else {
            j++;
        }
    }
    if (j > maxLen) {
        maxLen = j;
        strncpy(word, &str[i - j], j);
    }
    word[maxLen] = '\0';
    return word;
}

int main() {
    char str[] = "Hello, world!";

    // Reverse the string
    char *reversedStr = reverseString(str);
    printf("Reversed string: %s\n", reversedStr);

    // Check if the string is a palindrome
    int isPalindromeResult = isPalindrome(str);
    if (isPalindromeResult) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Count the number of vowels in the string
    int vowelCount = countVowels(str);
    printf("Number of vowels in the string: %d\n", vowelCount);

    // Find the longest word in the string
    char *longestWordResult = longestWord(str);
    printf("Longest word in the string: %s\n", longestWordResult);

    return 0;
}