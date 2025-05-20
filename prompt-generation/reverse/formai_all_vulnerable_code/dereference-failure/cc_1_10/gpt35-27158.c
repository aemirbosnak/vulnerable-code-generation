//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_WORDS 10000
#define MAX_WORD_LENGTH 50

// Function to remove non-alphabetic characters from a string
void removeNonAlpha(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to check if a word is spelled correctly
int spellCheck(char* word, char** dictionary) {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Load dictionary
    FILE* dictFile;
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(EXIT_FAILURE);
    }
    char** dictionary = malloc(NUM_WORDS * sizeof(char*));
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        dictionary[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
        if (fgets(dictionary[i], MAX_WORD_LENGTH, dictFile) == NULL) {
            break;
        }
        removeNonAlpha(dictionary[i]);
    }
    fclose(dictFile);

    // Spell checking loop
    char input[MAX_WORD_LENGTH];
    printf("Enter some text: ");
    while (fgets(input, MAX_WORD_LENGTH, stdin) != NULL) {
        char* token = strtok(input, " ");
        while (token != NULL) {
            removeNonAlpha(token);
            if (!spellCheck(token, dictionary)) {
                printf("Did you mean: ");
                int j;
                for (j = 0; token[j] != '\0'; j++) {
                    char c = token[j];
                    if (islower(c)) {
                        printf("%c", toupper(c));
                    } else {
                        printf("%c", c);
                    }
                }
                printf("? ");
            }
            token = strtok(NULL, " ");
        }
        printf("\nEnter some more text: ");
    }

    // Free memory
    for (i = 0; i < NUM_WORDS; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}