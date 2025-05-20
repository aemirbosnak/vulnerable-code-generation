//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} word_t;

void load_words(word_t words[]);
void translate_sentence(char sentence[], word_t words[]);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[1000];
    strcpy(sentence, argv[1]);

    word_t words[MAX_WORDS];
    load_words(words);

    translate_sentence(sentence, words);

    return 0;
}

void load_words(word_t words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(fp, "%s %s\n", words[word_count].english, words[word_count].cat)!= EOF) {
        word_count++;
    }

    fclose(fp);
}

void translate_sentence(char sentence[], word_t words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORD_LENGTH; i++) {
            if (token[i] == '\0') {
                break;
            }
            words[i].english[i] = token[i];
            words[i].cat[i] = '\0';
        }
        printf("%s -> %s\n", token, words[i].cat);
        token = strtok(NULL, " ");
    }
}