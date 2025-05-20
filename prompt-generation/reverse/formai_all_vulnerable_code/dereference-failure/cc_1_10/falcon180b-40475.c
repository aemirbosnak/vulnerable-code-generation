//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to append a node at the end of the list
void append(struct Node** head, int data) {
    struct Node* node = newNode(data);
    struct Node* last = *head;

    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = node;
    return;
}

// Function to insert a node at the beginning of the list
void prepend(struct Node** head, int data) {
    struct Node* node = newNode(data);

    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }

    node->next = *head;
    *head = node;
    return;
}

// Function to delete a node with the given data
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
    return;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    prepend(&head, 5);
    prepend(&head, 4);
    prepend(&head, 3);
    prepend(&head, 2);
    prepend(&head, 1);

    printf("Created Linked List: ");
    printList(head);

    deleteNode(&head, 5);
    deleteNode(&head, 10);

    printf("\nLinked List after deleting nodes with value 5 and 10: ");
    printList(head);

    return 0;
}