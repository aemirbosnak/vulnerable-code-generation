//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

typedef struct {
    char *word;
    char *translation;
} WordPair;

WordPair *dictionary;
int numWords;

void loadDictionary() {
    FILE *f = fopen("dictionary.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening dictionary file\n");
        exit(1);
    }

    char line[MAX_WORD_LEN * 2 + 2];
    while (fgets(line, sizeof(line), f) != NULL) {
        char *word = strtok(line, ":");
        char *translation = strtok(NULL, "\n");

        WordPair *newWordPair = malloc(sizeof(WordPair));
        newWordPair->word = strdup(word);
        newWordPair->translation = strdup(translation);

        dictionary = realloc(dictionary, (numWords + 1) * sizeof(WordPair));
        dictionary[numWords++] = *newWordPair;
    }

    fclose(f);
}

void translateText() {
    char text[1000];
    printf("Enter text to translate: ");
    fgets(text, sizeof(text), stdin);

    char *word = strtok(text, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                printf("%s ", dictionary[i].translation);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", word);
        }

        word = strtok(NULL, " ");
    }

    printf("\n");
}

void main() {
    loadDictionary();
    translateText();
}