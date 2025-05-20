//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

bool loadWords(char* filename, WordFrequency* words, int* numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words from file.\n");
        return false;
    }

    char line[MAX_WORD_LENGTH];
    char* wordStart = NULL;
    int wordLength = 0;
    int numWordsRead = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char* wordEnd = line + strlen(line) - 1;
        while (wordEnd > line && isspace(*wordEnd)) {
            wordEnd--;
        }

        if (wordEnd - wordStart >= MAX_WORD_LENGTH) {
            printf("Word too long: %s\n", wordStart);
            continue;
        }

        strncpy(words[numWordsRead].word, wordStart, MAX_WORD_LENGTH);
        words[numWordsRead].word[wordLength] = '\0';
        words[numWordsRead].count = 1;
        numWordsRead++;

        if (numWordsRead >= MAX_NUM_WORDS) {
            printf("Reached maximum number of words.\n");
            break;
        }
    }

    fclose(file);
    *numWords = numWordsRead;
    return true;
}

bool compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word) < 0;
}

void printWordFrequencies(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency words[MAX_NUM_WORDS];
    int numWords = 0;

    if (!loadWords(argv[1], words, &numWords)) {
        return 1;
    }

    printWordFrequencies(words, numWords);

    return 0;
}