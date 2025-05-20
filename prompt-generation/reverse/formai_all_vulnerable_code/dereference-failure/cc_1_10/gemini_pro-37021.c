//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the length of a string
int findStringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to reverse a string
void reverseString(char *str) {
    int length = findStringLength(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int checkPalindrome(char *str) {
    int length = findStringLength(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    int length = findStringLength(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ' && str[i - 1] != ' ') {
            count++;
        }
    }
    if (str[length - 1] != ' ') {
        count++;
    }
    return count;
}

// Function to find the most frequent character in a string
char findMostFrequentCharacter(char *str) {
    int length = findStringLength(str);
    int frequency[256] = {0};
    for (int i = 0; i < length; i++) {
        frequency[str[i]]++;
    }
    char mostFrequentCharacter = str[0];
    int maxFrequency = frequency[str[0]];
    for (int i = 1; i < 256; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentCharacter = str[i];
        }
    }
    return mostFrequentCharacter;
}

int main() {
    char str[] = "Hello, world!";

    printf("The length of the string is: %d\n", findStringLength(str));

    printf("The reversed string is: %s\n", str);
    reverseString(str);

    printf("Is the string a palindrome? %d\n", checkPalindrome(str));

    printf("The number of words in the string is: %d\n", countWords(str));

    printf("The most frequent character in the string is: %c\n", findMostFrequentCharacter(str));

    return 0;
}