//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    char key[MAX_SIZE];
    struct Node* node;
    struct Index* next;
};

void insertIndex(struct Index**, char*, struct Node*);

int main() {
    struct Index* head = NULL;
    struct Node* tail = NULL;

    insertIndex(&head, "John Doe", tail);
    insertIndex(&head, "Jane Doe", tail);
    insertIndex(&head, "Peter Pan", tail);

    struct Index* current = head;
    while (current) {
        printf("%s\n", current->node->name);
        current = current->next;
    }

    return 0;
}

void insertIndex(struct Index** head, char* key, struct Node* node) {
    struct Index* newIndex = (struct Index*)malloc(sizeof(struct Index));
    strcpy(newIndex->key, key);
    newIndex->node = node;
    newIndex->next = NULL;

    if (*head == NULL) {
        *head = newIndex;
    } else {
        struct Index* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newIndex;
    }
}