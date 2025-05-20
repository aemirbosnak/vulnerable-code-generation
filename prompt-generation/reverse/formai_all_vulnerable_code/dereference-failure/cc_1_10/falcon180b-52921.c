//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Function prototypes
void createList(struct node** head);
int search(struct node* head, int key);
void printList(struct node* node);

int main() {
    struct node* head = NULL;

    // Create linked list
    createList(&head);

    // Search for a node
    int key = 7;
    struct node* foundNode = search(head, key);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Print the found node (or a message if not found)
    if (foundNode!= NULL) {
        printf("\nFound node with data: %d", foundNode->data);
    } else {
        printf("\nNode not found.");
    }

    return 0;
}

// Function to create a linked list with 10 nodes
void createList(struct node** head) {
    *head = (struct node*) malloc(sizeof(struct node));
    (*head)->data = 1;
    (*head)->next = NULL;

    struct node* temp = *head;
    for (int i = 2; i <= 10; i++) {
        temp->next = (struct node*) malloc(sizeof(struct node));
        temp->next->data = i;
        temp->next->next = NULL;
        temp = temp->next;
    }
}

// Function to search for a node with the given key
int search(struct node* head, int key) {
    struct node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to print the linked list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}