//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverseString(char* str) {
    int len = strlen(str);
    char* reversedStr = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversedStr[i] = str[j];
    }
    reversedStr[len] = '\0';
    return reversedStr;
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    int i = 0;
    int inWord = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            inWord = 0;
        } else if (!inWord) {
            count++;
            inWord = 1;
        }
        i++;
    }
    return count;
}

// Function to count the number of lines in a string
int countLines(char* str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            count++;
        }
        i++;
    }
    return count;
}

// Function to count the number of characters in a string
int countCharacters(char* str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

// Function to print the frequency of each character in a string
void printCharacterFrequency(char* str) {
    int i, j;
    int len = strlen(str);
    int frequency[256] = {0};
    for (i = 0; i < len; i++) {
        frequency[str[i]]++;
    }
    for (i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", i, frequency[i]);
        }
    }
}

// Driver code
int main() {
    char str[] = "Hello, world! This is a test string.";
    printf("Original string: %s\n", str);

    // Reverse the string
    char* reversedStr = reverseString(str);
    printf("Reversed string: %s\n", reversedStr);

    // Count the number of words in the string
    int numWords = countWords(str);
    printf("Number of words: %d\n", numWords);

    // Count the number of lines in the string
    int numLines = countLines(str);
    printf("Number of lines: %d\n", numLines);

    // Count the number of characters in the string
    int numCharacters = countCharacters(str);
    printf("Number of characters: %d\n", numCharacters);

    // Print the frequency of each character in the string
    printCharacterFrequency(str);

    return 0;
}