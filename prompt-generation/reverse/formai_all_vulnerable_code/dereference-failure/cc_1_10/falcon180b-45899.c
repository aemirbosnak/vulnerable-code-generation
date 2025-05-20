//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char** argv) {
    FILE* inputFile;
    char line[1000];
    WordFrequency* wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;
    int wordLength;
    char* word;
    int i;

    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");
    if(inputFile == NULL) {
        printf("Error opening file %s.\n", argv[1]);
        exit(1);
    }

    while(fgets(line, 1000, inputFile)!= NULL) {
        word = strtok(line, ",.?!;:");
        while(word!= NULL) {
            wordLength = strlen(word);
            if(wordLength > MAX_WORD_LENGTH) {
                wordLength = MAX_WORD_LENGTH;
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].count = 1;
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for(i=0; i<numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);
    return 0;
}