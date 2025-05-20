//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    int key;
    struct Node* head;
};

void insertNode(struct Index* index, char* name) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        struct Node* current = index->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void searchNode(struct Index* index, char* name) {
    struct Node* current = index->head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Node found: %s\n", current->name);
            return;
        }
        current = current->next;
    }
    printf("Node not found.\n");
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    index->key = 1;
    index->head = NULL;

    insertNode(index, "John Doe");
    insertNode(index, "Jane Doe");
    insertNode(index, "Peter Pan");

    searchNode(index, "Jane Doe");
    searchNode(index, "Peter Pan");

    return 0;
}