//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Create a few nodes
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 10;
    node1->next = NULL;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 20;
    node2->next = NULL;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 30;
    node3->next = NULL;

    // Link the nodes together
    head = node1;
    tail = node3;

    // Print the data of the nodes
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    // Insert a new node at the tail
    Node* node4 = (Node*)malloc(sizeof(Node));
    node4->data = 40;
    node4->next = NULL;

    tail->next = node4;
    tail = node4;

    // Print the data of the nodes after insertion
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    // Delete the first node
    head = node1;
    tail = node2;

    free(head);
    head = tail->next;

    // Print the data of the nodes after deletion
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}