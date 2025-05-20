//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char name[256];
    struct Node* next;
} Node;

struct IndexEntry {
    char keyword[256];
    int doc_id;
    struct IndexEntry* next;
};

void insertNode(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertIndexEntry(struct IndexEntry** head, char* keyword, int doc_id) {
    struct IndexEntry* newEntry = (struct IndexEntry*)malloc(sizeof(struct IndexEntry));
    strcpy(newEntry->keyword, keyword);
    newEntry->doc_id = doc_id;
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

int searchIndex(struct IndexEntry* head, char* keyword) {
    while (head) {
        if (strcmp(head->keyword, keyword) == 0) {
            return head->doc_id;
        }
        head = head->next;
    }

    return -1;
}

int main() {
    struct Node* head = NULL;
    insertNode(&head, "John Doe");
    insertNode(&head, "Jane Doe");
    insertNode(&head, "Bill Smith");

    struct IndexEntry* indexHead = NULL;
    insertIndexEntry(&indexHead, "John", 1);
    insertIndexEntry(&indexHead, "Jane", 2);
    insertIndexEntry(&indexHead, "Bill", 3);

    int doc_id = searchIndex(indexHead, "John");
    if (doc_id != -1) {
        printf("Document ID: %d\n", doc_id);
    } else {
        printf("No document found.\n");
    }

    return 0;
}