//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *dictFile;
    struct word dictionary[MAX_WORDS];
    int numWords = 0;
    char line[100];

    // Open the dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    // Read in the dictionary
    while (fgets(line, sizeof(line), dictFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Dictionary is full.\n");
            break;
        }
        char *token = strtok(line, " ");
        strcpy(dictionary[numWords].english, token);
        token = strtok(NULL, " ");
        strcpy(dictionary[numWords].alien, token);
        numWords++;
    }

    // Close the dictionary file
    fclose(dictFile);

    // Translate input
    char input[MAX_WORD_LENGTH];
    printf("Enter a phrase to translate: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize input
    char *token = strtok(input, " ");
    while (token!= NULL) {
        // Search for word in dictionary
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(dictionary[i].english, token) == 0) {
                // Word found, print translation
                printf("%s ", dictionary[i].alien);
                break;
            }
        }
        if (i == numWords) {
            // Word not found, print original word
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}