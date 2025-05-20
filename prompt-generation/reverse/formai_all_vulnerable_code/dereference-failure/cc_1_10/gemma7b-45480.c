//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node* next;
};

// Insert a node at the end
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Print the linked list
void printList(struct node* head) {
    struct node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    // Insert some nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Print the linked list
    printList(head);

    // Free the memory
    struct node* current = head;
    while (current) {
        struct node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}