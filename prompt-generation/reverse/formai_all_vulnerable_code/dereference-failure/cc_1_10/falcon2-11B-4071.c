//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct node {
    int data;
    struct node* next;
};

// Function prototypes
void insert(struct node**, int);
void delete(struct node**, int);
void printList(struct node*);

// Main function
int main() {
    struct node* head = NULL;
    struct node* temp;

    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);

    printf("Original list: ");
    printList(head);

    printf("\nDeleting 10...");
    delete(&head, 10);

    printf("\nUpdated list: ");
    printList(head);

    return 0;
}

// Function to insert a node at the beginning of the linked list
void insert(struct node** head_ref, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete a node from the linked list
void delete(struct node** head_ref, int data) {
    struct node* temp = *head_ref;
    struct node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list\n");
        return;
    }

    if (prev == NULL) {
        *head_ref = temp->next;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}