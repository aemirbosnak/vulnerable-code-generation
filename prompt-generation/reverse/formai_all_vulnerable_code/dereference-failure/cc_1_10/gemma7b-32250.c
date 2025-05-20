//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Index {
    int key;
    Node* head;
};

void insertIndex(struct Index* index, int key, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchIndex(struct Index* index, int key) {
    Node* temp = index->head;
    while (temp) {
        if (temp->data == key) {
            printf("Data: %d\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found.\n");
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    insertIndex(index, 10, 20);
    insertIndex(index, 20, 30);
    insertIndex(index, 30, 40);
    insertIndex(index, 40, 50);
    searchIndex(index, 20);
    searchIndex(index, 40);
    return 0;
}