//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Entry;

void insert(Entry *table[], int size, char *key, int value) {
    if (size == MAX_SIZE) {
        printf("Table is full\n");
        exit(1);
    }

    int i = 0;
    while (table[i]!= NULL && strcmp(table[i]->key, key) < 1) {
        i++;
    }

    table[i] = (Entry *)malloc(sizeof(Entry));
    table[i]->key = strdup(key);
    table[i]->value = value;
}

int search(Entry *table[], int size, char *key) {
    int i = 0;
    while (table[i]!= NULL && strcmp(table[i]->key, key) < 1) {
        i++;
    }

    if (table[i] == NULL) {
        return -1;
    }

    return table[i]->value;
}

void delete(Entry *table[], int size, char *key) {
    int i = 0;
    while (table[i]!= NULL && strcmp(table[i]->key, key) < 1) {
        i++;
    }

    if (table[i] == NULL) {
        printf("Key not found\n");
        return;
    }

    free(table[i]->key);
    free(table[i]);
    table[i] = NULL;
}

int main() {
    Entry *table[MAX_SIZE];
    int size = 0;

    insert(table, size, "apple", 5);
    insert(table, size, "banana", 3);
    insert(table, size, "cherry", 7);

    int value = search(table, size, "banana");
    printf("Value of banana: %d\n", value);

    delete(table, size, "banana");
    value = search(table, size, "banana");
    if (value == -1) {
        printf("Key not found\n");
    }

    return 0;
}