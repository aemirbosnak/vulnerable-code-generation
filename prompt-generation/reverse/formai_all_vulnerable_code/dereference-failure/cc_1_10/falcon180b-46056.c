//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    char *key;
    int value;
} Pair;

Pair *hashTable;

int hash(char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]!= '\0') {
        sum += key[i];
        i++;
    }
    return sum % MAX_SIZE;
}

void init() {
    hashTable = (Pair *) malloc(MAX_SIZE * sizeof(Pair));
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable[i].key = NULL;
        hashTable[i].value = -1;
    }
}

int search(char *key) {
    int index = hash(key);
    Pair *pair = &hashTable[index];
    while (pair->key!= NULL) {
        if (strcmp(pair->key, key) == 0) {
            return pair->value;
        }
        pair++;
    }
    return -1;
}

void insert(char *key, int value) {
    int index = hash(key);
    Pair *pair = &hashTable[index];
    while (pair->key!= NULL) {
        if (strcmp(pair->key, key) == 0) {
            pair->value = value;
            return;
        }
        pair++;
    }
    pair->key = strdup(key);
    pair->value = value;
}

void delete(char *key) {
    int index = hash(key);
    Pair *pair = &hashTable[index];
    while (pair->key!= NULL) {
        if (strcmp(pair->key, key) == 0) {
            pair->key = NULL;
            pair->value = -1;
            return;
        }
        pair++;
    }
}

void display() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Pair *pair = &hashTable[i];
        while (pair->key!= NULL) {
            printf("%s -> %d\n", pair->key, pair->value);
            pair++;
        }
    }
}

int main() {
    init();
    insert("apple", 1);
    insert("banana", 2);
    insert("cherry", 3);
    display();
    printf("%d\n", search("banana"));
    delete("banana");
    display();
    return 0;
}