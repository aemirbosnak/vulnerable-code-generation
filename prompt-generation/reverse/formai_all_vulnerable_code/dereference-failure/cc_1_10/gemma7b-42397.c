//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initialize_memory(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX_MEMORY; i++) {
        Node* node = malloc(sizeof(Node));
        node->data = -1;
        node->next = NULL;
        *head = node;
        head = &node->next;
    }
}

void insert_node(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }

    head = &((*head)->next);
}

void traverse_nodes(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    initialize_memory(&head);
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    traverse_nodes(head);

    return 0;
}