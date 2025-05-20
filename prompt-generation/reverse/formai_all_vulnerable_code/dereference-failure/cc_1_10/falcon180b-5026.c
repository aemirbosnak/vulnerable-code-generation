//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} Translation;

int main() {
    FILE *dictFile;
    char line[MAX_WORD_LENGTH];
    Translation dict[MAX_WORDS];
    int numWords = 0;

    dictFile = fopen("dictionary.txt", "r");

    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, dictFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary is full.\n");
            fclose(dictFile);
            return 1;
        }

        char *englishWord = strtok(line, " ");
        char *alienWord = strtok(NULL, " ");

        if (englishWord == NULL || alienWord == NULL) {
            printf("Error: Invalid entry in dictionary file.\n");
            fclose(dictFile);
            return 1;
        }

        dict[numWords].english = strdup(englishWord);
        dict[numWords].alien = strdup(alienWord);

        numWords++;
    }

    fclose(dictFile);

    char input[MAX_WORD_LENGTH];

    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char *token = strtok(input, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, dict[i].english) == 0) {
                printf("%s ", dict[i].alien);
                break;
            }
        }

        if (i == numWords) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}