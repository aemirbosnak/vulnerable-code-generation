//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(FILE *file, WordFrequency words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[words[i].frequency] = tolower(ch);
            words[i].frequency++;
        } else {
            words[i].word[words[i].frequency] = '\0';
            i++;
        }
    }
}

void countFrequency(WordFrequency words[MAX_WORDS], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                strcpy(words[j].word, "");
                words[j].frequency = 0;
            }
        }
    }
}

void printFrequency(WordFrequency words[MAX_WORDS], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];
    int n = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    readFile(file, words);
    fclose(file);

    countFrequency(words, n);

    printFrequency(words, n);

    return 0;
}