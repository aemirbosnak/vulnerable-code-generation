//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* node = newNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = node;
    return;
}

// Function to delete a node with given data
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
    return;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the list
    printf("Initial List:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, 3);

    // Print the list after deletion
    printf("List after deleting 3:\n");
    printList(head);

    // Insert more nodes
    insertNode(&head, 6);
    insertNode(&head, 7);

    // Print the final list
    printf("Final List:\n");
    printList(head);

    return 0;
}