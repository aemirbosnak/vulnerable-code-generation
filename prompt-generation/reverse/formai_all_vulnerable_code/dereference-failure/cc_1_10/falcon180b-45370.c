//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} HashEntry;

HashEntry *hashTable = NULL;

unsigned int hash(char *key) {
    unsigned int hashValue = 0;
    int i = 0;
    while (key[i]!= '\0') {
        hashValue += key[i];
        i++;
    }
    return hashValue % MAX_SIZE;
}

void initHashTable() {
    hashTable = (HashEntry *)malloc(MAX_SIZE * sizeof(HashEntry));
    memset(hashTable, 0, MAX_SIZE * sizeof(HashEntry));
}

void insert(char *key, int value) {
    unsigned int index = hash(key);
    HashEntry *entry = &hashTable[index];
    while (entry->key!= NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry++;
    }
    entry->key = (char *)malloc(strlen(key) + 1);
    strcpy(entry->key, key);
    entry->value = value;
}

int search(char *key) {
    unsigned int index = hash(key);
    HashEntry *entry = &hashTable[index];
    while (entry->key!= NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry++;
    }
    return -1;
}

int main() {
    initHashTable();
    insert("apple", 10);
    insert("banana", 20);
    insert("orange", 30);
    insert("pear", 40);
    int value = search("orange");
    if (value!= -1) {
        printf("Value of orange: %d\n", value);
    } else {
        printf("Orange not found.\n");
    }
    return 0;
}