//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(FILE* file, char* buffer, int* bufferSize) {
    int c;
    while ((c = fgetc(file))!= EOF) {
        if (*bufferSize == 0) {
            fprintf(stderr, "Error: File is too large.\n");
            exit(1);
        }
        if (c == '\n') {
            *bufferSize = 0;
        } else {
            buffer[*bufferSize] = tolower(c);
            (*bufferSize)++;
        }
    }
}

void countWords(char* buffer, int bufferSize, WordFrequency* wordFrequencies, int numWordFrequencies) {
    char* wordStart = buffer;
    int numWords = 0;
    while (numWords < MAX_NUM_WORDS && bufferSize > 0) {
        if (isspace(buffer[0])) {
            buffer++;
            bufferSize--;
        } else {
            int wordLength = 0;
            while (!isspace(buffer[wordLength]) && wordLength < MAX_WORD_LENGTH) {
                wordLength++;
            }
            strncpy(wordFrequencies[numWords].word, wordStart, wordLength);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
            buffer += wordLength;
            bufferSize -= wordLength;
            while (bufferSize > 0 && isspace(buffer[0])) {
                buffer++;
                bufferSize--;
            }
            wordStart = buffer;
        }
    }
}

void printWordFrequencies(WordFrequency* wordFrequencies, int numWordFrequencies) {
    for (int i = 0; i < numWordFrequencies; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }
    char buffer[MAX_FILE_SIZE];
    int bufferSize = 0;
    readFile(file, buffer, &bufferSize);
    WordFrequency wordFrequencies[MAX_NUM_WORDS];
    int numWordFrequencies = 0;
    countWords(buffer, bufferSize, wordFrequencies, MAX_NUM_WORDS);
    printWordFrequencies(wordFrequencies, numWordFrequencies);
    return 0;
}