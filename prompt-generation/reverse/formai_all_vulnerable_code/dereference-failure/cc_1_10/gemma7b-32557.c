//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_INDEX_ENTRIES 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Index {
    char index_key[MAX_NAME_LENGTH];
    int index_entry_number;
    struct Index* next;
} Index;

Node* CreateNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

Index* CreateIndex(char* key, int entryNumber) {
    Index* newIndex = (Index*)malloc(sizeof(Index));
    strcpy(newIndex->index_key, key);
    newIndex->index_entry_number = entryNumber;
    newIndex->next = NULL;
    return newIndex;
}

void InsertNode(Node** head, char* name) {
    Node* newNode = CreateNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void InsertIndexEntry(Index** head, char* key, int entryNumber) {
    Index* newIndex = CreateIndex(key, entryNumber);
    if (*head == NULL) {
        *head = newIndex;
    } else {
        (*head)->next = newIndex;
    }
}

void SearchIndex(Index* head, char* key) {
    while (head) {
        if (strcmp(head->index_key, key) == 0) {
            printf("Index entry number: %d\n", head->index_entry_number);
        }
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    Index* indexHead = NULL;

    InsertNode(&head, "John Doe");
    InsertNode(&head, "Jane Doe");
    InsertNode(&head, "Alice White");

    InsertIndexEntry(&indexHead, "John Doe", 1);
    InsertIndexEntry(&indexHead, "Jane Doe", 2);
    InsertIndexEntry(&indexHead, "Alice White", 3);

    SearchIndex(indexHead, "John Doe");

    return 0;
}