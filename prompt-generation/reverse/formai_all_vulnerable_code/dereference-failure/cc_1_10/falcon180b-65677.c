//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a word is in the dictionary
bool isInDictionary(char *word) {
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), dictFile)!= NULL) {
        if (strcmp(line, word) == 0) {
            fclose(dictFile);
            return true;
        }
    }

    fclose(dictFile);
    return false;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    char line[100];
    char word[100];
    int wordCount = 0;
    int misspelledWords = 0;

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);

            // Convert word to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Check if word is in dictionary
            if (!isInDictionary(word)) {
                misspelledWords++;
            }

            wordCount++;
            token = strtok(NULL, " ");
        }
    }

    printf("Total words: %d\n", wordCount);
    printf("Misspelled words: %d\n", misspelledWords);

    fclose(inputFile);
    return 0;
}