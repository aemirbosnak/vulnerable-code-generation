//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char english[50];
    char cat[50];
} word_t;

void load_words(word_t words[]) {
    FILE *fp = fopen("words.txt", "r");
    char line[100];

    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
        char *token = strtok(line, ",");
        strcpy(words[count].english, token);
        token = strtok(NULL, ",");
        strcpy(words[count].cat, token);
        count++;
    }

    fclose(fp);
}

void translate_sentence(word_t words[], char sentence[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        int found = 0;
        for (i = 0; i < strlen(words[0].english); i++) {
            if (words[0].english[i] == token[0]) {
                printf("%s ", words[0].cat);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("meow ");
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
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(words, sentence);

    return 0;
}