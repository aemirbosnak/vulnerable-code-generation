//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 500
#define MAX_NUM_KEYS 1000
#define MAX_NUM_VALUES 10000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

int numKeys = 0;
int numValues = 0;
KeyValue *keys = NULL;

void init() {
    keys = malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    memset(keys, 0, MAX_NUM_KEYS * sizeof(KeyValue));
    numKeys = 0;
    numValues = 0;
}

int addKey(char *key) {
    for (int i = 0; i < numKeys; i++) {
        if (strcmp(keys[i].key, key) == 0) {
            return i;
        }
    }
    if (numKeys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return -1;
    }
    strcpy(keys[numKeys].key, key);
    return numKeys++;
}

int addValue(int keyIndex, char *value) {
    if (keyIndex < 0 || keyIndex >= numKeys) {
        printf("Error: Invalid key index.\n");
        return -1;
    }
    if (numValues >= MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return -1;
    }
    strcpy(keys[keyIndex].value, value);
    return numValues++;
}

void printKeys() {
    for (int i = 0; i < numKeys; i++) {
        printf("%s -> %s\n", keys[i].key, keys[i].value);
    }
}

void printValues(char *key) {
    int keyIndex = addKey(key);
    if (keyIndex >= 0) {
        for (int i = 0; i < numValues; i++) {
            if (strcmp(keys[i].key, key) == 0) {
                printf("%s\n", keys[i].value);
            }
        }
    }
}

int main() {
    init();
    addKey("apple");
    addValue(0, "red");
    addValue(0, "green");
    addValue(0, "yellow");
    addKey("banana");
    addValue(1, "yellow");
    addValue(1, "green");
    printKeys(); // apple -> red, apple -> green, apple -> yellow, banana -> yellow, banana -> green
    printValues("apple"); // red, green, yellow
    printValues("banana"); // yellow, green
    return 0;
}