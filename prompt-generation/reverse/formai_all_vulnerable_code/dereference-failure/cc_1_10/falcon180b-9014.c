//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char *english;
    char *alien;
} word_t;

void load_words(word_t words[]) {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char *token;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (fgets(line, MAX_WORD_LEN, fp) == NULL) {
            printf("Error: words.txt is empty or corrupted\n");
            exit(1);
        }

        token = strtok(line, " ");
        words[i].english = strdup(token);

        token = strtok(NULL, " ");
        words[i].alien = strdup(token);
    }

    fclose(fp);
}

void unload_words(word_t words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i].english);
        free(words[i].alien);
    }
}

void translate_sentence(char *sentence, word_t words[]) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    word_t words[MAX_WORDS];

    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, 1000, stdin);

    translate_sentence(sentence, words);

    unload_words(words);

    return 0;
}