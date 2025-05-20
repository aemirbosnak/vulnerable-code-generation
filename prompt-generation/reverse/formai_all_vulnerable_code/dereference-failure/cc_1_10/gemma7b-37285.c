//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct IndexTree {
    int size;
    Node** buckets;
    struct IndexTree* next;
};

struct IndexTree* insert(struct IndexTree* tree, char* data) {
    int hash = hashFunction(data);
    if (tree == NULL) {
        tree = malloc(sizeof(struct IndexTree));
        tree->size = 1;
        tree->buckets = malloc(MAX_SIZE * sizeof(Node*));
        for (int i = 0; i < MAX_SIZE; i++) {
            tree->buckets[i] = NULL;
        }
    } else if (tree->buckets[hash] == NULL) {
        tree->buckets[hash] = malloc(sizeof(Node));
        tree->buckets[hash]->next = NULL;
        tree->buckets[hash]->data[0] = '\0';
        tree->size++;
    }
    Node* newNode = tree->buckets[hash]->next;
    tree->buckets[hash]->next = newNode;
    newNode->data[0] = '\0';
    strcpy(newNode->data, data);
    return tree;
}

char* search(struct IndexTree* tree, char* data) {
    int hash = hashFunction(data);
    for (Node* node = tree->buckets[hash]; node; node = node->next) {
        if (strcmp(node->data, data) == 0) {
            return node->data;
        }
    }
    return NULL;
}

int hashFunction(char* str) {
    return (int) str[0] % MAX_SIZE;
}

int main() {
    struct IndexTree* tree = NULL;
    insert(tree, "John Doe");
    insert(tree, "Jane Doe");
    insert(tree, "Peter Pan");
    insert(tree, "Mary Poppins");
    insert(tree, "The Cat in the Hat");

    char* result = search(tree, "Jane Doe");
    if (result) {
        printf("%s\n", result);
    } else {
        printf("Data not found\n");
    }

    return 0;
}