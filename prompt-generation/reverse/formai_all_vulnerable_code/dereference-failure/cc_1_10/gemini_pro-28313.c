//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverseString(char* str) {
    int len = strlen(str);
    char* reversedString = malloc(len + 1);
    int i, j;
    for(i = 0, j = len - 1; i < len; i++, j--) {
        reversedString[i] = str[j];
    }
    reversedString[len] = '\0';
    return reversedString;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char* longestPalindrome(char* str) {
    int len = strlen(str);
    int maxLen = 1;
    int start = 0;
    int end = 0;
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            int lenOfSubstring = j - i + 1;
            if(lenOfSubstring > maxLen && isPalindrome(str + i)) {
                maxLen = lenOfSubstring;
                start = i;
                end = j;
            }
        }
    }
    char* longestPalindrome = malloc(maxLen + 1);
    strncpy(longestPalindrome, str + start, maxLen);
    longestPalindrome[maxLen] = '\0';
    return longestPalindrome;
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int len = strlen(str);
    int count = 0;
    for(int i = 0; i < len; i++) {
        char ch = str[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}

// Function to find the most frequent character in a string
char mostFrequentCharacter(char* str) {
    int len = strlen(str);
    int frequency[256] = {0};
    for(int i = 0; i < len; i++) {
        frequency[str[i]]++;
    }
    int maxFrequency = 0;
    char mostFrequentCharacter;
    for(int i = 0; i < 256; i++) {
        if(frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentCharacter = i;
        }
    }
    return mostFrequentCharacter;
}

int main() {
    char* str = "Hello, world!";

    // Reverse the string
    char* reversedString = reverseString(str);
    printf("Reversed string: %s\n", reversedString);

    // Check if the string is a palindrome
    int isPalindromeResult = isPalindrome(str);
    printf("Is palindrome: %d\n", isPalindromeResult);

    // Find the longest palindrome in the string
    char* longestPalindromeResult = longestPalindrome(str);
    printf("Longest palindrome: %s\n", longestPalindromeResult);

    // Count the number of vowels in the string
    int countVowelsResult = countVowels(str);
    printf("Number of vowels: %d\n", countVowelsResult);

    // Find the most frequent character in the string
    char mostFrequentCharacterResult = mostFrequentCharacter(str);
    printf("Most frequent character: %c\n", mostFrequentCharacterResult);

    return 0;
}