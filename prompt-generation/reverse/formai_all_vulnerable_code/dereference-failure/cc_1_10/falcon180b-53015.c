//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 1000
#define MAX_NUM_INDEXES 1000
#define MAX_INDEX_SIZE 200

typedef struct {
    char *word;
    int index;
} WordIndex;

typedef struct {
    char *name;
    int numWords;
    WordIndex *indexes;
} Index;

Index *createIndex(char *name) {
    Index *index = malloc(sizeof(Index));
    index->name = strdup(name);
    index->numWords = 0;
    index->indexes = malloc(MAX_NUM_INDEXES * sizeof(WordIndex));
    return index;
}

void addWordToIndex(Index *index, char *word) {
    if (index->numWords >= MAX_NUM_WORDS) {
        printf("Error: Index is full.\n");
        return;
    }
    WordIndex *indexEntry = &index->indexes[index->numWords];
    indexEntry->word = strdup(word);
    indexEntry->index = index->numWords;
    index->numWords++;
}

void searchIndex(Index *index, char *query) {
    int numMatches = 0;
    WordIndex *indexEntry = index->indexes;
    while (numMatches < MAX_NUM_INDEXES && indexEntry->word!= NULL) {
        if (strcmp(indexEntry->word, query) == 0) {
            printf("Found match: %s\n", indexEntry->word);
            numMatches++;
        }
        indexEntry++;
    }
}

int main() {
    Index *index = createIndex("test index");
    addWordToIndex(index, "apple");
    addWordToIndex(index, "banana");
    addWordToIndex(index, "cherry");
    searchIndex(index, "apple");
    searchIndex(index, "orange");
    return 0;
}