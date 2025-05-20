//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= strlen(buffer)) {
            printf("Error: Buffer overflow\n");
            exit(1);
        }
        buffer[index++] = tolower(ch);
    }
    buffer[index] = '\0';
}

void tokenize(char *buffer, WordFrequency *wordFrequencyTable) {
    char *token;
    int i = 0;

    token = strtok(buffer, ",.?!;:");
    while (token!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words\n");
            exit(1);
        }
        strcpy(wordFrequencyTable[i].word, token);
        wordFrequencyTable[i].count = 1;
        i++;
        token = strtok(NULL, ",.?!;:");
    }
}

void printWordFrequencyTable(WordFrequency *wordFrequencyTable) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencyTable[i].count > 0) {
            printf("%s: %d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[MAX_WORD_LENGTH * 100];
    WordFrequency wordFrequencyTable[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    readFile(file, buffer);
    fclose(file);

    tokenize(buffer, wordFrequencyTable);
    printWordFrequencyTable(wordFrequencyTable);

    return 0;
}