//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to count the frequency of words in a given string
void countWords(char* str, char* word, int* freq) {
    char* token = strtok(str, " ");
    while (token!= NULL) {
        if (strcmp(token, word) == 0) {
            (*freq)++;
        }
        token = strtok(NULL, " ");
    }
}

// Function to remove non-alphabetic characters from a string
void removeNonAlpha(char* str) {
    int len = strlen(str);
    char* newStr = malloc(len + 1);
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (isalpha(str[j])) {
            newStr[i++] = tolower(str[j]);
        }
    }
    newStr[i] = '\0';
    strcpy(str, newStr);
    free(newStr);
}

// Function to print the frequency of a word in a given string
void printFreq(char* str, char* word, int freq) {
    printf("%s appears %d times in the string.\n", word, freq);
}

int main() {
    char string[1000];
    char word[100];
    int freq = 0;

    // Get the string from user
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    // Remove non-alphabetic characters and convert to lowercase
    removeNonAlpha(string);

    // Get the word from user
    printf("Enter a word to count: ");
    fgets(word, sizeof(word), stdin);

    // Count the frequency of the word in the string
    countWords(string, word, &freq);

    // Print the frequency of the word in the string
    printf("The frequency of '%s' in the string is: ", word);
    printFreq(string, word, freq);

    return 0;
}