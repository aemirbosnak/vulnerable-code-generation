//FormAI DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new linked list node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the linked list
void prepend(Node** head, int data) {
    Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to insert a new node at the end of the linked list
void append(Node** head, int data) {
    Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
}

// Function to remove the first occurrence of a node with the given data
void removeNode(Node** head, int data) {
    Node* cur = *head;
    Node* prev = NULL;
    while (cur != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        return;
    }
    if (prev == NULL) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
}

// Function to print the contents of the linked list
void printList(Node* head) {
    printf("[");
    Node* cur = head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL) {
            printf(", ");
        }
        cur = cur->next;
    }
    printf("]\n");
}

// Example usage of the linked list data structure
int main() {
    Node* head = NULL;
    prepend(&head, 1);
    append(&head, 2);
    append(&head, 3);
    prepend(&head, 4);
    printList(head);
    removeNode(&head, 2);
    printList(head);
    return 0;
}