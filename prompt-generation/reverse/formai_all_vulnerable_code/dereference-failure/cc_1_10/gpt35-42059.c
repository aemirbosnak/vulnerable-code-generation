//FormAI DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list data structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the head pointer to NULL 
struct Node* head = NULL;

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning of the list.\n", data);
}

// Function to insert a node at the end of a linked list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end of the list.\n", data);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end of the list.\n", data);
}

// Function to delete a node from a linked list
void delete(int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete %d.\n", data);
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", data);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list. Cannot delete.\n", data);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", data);
}

// Function to print the contents of a linked list
void printList() {
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtBeginning(5);
    insertAtBeginning(10);
    insertAtEnd(7);
    insertAtEnd(12);
    printList();
    delete(7);
    delete(15);
    printList();
    return 0;
}