//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount wordCounts[MAX_NUM_WORDS];
    int numWords;
} WordFreq;

void addWord(WordFreq *wf, char *word) {
    int i;
    // Convert word to lowercase
    for (i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    // See if word already exists
    for (i = 0; i < wf->numWords; i++) {
        if (strcmp(word, wf->wordCounts[i].word) == 0) {
            wf->wordCounts[i].count++;
            return;
        }
    }
    // Add new word
    if (wf->numWords < MAX_NUM_WORDS) {
        strcpy(wf->wordCounts[wf->numWords].word, word);
        wf->wordCounts[wf->numWords].count = 1;
        wf->numWords++;
    }
}

void printWordFreq(WordFreq *wf) {
    int i;
    printf("Word Frequency:\n");
    for (i = 0; i < wf->numWords; i++) {
        printf("%s: %d\n", wf->wordCounts[i].word, wf->wordCounts[i].count);
    }
}

int main() {
    char str[] = "This is a test string. Test string, this is.";
    char *word, *tokPtr;
    WordFreq wf;
    wf.numWords = 0;
    word = strtok_r(str, " ,.", &tokPtr);
    while (word) {
        addWord(&wf, word);
        word = strtok_r(NULL, " ,.", &tokPtr);
    }
    printWordFreq(&wf);
    return 0;
}