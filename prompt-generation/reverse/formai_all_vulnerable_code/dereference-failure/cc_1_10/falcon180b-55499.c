//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char *key;
    int value;
} Entry;

Entry *table = NULL;
int size = 0;

void init() {
    table = (Entry *) malloc(MAX_SIZE * sizeof(Entry));
    memset(table, 0, MAX_SIZE * sizeof(Entry));
    size = 0;
}

void insert(char *key, int value) {
    if (size >= MAX_SIZE) {
        printf("Table is full!\n");
        return;
    }

    table[size].key = strdup(key);
    table[size].value = value;

    size++;
}

int search(char *key) {
    int i = 0;
    while (i < size) {
        if (strcmp(table[i].key, key) == 0) {
            return table[i].value;
        }
        i++;
    }
    return -1;
}

void delete(char *key) {
    int i = 0;
    while (i < size) {
        if (strcmp(table[i].key, key) == 0) {
            free(table[i].key);
            table[i] = table[size - 1];
            size--;
            return;
        }
        i++;
    }
}

void print() {
    int i = 0;
    while (i < size) {
        printf("%s -> %d\n", table[i].key, table[i].value);
        i++;
    }
}

int main() {
    init();

    insert("apple", 1);
    insert("banana", 2);
    insert("cherry", 3);

    print();

    int value = search("banana");
    if (value == -1) {
        printf("Not found\n");
    } else {
        printf("Found: %d\n", value);
    }

    delete("banana");

    print();

    return 0;
}