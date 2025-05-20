//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void printNode(Node* node) {
    printf(" %d -> ", node->data);
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printNode(current);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* current = NULL;

    // Insert nodes into the list
    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    current = tail->next;
    current->prev = tail;
    tail->next = current;
    current->data = 2;

    current = current->next;
    current->prev = current;
    current->data = 3;

    current = current->next;
    current->prev = current;
    current->data = 4;

    current = current->next;
    current->prev = current;
    current->data = 5;

    // Visualize the list
    printf("Doubly Linked List: \n");
    printf("-------------------------------------\n");
    printList(head);
    printf("\n");

    return 0;
}