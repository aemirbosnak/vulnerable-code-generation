//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_INDEX_SIZE 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Index {
    char index[MAX_NAME_LENGTH];
    struct Index* next;
} Index;

Index* insertIndex(Index* head, char* name) {
    Index* newNode = (Index*)malloc(sizeof(Index));
    strcpy(newNode->index, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Index* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void searchIndex(Index* head, char* name) {
    Index* temp = head;
    while (temp) {
        if (strcmp(temp->index, name) == 0) {
            printf("Index found: %s\n", temp->index);
            return;
        }
        temp = temp->next;
    }

    printf("Index not found.\n");
}

int main() {
    Index* indexHead = NULL;

    insertIndex(indexHead, "Sir Robin");
    insertIndex(indexHead, "The Knight of the Round Table");
    insertIndex(indexHead, "The Black Knight");

    searchIndex(indexHead, "The Knight of the Round Table");

    return 0;
}