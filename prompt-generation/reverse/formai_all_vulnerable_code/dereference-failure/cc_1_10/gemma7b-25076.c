//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node** buckets;
    int size;
    int bucketSize;
    int numBuckets;
};

void insert(struct Index* index, char* name) {
    int bucketIndex = hash(name, index->numBuckets);
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->buckets[bucketIndex] == NULL) {
        index->buckets[bucketIndex] = newNode;
    } else {
        Node* tail = index->buckets[bucketIndex];
        tail->next = newNode;
    }
}

int hash(char* name, int numBuckets) {
    int hashValue = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hashValue = (hashValue * 3) + name[i];
    }
    return hashValue % numBuckets;
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    index->buckets = NULL;
    index->size = 0;
    index->bucketSize = 10;
    index->numBuckets = 10;

    insert(index, "John Doe");
    insert(index, "Jane Doe");
    insert(index, "Peter Pan");

    Node* node = index->buckets[hash("John Doe", index->numBuckets)];
    printf("%s", node->name);

    return 0;
}