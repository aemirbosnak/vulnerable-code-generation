//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char *english;
    char *cat;
} WordPair;

int main() {
    FILE *dictFile;
    WordPair dict[MAX_WORDS];
    int numWords = 0;
    char line[MAX_WORD_LEN];
    char *token;

    // Open dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read in dictionary
    while (fgets(line, MAX_WORD_LEN, dictFile)!= NULL) {
        token = strtok(line, " ");
        if (numWords >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            fclose(dictFile);
            return 1;
        }
        dict[numWords].english = strdup(token);
        token = strtok(NULL, " ");
        dict[numWords].cat = strdup(token);
        numWords++;
    }
    fclose(dictFile);

    // Translate input
    char input[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LEN, stdin);

    // Split input into words
    char *word = strtok(input, " ");
    while (word!= NULL) {
        // Translate word
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, dict[i].english) == 0) {
                printf("%s ", dict[i].cat);
                break;
            }
        }
        if (i == numWords) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}