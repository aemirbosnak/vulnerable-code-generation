//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function to count the words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to print the words in a string
void printWords(char* str) {
    char* word = strtok(str, " ");
    while (word!= NULL) {
        printf("%s ", word);
        word = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;
    int i;

    // Get input from user
    printf("Enter a string: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Count the number of words in the input string
    int wordCount = countWords(input);

    // Split the input string into individual words and store them in an array
    char* word = strtok(input, " ");
    for (i = 0; i < wordCount; i++) {
        strcpy(words[i], word);
        word = strtok(NULL, " ");
    }

    // Print the number of words and the words themselves
    printf("Number of words: %d\n", wordCount);
    printf("Words: ");
    for (i = 0; i < wordCount; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}