//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordPair;

int main() {
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    WordPair *wordPairs = (WordPair *)malloc(MAX_WORDS * sizeof(WordPair));
    int numWords = 0;

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, dictionaryFile)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        strcpy(wordPairs[numWords].word, word);
        strcpy(wordPairs[numWords].translation, translation);

        numWords++;
    }

    fclose(dictionaryFile);

    char input[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word to translate: ");
        fgets(input, MAX_WORD_LEN, stdin);

        char *translatedWord = strtok(input, " ");
        if (translatedWord == NULL) {
            break;
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(translatedWord, wordPairs[i].word) == 0) {
                printf("Translation: %s\n", wordPairs[i].translation);
                break;
            }
        }

        if (i == numWords) {
            printf("No translation found.\n");
        }
    }

    return 0;
}