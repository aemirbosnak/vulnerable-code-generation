//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to read words from a file and store them in an array
void readWords(char *filename, char **words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int numWords = 0;

    // Read words from file and store them in array
    while (fscanf(file, "%s", word)!= EOF) {
        words[numWords] = strdup(word);
        numWords++;
    }

    fclose(file);
}

// Function to print all words in an array
void printWords(char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to search for a word in an array
int searchWord(char **words, int numWords, char *wordToFind) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i], wordToFind) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <word_to_search>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *wordToFind = argv[2];

    // Read words from file
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int numWords = 0;
    readWords(filename, words);

    // Print all words
    printf("All words:\n");
    printWords(words, numWords);

    // Search for a word
    int index = searchWord(words, numWords, wordToFind);
    if (index == -1) {
        printf("Word not found\n");
    } else {
        printf("Word found at index %d\n", index);
    }

    // Free memory
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}