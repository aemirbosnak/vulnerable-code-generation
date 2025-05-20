//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} entry_t;

void insert(entry_t entries[], int count, char *key, int value) {
    if (count >= MAX_SIZE) {
        printf("Error: table is full\n");
        exit(1);
    }

    int i = 0;
    while (i < count && strcmp(entries[i].key, key) < 0) {
        i++;
    }

    for (int j = count; j > i; j--) {
        entries[j] = entries[j - 1];
    }

    entries[i] = (entry_t) {.key = strdup(key),.value = value };
    count++;
}

int search(entry_t entries[], int count, char *key) {
    int i = 0;
    while (i < count && strcmp(entries[i].key, key) < 0) {
        i++;
    }

    if (i == count || strcmp(entries[i].key, key)!= 0) {
        return -1;
    }

    return entries[i].value;
}

int main() {
    entry_t entries[MAX_SIZE];
    int count = 0;

    insert(entries, count, "apple", 1);
    insert(entries, count, "banana", 2);
    insert(entries, count, "cherry", 3);

    int value = search(entries, count, "banana");
    printf("Value of banana: %d\n", value);

    return 0;
}