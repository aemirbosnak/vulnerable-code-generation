//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY_SIZE 1000
#define MAX_CHAR_LENGTH 50

typedef struct {
    char english[MAX_CHAR_LENGTH];
    char cat[MAX_CHAR_LENGTH];
} Vocabulary;

int vocabulary_count = 0;
Vocabulary vocabulary[MAX_VOCABULARY_SIZE];

void load_vocabulary() {
    FILE *file;
    char line[MAX_CHAR_LENGTH];
    char *token;

    file = fopen("vocabulary.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open vocabulary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_CHAR_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        strcpy(vocabulary[vocabulary_count].english, token);
        token = strtok(NULL, ",");
        strcpy(vocabulary[vocabulary_count].cat, token);
        vocabulary_count++;
    }

    fclose(file);
}

void translate(char *sentence) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < vocabulary_count; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                printf("%s ", vocabulary[i].cat);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    load_vocabulary();
    char sentence[MAX_CHAR_LENGTH];

    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_CHAR_LENGTH, stdin);
    translate(sentence);

    return 0;
}