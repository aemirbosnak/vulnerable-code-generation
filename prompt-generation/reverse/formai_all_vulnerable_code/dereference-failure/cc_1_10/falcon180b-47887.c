//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

Word dictionary[MAX_WORDS];
int numWords = 0;

void loadDictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        strcpy(dictionary[numWords].word, word);
        strcpy(dictionary[numWords].translation, translation);

        numWords++;
    }

    fclose(fp);
}

int binarySearch(char *word) {
    int left = 0;
    int right = numWords - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int cmp = strcmp(dictionary[mid].word, word);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void translate(char *sentence) {
    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        int index = binarySearch(token);

        if (index == -1) {
            printf("Unknown word: %s\n", token);
        } else {
            printf("%s -> %s\n", token, dictionary[index].translation);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    loadDictionary();

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, 1000, stdin);

    translate(sentence);

    return 0;
}