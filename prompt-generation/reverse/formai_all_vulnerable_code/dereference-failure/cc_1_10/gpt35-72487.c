//FormAI DATASET v1.0 Category: Text Summarizer ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define a struct for storing each word and its frequency
typedef struct {
    char* word;
    int freq;
} WordFreq;

// forward declaration of function to read input file and count word frequency
void countWordFreq(char* filename, WordFreq** wordCount, int* numWords);

// forward declaration of function to sort and print the word frequency summary
void printWordFreqSummary(WordFreq* wordCount, int numWords);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    WordFreq* wordCount;
    int numWords;

    // count word frequency and build summary
    countWordFreq(argv[1], &wordCount, &numWords);
    printWordFreqSummary(wordCount, numWords);

    // cleanup
    for (int i = 0; i < numWords; i++) {
        free(wordCount[i].word);
    }
    free(wordCount);
    
    return 0;
}

void countWordFreq(char* filename, WordFreq** wordCount, int* numWords) {
    // open input file
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        printf("Error: unable to open input file\n");
        exit(1);
    }

    // initialize word count data structure
    *wordCount = (WordFreq*) malloc(sizeof(WordFreq) * 10);
    *numWords = 0;
    int maxWords = 10;

    // read input file word by word and count frequency
    char nextWord[100];
    while (fscanf(in, "%s", nextWord) == 1) {
        // check if we need to resize word count array
        if (*numWords == maxWords) {
            maxWords *= 2;
            *wordCount = (WordFreq*) realloc(*wordCount, sizeof(WordFreq) * maxWords);
        }

        // check if word already exists in word count array
        int wordIndex = -1;
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(nextWord, (*wordCount)[i].word) == 0) {
                wordIndex = i;
                break;
            }
        }

        // if word does not exist, add it to word count array
        if (wordIndex == -1) {
            (*wordCount)[*numWords].word = (char*) malloc(sizeof(char) * (strlen(nextWord) + 1));
            strcpy((*wordCount)[*numWords].word, nextWord);
            (*wordCount)[*numWords].freq = 1;
            (*numWords)++;
        } else {
            // if word already exists, increment its frequency count
            (*wordCount)[wordIndex].freq++;
        }
    }

    // close input file
    fclose(in);

    // shrink word count array if necessary
    if (*numWords < maxWords) {
        *wordCount = (WordFreq*) realloc(*wordCount, sizeof(WordFreq) * (*numWords));
    }
}

void printWordFreqSummary(WordFreq* wordCount, int numWords) {
    // sort word count array by frequency in descending order
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (wordCount[i].freq < wordCount[j].freq) {
                // swap i and j in word count array
                WordFreq tmp = wordCount[i];
                wordCount[i] = wordCount[j];
                wordCount[j] = tmp;
            }
        }
    }

    // print word frequency summary
    printf("Word frequency summary:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCount[i].word, wordCount[i].freq);
    }
}