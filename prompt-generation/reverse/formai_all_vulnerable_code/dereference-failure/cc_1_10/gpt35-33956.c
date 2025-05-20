//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct IndexNode {
    int data;
    int index;
};

struct Index {
    struct IndexNode *nodes;
    int size;
};

struct Index* createIndex(int size) {
    struct Index *index = (struct Index*) malloc(sizeof(struct Index));
    index->size = size;
    index->nodes = (struct IndexNode*) malloc(size * sizeof(struct IndexNode));
    return index;
}

void insert(struct Index *index, int data) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (index->nodes[i].index == -1) { // Found an empty spot
            index->nodes[i].data = data;
            index->nodes[i].index = i;
            break;
        }
    }
}

int search(struct Index *index, int data) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (index->nodes[i].data == data) {
            return index->nodes[i].index;
        }
    }
    return -1; // Not found
}

int delete(struct Index *index, int data) {
    int i, indexToBeDeleted;
    indexToBeDeleted = search(index, data);
    if (indexToBeDeleted == -1) { // Not found
        return -1;
    }
    index->nodes[indexToBeDeleted].data = -1; // Mark as deleted
    return indexToBeDeleted;
}

void printIndex(struct Index *index) {
    int i;
    for (i = 0; i < index->size; i++) {
        printf("%d:%d ", index->nodes[i].index, index->nodes[i].data);
    }
    printf("\n");
}

int main() {
    struct Index *index = createIndex(10);
    int i;
    for (i = 0; i < index->size; i++) {
        index->nodes[i].index = -1; // Mark all as empty
    }
    insert(index, 23);
    insert(index, 57);
    insert(index, 31);
    printIndex(index);
    printf("%d\n", search(index, 57));
    delete(index, 57);
    printIndex(index);
    printf("%d\n", search(index, 57));
    free(index->nodes);
    free(index);
    return 0;
}