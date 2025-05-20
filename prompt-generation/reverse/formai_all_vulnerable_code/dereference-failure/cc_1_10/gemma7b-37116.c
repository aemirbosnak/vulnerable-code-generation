//Gemma-7B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOC 10

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *head = NULL;

void alloc_node(char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(MAX_ALLOC);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }

    strcpy(newNode->data, data);
}

void free_node(char *data) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr) {
        if (strcmp(curr->data, data) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr->data);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Error: data not found.\n");
}

int main() {
    alloc_node("John Doe");
    alloc_node("Jane Doe");
    alloc_node("Peter Pan");

    free_node("Jane Doe");

    printf("Head: %s\n", head->data);
    printf("Second node: %s\n", head->next->data);

    return 0;
}