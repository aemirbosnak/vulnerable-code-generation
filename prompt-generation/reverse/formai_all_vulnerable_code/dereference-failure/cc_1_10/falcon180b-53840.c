//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

WordTranslation dictionary[MAX_WORDS];
int numWords = 0;

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char* token = strtok(line, " ");
        strcpy(word, token);
        token = strtok(NULL, " ");
        strcpy(translation, token);

        if (numWords >= MAX_WORDS) {
            printf("Dictionary is full.\n");
            exit(1);
        }

        strcpy(dictionary[numWords].word, word);
        strcpy(dictionary[numWords].translation, translation);

        numWords++;
    }

    fclose(file);
}

void translate(const char* sentence) {
    char word[MAX_WORD_LENGTH];
    char* token = strtok(sentence, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                printf("%s ", dictionary[i].translation);
                break;
            }
        }

        if (i == numWords) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    loadDictionary("dictionary.txt");

    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    translate(sentence);

    return 0;
}