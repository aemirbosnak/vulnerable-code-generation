//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char english[50];
    char cat[50];
} word_t;

void load_words(word_t words[]) {
    FILE *fp;
    char line[100];
    int count = 0;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL && count < MAX_WORDS) {
        char *token = strtok(line, ",");
        strcpy(words[count].english, token);
        token = strtok(NULL, ",");
        strcpy(words[count].cat, token);
        count++;
    }

    fclose(fp);
}

void translate_sentence(word_t words[], char sentence[]) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("unknown word: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    word_t words[MAX_WORDS];
    load_words(words);

    char sentence[] = "Hello world, how are you?";
    translate_sentence(words, sentence);

    return 0;
}