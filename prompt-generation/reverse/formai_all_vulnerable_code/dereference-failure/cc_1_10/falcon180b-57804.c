//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int index;
    char *value;
} Pair;

void insert(Pair **table, int size, int index, char *value) {
    if (size == 0) {
        size = MAX_SIZE;
        *table = (Pair *) malloc(size * sizeof(Pair));
    }

    if (size == MAX_SIZE) {
        printf("Error: Table is full!\n");
        return;
    }

    memmove(&(*table)[index + 1], &(*table)[index], (size - index) * sizeof(Pair));

    (*table)[index].index = index;
    (*table)[index].value = value;

    size++;
}

Pair *search(Pair *table, int size, int index) {
    while (index < size) {
        if (table[index].index == index) {
            return &table[index];
        }
        index++;
    }
    return NULL;
}

int main() {
    Pair *table = NULL;
    int size = 0;

    insert(&table, size, 1, "apple");
    insert(&table, size, 2, "banana");
    insert(&table, size, 3, "cherry");

    Pair *result = search(table, size, 2);

    if (result!= NULL) {
        printf("Value at index %d: %s\n", result->index, result->value);
    } else {
        printf("Value not found!\n");
    }

    free(table);
    return 0;
}