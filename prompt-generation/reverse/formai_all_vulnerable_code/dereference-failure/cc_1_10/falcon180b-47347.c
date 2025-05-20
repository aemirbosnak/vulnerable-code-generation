//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 2000

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

typedef struct {
    Word words[MAX_WORD_LENGTH];
    int numWords;
} Dictionary;

Dictionary loadDictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    Dictionary dict = { 0 };
    char line[MAX_INPUT_LENGTH];
    char* word;
    char* cat;
    int i = 0;

    if (fp == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    while (fgets(line, MAX_INPUT_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");
        cat = strtok(NULL, " ");

        if (i >= MAX_WORD_LENGTH) {
            printf("Dictionary too large\n");
            exit(1);
        }

        strcpy(dict.words[i].english, word);
        strcpy(dict.words[i].cat, cat);
        i++;
    }

    dict.numWords = i;
    fclose(fp);
    return dict;
}

void translate(Dictionary dict, char* input, char* output) {
    char* word;
    int i = 0;
    while ((word = strtok(input, " "))!= NULL) {
        if (i >= MAX_OUTPUT_LENGTH) {
            printf("Output too large\n");
            exit(1);
        }

        Word* w = NULL;
        for (int j = 0; j < dict.numWords; j++) {
            if (strcmp(dict.words[j].english, word) == 0) {
                w = &dict.words[j];
                break;
            }
        }

        if (w == NULL) {
            strcpy(output + strlen(output), word);
            strcat(output, " ");
        } else {
            strcpy(output + strlen(output), w->cat);
            strcat(output, " ");
        }

        i += strlen(word) + strlen(w->cat) + 1;
    }
}

int main() {
    Dictionary dict = loadDictionary("dictionary.txt");
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    translate(dict, input, output);
    printf("%s\n", output);

    return 0;
}