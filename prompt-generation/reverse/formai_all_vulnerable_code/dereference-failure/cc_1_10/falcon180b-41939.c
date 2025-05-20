//Falcon-180B DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Function to count words in a string
int countWords(char *str) {
    int count = 0;
    char *word = strtok(str, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

// Function to convert a string to uppercase
void strToUpper(char *str) {
    int i = 0;

    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to convert a string to lowercase
void strToLower(char *str) {
    int i = 0;

    while (str[i]!= '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to remove all vowels from a string
void removeVowels(char *str) {
    char vowels[] = "aeiouAEIOU";
    int i = 0;

    while (str[i]!= '\0') {
        if (strchr(vowels, tolower(str[i])) == NULL) {
            str[i] = tolower(str[i]);
            i++;
        } else {
            str[i] = '\0';
            i++;
        }
    }
}

int main() {
    char inputStr[MAX_WORDS][MAX_WORD_LEN];
    int numWords;

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", inputStr);

    // Count number of words in input string
    numWords = countWords(inputStr);

    // Reverse input string
    reverseString(inputStr);

    // Convert input string to uppercase
    strToUpper(inputStr);

    // Remove all vowels from input string
    removeVowels(inputStr);

    // Print modified string and number of words
    printf("Modified string: %s\n", inputStr);
    printf("Number of words: %d\n", numWords);

    return 0;
}