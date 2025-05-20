//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_INDEX_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int index;
} WordIndex;

typedef struct {
    WordIndex *wordIndex;
    int numWords;
} Index;

void initIndex(Index *index) {
    index->wordIndex = (WordIndex *)malloc(MAX_INDEX_SIZE * sizeof(WordIndex));
    index->numWords = 0;
}

void addWord(Index *index, char *word) {
    WordIndex *wi = &index->wordIndex[index->numWords];
    strcpy(wi->word, word);
    wi->index = index->numWords;
    index->numWords++;
}

void printIndex(Index *index) {
    printf("Index:\n");
    for (int i = 0; i < index->numWords; i++) {
        printf("%s -> %d\n", index->wordIndex[i].word, index->wordIndex[i].index);
    }
}

void searchIndex(Index *index, char *query) {
    int i = 0;
    while (i < index->numWords) {
        WordIndex *wi = &index->wordIndex[i];
        if (strcmp(wi->word, query) == 0) {
            printf("Found word '%s' at index %d\n", query, wi->index);
            return;
        }
        i++;
    }
    printf("Word not found\n");
}

int main() {
    Index index;
    initIndex(&index);

    addWord(&index, "apple");
    addWord(&index, "banana");
    addWord(&index, "cherry");

    printIndex(&index);

    searchIndex(&index, "banana");

    return 0;
}