//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int numPairs;
} Index;

void initIndex(Index *index) {
    index->pairs = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    index->numPairs = 0;
}

void addPair(Index *index, char *key, char *value) {
    if (index->numPairs >= MAX_NUM_KEYS) {
        printf("Error: Index is full.\n");
        return;
    }

    strcpy(index->pairs[index->numPairs].key, key);
    strcpy(index->pairs[index->numPairs].value, value);
    index->numPairs++;
}

void searchIndex(Index *index, char *key, char *result) {
    int i;
    for (i = 0; i < index->numPairs; i++) {
        if (strcmp(index->pairs[i].key, key) == 0) {
            strcpy(result, index->pairs[i].value);
            return;
        }
    }

    strcpy(result, "");
}

int main() {
    Index index;
    initIndex(&index);

    addPair(&index, "apple", "red");
    addPair(&index, "banana", "yellow");
    addPair(&index, "cherry", "red");

    char result[MAX_VAL_LEN];
    searchIndex(&index, "apple", result);
    printf("Value for 'apple': %s\n", result);

    searchIndex(&index, "grape", result);
    printf("Value for 'grape': %s\n", result);

    return 0;
}