//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(char* filename, char* buffer) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    fread(buffer, fileSize, 1, file);
    fclose(file);
}

void tokenize(char* buffer, char* delimiter, WordCount* wordCounts, int numWords) {
    char* token = strtok(buffer, delimiter);
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            strncpy(wordCounts[numWords].word, token, MAX_WORD_LENGTH - 1);
            wordCounts[numWords].word[MAX_WORD_LENGTH - 1] = '\0';
            wordCounts[numWords].count = 1;
            numWords++;
        }
        token = strtok(NULL, delimiter);
    }
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }
    char filename[100];
    strcpy(filename, argv[1]);
    char delimiter = argv[2][0];
    char buffer[1000000]; // 1 MB should be enough for most files
    readFile(filename, buffer);
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    tokenize(buffer, delimiter, wordCounts, numWords);
    printWordCounts(wordCounts, numWords);
    return 0;
}