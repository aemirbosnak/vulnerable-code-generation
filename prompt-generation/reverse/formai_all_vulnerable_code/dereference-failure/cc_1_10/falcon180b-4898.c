//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void initializeWordFrequencyArray(WordFrequency* array) {
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        strcpy(array[i].word, "");
        array[i].count = 0;
    }
}

bool isWord(char c) {
    return isalpha(c);
}

void readFile(FILE* file, WordFrequency* array) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        char* wordStart = buffer;
        while (isWord(*wordStart)) {
            wordStart++;
        }
        char* wordEnd = wordStart;
        while (isWord(*wordEnd)) {
            wordEnd--;
        }
        char word[MAX_WORD_LENGTH];
        strncpy(word, wordStart, wordEnd - wordStart + 1);
        word[wordEnd - wordStart] = '\0';
        for (int i = 0; i < MAX_WORD_COUNT; i++) {
            if (strcmp(array[i].word, word) == 0) {
                array[i].count++;
                break;
            }
        }
    }
}

void printWordFrequency(WordFrequency* array) {
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (array[i].count > 0) {
            printf("%s\t%d\n", array[i].word, array[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char filename[1024];
    strcpy(filename, argv[1]);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Failed to open file '%s'.\n", filename);
        return 1;
    }
    WordFrequency array[MAX_WORD_COUNT];
    initializeWordFrequencyArray(array);
    readFile(file, array);
    fclose(file);
    printWordFrequency(array);
    return 0;
}