//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentence;
    int length;
} Sentence;

int main() {
    srand(time(NULL));
    int numWords = rand() % MAX_WORDS + 1;
    char *words[MAX_WORDS];
    int lengths[MAX_WORDS];
    int totalLength = 0;

    // Generate random words
    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length] = '\0';
        words[i] = strdup(word);
        lengths[i] = length;
        totalLength += length;
    }

    // Generate random sentence
    char sentence[MAX_SENTENCE_LENGTH];
    int sentenceLength = rand() % MAX_SENTENCE_LENGTH + 1;
    for (int i = 0; i < sentenceLength; i++) {
        int wordIndex = rand() % numWords;
        strncat(sentence, words[wordIndex], lengths[wordIndex]);
        if (i < sentenceLength - 1) {
            strcat(sentence, " ");
        }
    }

    // Print sentence and word counts
    printf("Random sentence: %s\n", sentence);
    printf("Total word count: %d\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("Word %d: %s (%d characters)\n", i + 1, words[i], lengths[i]);
    }

    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
    free(sentence);

    return 0;
}