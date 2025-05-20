//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

typedef struct {
    int count;
    char **words;
} WordList;

// Asynchronous function to read a file and count the occurrences of each word
void countWordsAsync(char *filename, void (*callback)(WordList *)) {
    WordList *wordList = malloc(sizeof(WordList));
    wordList->count = 0;
    wordList->words = NULL;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char *word = strtok(buffer, " \n\r\t");
        while (word != NULL) {
            bool found = false;
            for (int i = 0; i < wordList->count; i++) {
                if (strcmp(wordList->words[i], word) == 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                if (wordList->words == NULL) {
                    wordList->words = malloc(sizeof(char *));
                } else {
                    wordList->words = realloc(wordList->words, sizeof(char *) * (wordList->count + 1));
                }
                wordList->words[wordList->count] = malloc(sizeof(char) * (strlen(word) + 1));
                strcpy(wordList->words[wordList->count++], word);
            }

            word = strtok(NULL, " \n\r\t");
        }
    }

    fclose(file);

    callback(wordList);
}

// Callback function to print the word counts
void printWordCounts(WordList *wordList) {
    printf("Word counts:\n");
    for (int i = 0; i < wordList->count; i++) {
        int count = 0;
        FILE *file = fopen("example.txt", "r");
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
            char *word = strtok(buffer, " \n\r\t");
            while (word != NULL) {
                if (strcmp(word, wordList->words[i]) == 0) {
                    count++;
                }
                word = strtok(NULL, " \n\r\t");
            }
        }
        fclose(file);

        printf("%s: %d\n", wordList->words[i], count);
    }

    // Clean up allocated memory
    for (int i = 0; i < wordList->count; i++) {
        free(wordList->words[i]);
    }
    free(wordList->words);
    free(wordList);
}

int main() {
    printf("Reading file (asynchronously)...\n");

    countWordsAsync("example.txt", printWordCounts);

    printf("Program is running asynchronously\n");

    // Keep the program running while the asynchronous code is executing
    while (true) {}

    return 0;
}