//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *reversed = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to find the longest palindrome in a string
char *longestPalindrome(char *str) {
    int len = strlen(str);
    int maxLen = 1;
    int start = 0;
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            int k;
            for (k = 0; k < (j - i + 1) / 2; k++) {
                if (str[i + k] != str[j - k]) {
                    break;
                }
            }
            if (k == (j - i + 1) / 2 && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                start = i;
            }
        }
    }
    char *palindrome = malloc(maxLen + 1);
    strncpy(palindrome, str + start, maxLen);
    palindrome[maxLen] = '\0';
    return palindrome;
}

// Function to count the number of vowels in a string
int countVowels(char *str) {
    int len = strlen(str);
    int count = 0;
    int i;
    for (i = 0; i < len; i++) {
        char c = str[i];
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            count++;
        }
    }
    return count;
}

// Function to find the most frequent character in a string
char mostFrequentCharacter(char *str) {
    int len = strlen(str);
    int charCount[256] = {0};
    int i;
    for (i = 0; i < len; i++) {
        charCount[str[i]]++;
    }
    int maxCount = 0;
    char mostFrequentCharacter;
    for (i = 0; i < 256; i++) {
        if (charCount[i] > maxCount) {
            maxCount = charCount[i];
            mostFrequentCharacter = i;
        }
    }
    return mostFrequentCharacter;
}

// Main function
int main() {
    // Test the reverse function
    char str[] = "Hello";
    char *reversedStr = reverse(str);
    printf("Reversed string: %s\n", reversedStr);
    free(reversedStr);

    // Test the longestPalindrome function
    char str2[] = "racecar";
    char *longestPalindromeStr = longestPalindrome(str2);
    printf("Longest palindrome: %s\n", longestPalindromeStr);
    free(longestPalindromeStr);

    // Test the countVowels function
    char str3[] = "The quick brown fox jumps over the lazy dog";
    int vowelCount = countVowels(str3);
    printf("Number of vowels: %d\n", vowelCount);

    // Test the mostFrequentCharacter function
    char str4[] = "Hello world";
    char mostFrequentCharacterStr = mostFrequentCharacter(str4);
    printf("Most frequent character: %c\n", mostFrequentCharacterStr);

    return 0;
}