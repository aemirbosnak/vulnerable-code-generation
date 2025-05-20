//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char **words;
    int count;
} WordList;

// Function to initialize a WordList
WordList* createWordList() {
    WordList *list = (WordList*)malloc(sizeof(WordList));
    list->words = (char**)malloc(MAX_WORDS * sizeof(char*));
    for (int i = 0; i < MAX_WORDS; i++) {
        list->words[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    list->count = 0;
    return list;
}

// Function to free the memory allocated for WordList
void freeWordList(WordList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->words[i]);
    }
    free(list->words);
    free(list);
}

// Function to split a string into words
int splitIntoWords(char *line, WordList *list) {
    char *token = strtok(line, " \n\t");
    while (token != NULL && list->count < MAX_WORDS) {
        strncpy(list->words[list->count++], token, MAX_WORD_LENGTH - 1);
        list->words[list->count - 1][MAX_WORD_LENGTH - 1] = '\0'; // Ensure null-termination
        token = strtok(NULL, " \n\t");
    }
    return list->count;
}

// Function to print the words
void printWords(WordList *list, const char *title) {
    printf("%s:\n", title);
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->words[i]);
    }
}

// Function to count occurrences of each word
void countWordOccurrences(WordList *list) {
    int *countArray = (int*)calloc(list->count, sizeof(int));

    for (int i = 0; i < list->count; i++) {
        if (countArray[i] == -1)
            continue;
        countArray[i] = 1;  // Initial count

        for (int j = i + 1; j < list->count; j++) {
            if (strcmp(list->words[i], list->words[j]) == 0) {
                countArray[i]++;
                countArray[j] = -1;  // Mark as counted
            }
        }
    }

    // Print word occurrences
    printf("\nWord Occurrences:\n");
    for (int i = 0; i < list->count; i++) {
        if (countArray[i] > 0) {
            printf("%s: %d\n", list->words[i], countArray[i]);
        }
    }
    free(countArray);
}

int main() {
    char line[MAX_LINE_LENGTH];
    WordList *wordList = createWordList();

    printf("Enter text (end with EOF, i.e., Ctrl+D):\n");
    while (fgets(line, sizeof(line), stdin) != NULL) {
        splitIntoWords(line, wordList);
    }

    printWords(wordList, "Extracted Words");
    countWordOccurrences(wordList);

    freeWordList(wordList);
    return 0;
}