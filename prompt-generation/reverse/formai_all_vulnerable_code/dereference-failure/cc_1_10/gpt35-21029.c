//FormAI DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the linked list structure
struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the linked list
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Print the linked list
    printf("Original Linked List:\n");
    printList(head);

    // Insert a node at the beginning of the linked list
    struct node* newHead = NULL;
    newHead = (struct node*)malloc(sizeof(struct node));

    newHead->data = 50;
    newHead->next = head;

    // Print the updated linked list
    printf("Linked List after Insertion at beginning:\n");
    printList(newHead);

    // Delete a node from the linked list
    newHead->next = third;

    // Print the updated linked list after deletion
    printf("Linked List after Deletion:\n");
    printList(newHead);

    // Free the memory allocated to the linked list
    free(head);
    free(second);
    free(third);
    free(newHead);

    return 0;
}