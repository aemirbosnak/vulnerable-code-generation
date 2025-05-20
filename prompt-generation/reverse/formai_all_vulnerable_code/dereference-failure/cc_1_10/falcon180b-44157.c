//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int value;
} Record;

typedef struct {
    Record *data;
    int size;
    int capacity;
} Index;

Index *createIndex(int capacity) {
    Index *index = (Index *) malloc(sizeof(Index));
    index->data = (Record *) malloc(capacity * sizeof(Record));
    index->size = 0;
    index->capacity = capacity;
    return index;
}

void destroyIndex(Index *index) {
    free(index->data);
    free(index);
}

int hash(int key, int capacity) {
    return key % capacity;
}

void insert(Index *index, int key, int value) {
    int indexKey = hash(key, index->capacity);
    int i = 0;
    while (i < index->size && index->data[i].key!= key) {
        i++;
    }
    if (i == index->size) {
        if (index->size >= index->capacity) {
            printf("Index is full. Cannot insert.\n");
            return;
        }
        index->data[index->size].key = key;
        index->data[index->size].value = value;
        index->size++;
    } else {
        index->data[i].value = value;
    }
}

int search(Index *index, int key) {
    int indexKey = hash(key, index->capacity);
    int i = 0;
    while (i < index->size && index->data[i].key!= key) {
        i++;
    }
    if (i == index->size) {
        return -1;
    } else {
        return index->data[i].value;
    }
}

int main() {
    Index *index = createIndex(10);
    insert(index, 1, 10);
    insert(index, 2, 20);
    insert(index, 3, 30);
    insert(index, 4, 40);
    insert(index, 5, 50);
    insert(index, 6, 60);
    insert(index, 7, 70);
    insert(index, 8, 80);
    insert(index, 9, 90);
    insert(index, 10, 100);

    printf("Search for key 5: %d\n", search(index, 5));
    printf("Search for key 11: %d\n", search(index, 11));

    destroyIndex(index);
    return 0;
}