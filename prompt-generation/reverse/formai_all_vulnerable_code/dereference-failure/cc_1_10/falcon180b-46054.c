//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_pair;

word_pair words[MAX_WORDS];
int num_words = 0;

void load_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        char* word = strtok(line, " ");
        char* translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: invalid line in file %s\n", filename);
            exit(1);
        }

        strcpy(words[num_words].word, word);
        strcpy(words[num_words].translation, translation);

        num_words++;
    }

    fclose(fp);
}

void translate(char* sentence) {
    char* word = strtok(sentence, " ");
    char result[MAX_WORD_LEN];

    while (word!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                strcpy(result, words[i].translation);
                break;
            }
        }

        if (i == num_words) {
            strcpy(result, word);
        }

        strcat(result, " ");

        word = strtok(NULL, " ");
    }

    printf("%s\n", result);
}

int main() {
    load_words("words.txt");

    char sentence[MAX_WORD_LEN*10];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_WORD_LEN*10, stdin);

    translate(sentence);

    return 0;
}