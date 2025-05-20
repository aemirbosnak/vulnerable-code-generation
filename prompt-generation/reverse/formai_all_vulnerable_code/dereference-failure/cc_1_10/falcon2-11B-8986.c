//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of a linked list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from a linked list
void deleteNode(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
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

// Function to delete the entire linked list
void deleteList(struct node** head) {
    struct node* temp = *head;
    struct node* next;

    while (temp!= NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    struct node* head = NULL;

    // Inserting elements at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);

    // Printing the linked list
    printf("Linked list: ");
    printList(head);

    // Inserting elements at the end of the list
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 12);

    // Printing the linked list
    printf("Linked list: ");
    printList(head);

    // Deleting elements from the list
    deleteNode(&head, 8);
    deleteNode(&head, 5);
    deleteNode(&head, 6);
    deleteNode(&head, 7);

    // Printing the linked list
    printf("Linked list after deletion: ");
    printList(head);

    // Deleting the entire linked list
    deleteList(&head);

    return 0;
}