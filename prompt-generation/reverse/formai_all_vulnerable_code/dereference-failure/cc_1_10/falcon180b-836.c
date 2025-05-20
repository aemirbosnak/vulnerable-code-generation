//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= strlen(buffer)) {
            printf("Error: Buffer overflow.\n");
            exit(1);
        }
        buffer[index++] = tolower(ch);
    }
    buffer[index] = '\0';
}

void tokenize(char *buffer, WordCount words[MAX_WORDS]) {
    char *token = strtok(buffer, ",.!?;:\"'()[]{}<>");
    int count = 0;

    while (token!= NULL && count < MAX_WORDS) {
        if (strlen(token) > 0) {
            strcpy(words[count].word, token);
            words[count].count = 1;
            count++;
        }
        token = strtok(NULL, ",.!?;:\"'()[]{}<>");
    }
}

void printWords(WordCount words[MAX_WORDS], int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    readFile(file, buffer);

    WordCount words[MAX_WORDS];
    tokenize(buffer, words);

    printWords(words, MAX_WORDS);

    return 0;
}