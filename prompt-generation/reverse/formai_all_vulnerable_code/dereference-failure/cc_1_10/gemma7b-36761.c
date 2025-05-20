//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
    char key[MAX_SIZE];
};

void insert(struct Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* lastNode = index->head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    index->size++;
}

char search(struct Index* index, char* key) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, key) == 0) {
            return current->data[0];
        }
        current = current->next;
    }

    return '\0';
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;
    strcpy(index->key, "Index Database");

    insert(index, "Alice");
    insert(index, "Bob");
    insert(index, "Charlie");

    char data = search(index, "Bob");
    if (data) {
        printf("Data of Bob: %c\n", data);
    } else {
        printf("Bob not found.\n");
    }

    return 0;
}