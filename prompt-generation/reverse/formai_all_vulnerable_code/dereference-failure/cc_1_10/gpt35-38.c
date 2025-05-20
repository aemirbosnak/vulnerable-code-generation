//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

int main() {
    struct node* head = NULL;

    // Add elements to the beginning of the linked list
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Display the linked list
    printf("Linked List after adding elements at the beginning: ");
    printList(head);
    printf("\n");

    // Add elements to the end of the linked list
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Display the linked list
    printf("Linked List after adding elements at the end: ");
    printList(head);
    printf("\n");

    return 0;
}