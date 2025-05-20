//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    char keyword[MAX_SIZE];
    struct Node* head;
};

void insertNode(struct Index* index, char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        struct Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchNode(struct Index* index, char* keyword) {
    struct Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->name, keyword) == 0) {
            printf("Node found: %s\n", temp->name);
        }
        temp = temp->next;
    }
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    insertNode(index, "John Doe");
    insertNode(index, "Jane Doe");
    insertNode(index, "Peter Pan");
    searchNode(index, "Jane Doe");

    return 0;
}