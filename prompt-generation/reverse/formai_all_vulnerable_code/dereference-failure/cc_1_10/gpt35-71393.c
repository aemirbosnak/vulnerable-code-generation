//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Definition of a linked list node */
struct Node {
    int data;
    struct Node *next;
};

/* Function to display the contents of the linked list */
void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/* Function to insert a new node at the beginning of the linked list */
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/* Function to insert a new node at the end of the linked list */
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    /* Creating an empty linked list */
    struct Node *head = NULL;

    /* Inserting nodes into the linked list */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);

    /* Displaying the contents of the linked list */
    display(head);

    return 0;
}