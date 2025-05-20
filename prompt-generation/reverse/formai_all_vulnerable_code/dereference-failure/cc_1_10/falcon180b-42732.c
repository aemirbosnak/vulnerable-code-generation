//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
    int numWords = 0;
    WordPair *wordPairs = (WordPair*)malloc(sizeof(WordPair) * MAX_WORDS);

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Warning: Maximum number of words reached\n");
            break;
        }
        sscanf(line, "%s %s", word, translation);
        strcpy(wordPairs[numWords].word, word);
        strcpy(wordPairs[numWords].translation, translation);
        numWords++;
    }

    fclose(file);

    printf("Enter a sentence to translate:\n");
    fgets(line, MAX_WORD_LENGTH, stdin);

    char *token = strtok(line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, wordPairs[i].word) == 0) {
                printf("%s ", wordPairs[i].translation);
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