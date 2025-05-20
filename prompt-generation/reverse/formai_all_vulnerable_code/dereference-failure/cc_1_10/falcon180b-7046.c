//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char* inputBuffer = NULL;
    size_t inputBufferSize = 0;

    WordFrequency* wordFrequencies = NULL;
    int numWords = 0;

    while (getline(&inputBuffer, &inputBufferSize, inputFile)!= -1) {
        char* wordStart = inputBuffer;
        while (wordStart < inputBuffer + strlen(inputBuffer)) {
            char* wordEnd = wordStart;
            while (wordEnd < inputBuffer + strlen(inputBuffer) && isalnum(*wordEnd)) {
                wordEnd++;
            }

            char word[MAX_WORD_LENGTH];
            strncpy(word, wordStart, wordEnd - wordStart);
            word[wordEnd - wordStart] = '\0';

            for (int i = 0; i < numWords; i++) {
                if (strcmp(wordFrequencies[i].word, word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }

            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                break;
            }

            WordFrequency newWord;
            strcpy(newWord.word, word);
            newWord.frequency = 1;
            wordFrequencies = realloc(wordFrequencies, sizeof(WordFrequency) * (numWords + 1));
            wordFrequencies[numWords++] = newWord;

            wordStart = wordEnd;
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(inputBuffer);
    free(wordFrequencies);

    return 0;
}