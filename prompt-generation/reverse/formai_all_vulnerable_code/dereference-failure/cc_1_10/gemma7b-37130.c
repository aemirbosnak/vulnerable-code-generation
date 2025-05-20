//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

typedef struct node {
    int data;
    struct node* next;
} node;

node* insertAtTail(node* head, int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void displayList(node* head) {
    node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    node* head = NULL;

    // Inserting at the tail
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    // Displaying the linked list
    displayList(head);

    // Shifting the shape
    head = insertAtTail(head, 60);
    displayList(head);

    // Removing the last node
    head = insertAtTail(head, 70);
    displayList(head);

    return 0;
}