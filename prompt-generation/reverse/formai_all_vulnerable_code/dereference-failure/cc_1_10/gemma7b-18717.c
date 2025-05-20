//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {

    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    // Greed Algorithm
    Node* current = head;
    Node* previous = NULL;
    while (current) {
        previous = current;
        current = current->next;
        if (previous->data < current->data) {
            insert(&head, current->data);
            previous->next = NULL;
        }
    }

    // Print the rearranged list
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}