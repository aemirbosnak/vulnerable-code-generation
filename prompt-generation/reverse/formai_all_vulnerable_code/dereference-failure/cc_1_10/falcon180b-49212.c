//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *key;
    int value;
} entry_t;

entry_t *entries = NULL;
int num_entries = 0;

void init() {
    entries = malloc(MAX_SIZE * sizeof(entry_t));
    memset(entries, 0, MAX_SIZE * sizeof(entry_t));
}

int hash(const char *key) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31) ^ (*key);
        key++;
    }
    return hash % MAX_SIZE;
}

void add(const char *key, int value) {
    int index = hash(key);
    while (entries[index].key) {
        index = (index + 1) % MAX_SIZE;
    }
    entries[index].key = strdup(key);
    entries[index].value = value;
    num_entries++;
}

int get(const char *key) {
    int index = hash(key);
    while (entries[index].key) {
        if (strcmp(entries[index].key, key) == 0) {
            return entries[index].value;
        }
        index = (index + 1) % MAX_SIZE;
    }
    return -1;
}

void print() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (entries[i].key) {
            printf("%s -> %d\n", entries[i].key, entries[i].value);
        }
    }
}

int main() {
    init();
    add("apple", 1);
    add("banana", 2);
    add("cherry", 3);
    print();
    printf("get banana: %d\n", get("banana"));
    printf("get orange: %d\n", get("orange"));
    return 0;
}