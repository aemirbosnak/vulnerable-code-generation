//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 10

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insertIndex(struct Index* index, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
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
    index->size++;
}

int searchIndex(struct Index* index, char name[]) {
    Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    if (searchIndex(index, "Jane Doe") == 1) {
        printf("Jane Doe is in the index.\n");
    }

    return 0;
}