//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Vocabulary;

int vocabulary_count = 0;
Vocabulary vocabulary[MAX_VOCABULARY];

void load_vocabulary() {
    FILE *file = fopen("vocabulary.txt", "r");
    if (file == NULL) {
        printf("Vocabulary file not found.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");
        strcpy(vocabulary[vocabulary_count].english, token);

        token = strtok(NULL, " ");
        strcpy(vocabulary[vocabulary_count].cat, token);

        vocabulary_count++;
    }

    fclose(file);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < vocabulary_count; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                printf("%s ", vocabulary[i].cat);
                break;
            }
        }

        if (i == vocabulary_count) {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    load_vocabulary();

    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    translate_sentence(sentence);

    return 0;
}