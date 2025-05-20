//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct IndexNode {
    int key;
    int address;
    struct IndexNode* next;
};

struct Index {
    int numNodes;
    struct IndexNode* head;
};

void printIndex(struct Index* index) {
    struct IndexNode* currentNode = index->head;
    printf("Index:\n");
    while (currentNode != NULL) {
        printf("Key: %d, Address: %d\n", currentNode->key, currentNode->address);
        currentNode = currentNode->next;
    }
}

void addNode(struct Index* index, int key, int address) {
    struct IndexNode* newNode = (struct IndexNode*) malloc(sizeof(struct IndexNode));
    newNode->key = key;
    newNode->address = address;
    newNode->next = NULL;
    
    if (index->head == NULL) {
        index->head = newNode;
    } else {
        struct IndexNode* currentNode = index->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    
    index->numNodes++;
}

void deleteNode(struct Index* index, int key) {
    struct IndexNode* previousNode = NULL;
    struct IndexNode* currentNode = index->head;

    while (currentNode != NULL && currentNode->key != key) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode != NULL) {
        if (previousNode == NULL) {
            index->head = currentNode->next;
        } else {
            previousNode->next = currentNode->next;
        }
        free(currentNode);
        index->numNodes--;
    }

}

int main() {
    struct Index index;
    index.numNodes = 0;
    index.head = NULL;
    
    addNode(&index, 10, 20);
    addNode(&index, 5, 25);
    addNode(&index, 12, 52);
    addNode(&index, 3, 72);

    printf("Before deletion:\n");
    printIndex(&index);

    printf("Deleting key 12...\n\n");
    deleteNode(&index, 12);

    printf("After deletion:\n");
    printIndex(&index);

    return 0;
}