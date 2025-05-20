//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main() {
    srand(time(NULL));

    int numWords;
    scanf("%d", &numWords);

    WordFrequency *wordFrequency = (WordFrequency *)malloc(sizeof(WordFrequency) * numWords);

    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        scanf("%s", word);

        strcpy(wordFrequency[i].word, word);
        wordFrequency[i].frequency = rand() % 100;
    }

    printWordFrequency(wordFrequency, numWords);

    return 0;
}