//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = a;
    const WordFrequency* wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char inputBuffer[10000];
    char* input = inputBuffer;
    char* wordStart = input;
    char* wordEnd;
    char* token;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Read input from standard input
    while (fgets(input, sizeof(inputBuffer), stdin)!= NULL) {
        input += strlen(input);

        // Tokenize input into words
        while ((token = strtok_r(wordStart, " \t\n\r\f\v", &wordEnd))!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words\n");
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].frequency = 1;
            numWords++;

            wordStart = NULL;
        }
    }

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequency
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}