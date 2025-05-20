//Gemma-7B DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertionSort(Node** head) {
    Node* current = *head;
    Node* sorted = NULL;

    while (current) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = current->data;
        newNode->next = NULL;

        if (sorted) {
            current->next = sorted;
            sorted = newNode;
        } else {
            *head = newNode;
            sorted = newNode;
        }
        current = current->next;
    }

    *head = sorted;
}

int main() {
    Node* head = NULL;

    // Create a few nodes
    Node* node1 = malloc(sizeof(Node));
    node1->data = 4;
    node1->next = NULL;

    Node* node2 = malloc(sizeof(Node));
    node2->data = 2;
    node2->next = NULL;

    Node* node3 = malloc(sizeof(Node));
    node3->data = 8;
    node3->next = NULL;

    Node* node4 = malloc(sizeof(Node));
    node4->data = 6;
    node4->next = NULL;

    // Link the nodes together
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Sort the nodes
    insertionSort(&head);

    // Print the sorted nodes
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}