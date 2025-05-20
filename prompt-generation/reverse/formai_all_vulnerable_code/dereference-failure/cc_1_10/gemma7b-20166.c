//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 100

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

struct Index {
    char *key;
    struct Node *node;
    struct Index *next;
};

void insert(struct Index **head, char *key, char *data) {
    struct Index *newIndex = (struct Index *)malloc(sizeof(struct Index));
    newIndex->key = strdup(key);
    newIndex->node = (struct Node *)malloc(sizeof(struct Node));
    newIndex->node->data = strdup(data);
    newIndex->next = NULL;

    if (*head == NULL) {
        *head = newIndex;
    } else {
        (*head)->next = newIndex;
    }
}

int search(struct Index *head, char *key) {
    while (head) {
        if (strcmp(key, head->key) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    struct Index *head = NULL;
    insert(&head, "a", "Alice");
    insert(&head, "b", "Bob");
    insert(&head, "c", "Charlie");

    if (search(head, "a") == 1) {
        printf("Alice found!\n");
    }

    return 0;
}