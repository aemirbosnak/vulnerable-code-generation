//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEARCH_RESULTS 10

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void insertNode(Node **head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int searchNode(Node *head, char *query) {
    while (head) {
        if (strcmp(head->data, query) == 0) {
            return 1;
        } else if (strcmp(head->data, query) > 0) {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    Node *head = NULL;

    insertNode(&head, "Alice");
    insertNode(&head, "Bob");
    insertNode(&head, "Charlie");
    insertNode(&head, "Dave");
    insertNode(&head, "Eve");

    searchNode(head, "Bob");  // Output: 1
    searchNode(head, "Dave");  // Output: 1
    searchNode(head, "Fred");  // Output: 0

    return 0;
}