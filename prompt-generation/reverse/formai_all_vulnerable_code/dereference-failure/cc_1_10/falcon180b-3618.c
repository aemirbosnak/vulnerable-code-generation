//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    int numKeys;
    int numValues;
    KeyValuePair *keys;
    KeyValuePair *values;
} Index;

void createIndex(Index *index) {
    index->numKeys = 0;
    index->numValues = 0;
    index->keys = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    index->values = (KeyValuePair *)malloc(MAX_NUM_VALUES * sizeof(KeyValuePair));
}

void addKeyValuePair(Index *index, char *key, char *value) {
    int i;
    for (i = 0; i < index->numKeys; i++) {
        if (strcmp(key, index->keys[i].key) == 0) {
            strcpy(index->values[i].value, value);
            return;
        }
    }
    if (index->numKeys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return;
    }
    if (index->numValues >= MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return;
    }
    strcpy(index->keys[index->numKeys].key, key);
    strcpy(index->values[index->numValues].value, value);
    index->numKeys++;
    index->numValues++;
}

void searchIndex(Index *index, char *key) {
    int i;
    for (i = 0; i < index->numKeys; i++) {
        if (strcmp(key, index->keys[i].key) == 0) {
            printf("%s\n", index->values[i].value);
            return;
        }
    }
    printf("Key not found.\n");
}

int main() {
    Index index;
    createIndex(&index);
    addKeyValuePair(&index, "apple", "red");
    addKeyValuePair(&index, "banana", "yellow");
    addKeyValuePair(&index, "orange", "orange");
    searchIndex(&index, "apple");
    searchIndex(&index, "banana");
    searchIndex(&index, "orange");
    return 0;
}