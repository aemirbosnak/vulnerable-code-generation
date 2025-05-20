//FormAI DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a given word is spelled correctly
int spellCheck(char *word, char **dictionary, int dictionarySize) {
    // Convert all characters in the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Linear search through the dictionary for the given word
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            // Word found in dictionary, return 1 (true)
            return 1;
        }
    }

    // Word not found in dictionary, return 0 (false)
    return 0;
}

int main() {
    // Open dictionary file to read words
    FILE *fp;
    char *filename = "dictionary.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s", filename);
        exit(1);
    }

    // Read dictionary words into array
    char *dictionary[10000];
    int dictionarySize = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        dictionary[dictionarySize] = (char *) malloc(strlen(line) + 1);
        strcpy(dictionary[dictionarySize], line);
        dictionarySize++;
    }

    // Close dictionary file
    fclose(fp);

    // Prompt user for input
    char input[256];
    printf("Enter a sentence to spell check:\n");
    fgets(input, sizeof(input), stdin);

    // Split input sentence into individual words
    char *word = strtok(input, " ");
    while (word != NULL) {
        // Remove newline character from end of word
        if (strlen(word) > 0 && word[strlen(word)-1] == '\n') {
            word[strlen(word)-1] = '\0';
        }

        // Check if word is spelled correctly
        if (!spellCheck(word, dictionary, dictionarySize)) {
            printf("Did you mean:");

            // Generate possible correct spellings by swapping adjacent letters
            for (int i = 0; i < strlen(word)-1; i++) {
                char temp = word[i];
                word[i] = word[i+1];
                word[i+1] = temp;

                if (spellCheck(word, dictionary, dictionarySize)) {
                    printf(" %s", word);
                }

                // Swap letters back to original positions
                temp = word[i];
                word[i] = word[i+1];
                word[i+1] = temp;
            }

            printf("\n");
        }

        // Get next word in input sentence
        word = strtok(NULL, " ");
    }

    // Free memory allocated to dictionary
    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }

    return 0;
}