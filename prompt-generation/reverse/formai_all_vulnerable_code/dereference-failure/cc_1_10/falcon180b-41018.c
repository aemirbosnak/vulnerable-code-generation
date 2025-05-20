//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_MAX_LENGTH 50

// Function to remove non-alphabetic characters from a string
void removeNonAlphabetic(char* str) {
    int i, j = 0;
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to split a string into words
char* splitString(char* str, char delimiter) {
    char* word = strtok(str, delimiter);
    while (word!= NULL) {
        removeNonAlphabetic(word);
        printf("%s\n", word);
        word = strtok(NULL, delimiter);
    }
}

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " \t\n\r\f");
    while (word!= NULL) {
        removeNonAlphabetic(word);
        printf("%s\n", word);
        count++;
        word = strtok(NULL, " \t\n\r\f");
    }
    return count;
}

int main() {
    char input[MAX_WORDS * WORD_MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int numWords = countWords(input);
    printf("Number of words: %d\n", numWords);

    printf("Enter delimiter (space, tab, newline, carriage return, form feed): ");
    char delimiter = getchar();

    splitString(input, delimiter);

    return 0;
}