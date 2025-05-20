//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int data;
} HashTable;

HashTable *createHashTable(int size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable) * size);
    for (int i = 0; i < size; i++) {
        table[i].key = NULL;
        table[i].data = -1;
    }
    return table;
}

int hashFunction(char *key, int size) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % size;
}

void insert(HashTable *table, char *key, int data) {
    int index = hashFunction(key, MAX_SIZE);
    while (table[index].key!= NULL) {
        if (strcmp(table[index].key, key) == 0) {
            table[index].data = data;
            return;
        }
        index = (index + 1) % MAX_SIZE;
    }
    table[index].key = strdup(key);
    table[index].data = data;
}

int search(HashTable *table, char *key) {
    int index = hashFunction(key, MAX_SIZE);
    while (table[index].key!= NULL) {
        if (strcmp(table[index].key, key) == 0) {
            return table[index].data;
        }
        index = (index + 1) % MAX_SIZE;
    }
    return -1;
}

void delete(HashTable *table, char *key) {
    int index = hashFunction(key, MAX_SIZE);
    while (table[index].key!= NULL) {
        if (strcmp(table[index].key, key) == 0) {
            free(table[index].key);
            table[index].key = NULL;
            table[index].data = -1;
            return;
        }
        index = (index + 1) % MAX_SIZE;
    }
}

int main() {
    HashTable *table = createHashTable(MAX_SIZE);
    insert(table, "apple", 5);
    insert(table, "banana", 3);
    insert(table, "cherry", 2);
    insert(table, "date", 8);
    insert(table, "elderberry", 1);
    insert(table, "fig", 7);
    insert(table, "grape", 4);
    insert(table, "honeydew", 9);
    insert(table, "kiwi", 6);

    int searchResult = search(table, "banana");
    if (searchResult!= -1) {
        printf("Found banana with data %d\n", searchResult);
    } else {
        printf("Banana not found\n");
    }

    delete(table, "banana");

    searchResult = search(table, "banana");
    if (searchResult!= -1) {
        printf("Found banana with data %d\n", searchResult);
    } else {
        printf("Banana not found\n");
    }

    return 0;
}