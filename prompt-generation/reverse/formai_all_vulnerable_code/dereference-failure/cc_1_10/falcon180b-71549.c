//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 64
#define MAX_SENTENCE_LEN 512

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *word;
    int count;
    bool isPunctuation;
} Word;

char *getWord(char *sentence) {
    char *word = malloc(MAX_WORD_LEN);
    int i = 0;
    while (isalpha(*sentence)) {
        word[i] = tolower(*sentence);
        sentence++;
        i++;
    }
    word[i] = '\0';
    return word;
}

void translate(char *sentence) {
    char *translated = malloc(MAX_SENTENCE_LEN);
    int i = 0;
    while (*sentence) {
        if (isalpha(*sentence)) {
            char *word = getWord(sentence);
            if (strlen(word) == 1) {
                translated[i] = 'a';
            } else if (strlen(word) == 2) {
                translated[i] = 'b';
            } else if (strlen(word) == 3) {
                translated[i] = 'c';
            } else if (strlen(word) == 4) {
                translated[i] = 'd';
            } else {
                translated[i] = 'e';
            }
            i++;
        } else {
            translated[i] = *sentence;
            i++;
        }
        sentence++;
    }
    translated[i] = '\0';
    printf("%s\n", translated);
    free(translated);
}

int main() {
    char sentence[MAX_SENTENCE_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_SENTENCE_LEN, stdin);
    translate(sentence);
    return 0;
}