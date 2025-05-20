//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insert(struct Index* index, char* name) {
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

void search(struct Index* index, char* name) {
    Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s\n", temp->name);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Name not found.\n");
    }
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insert(index, "John Doe");
    insert(index, "Jane Doe");
    insert(index, "Peter Pan");

    search(index, "Jane Doe");

    return 0;
}