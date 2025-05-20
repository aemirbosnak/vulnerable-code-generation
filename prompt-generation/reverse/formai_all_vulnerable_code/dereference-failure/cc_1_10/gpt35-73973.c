//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Initialize the head pointer to NULL
Node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list by its value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("The Linked List is empty!\n");
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("The value %d does not exist in the Linked List!\n", value);
    }
}

// Function to display all the nodes in the linked list
void display() {
    if (head == NULL) {
        printf("The Linked List is empty!\n");
        return;
    }
    printf("The nodes in the Linked List are:\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Test the linked list operations
    printf("Inserting 5 at the beginning...\n");
    insertAtBeginning(5);
    display();

    printf("\nInserting 6 at the end...\n");
    insertAtEnd(6);
    display();

    printf("\nInserting 7 at the end...\n");
    insertAtEnd(7);
    display();

    printf("\nInserting 4 at the beginning...\n");
    insertAtBeginning(4);
    display();

    printf("\nDeleting 6 from the Linked List...\n");
    deleteByValue(6);
    display();

    printf("\nDeleting 3 from the Linked List...\n");
    deleteByValue(3);
    display();

    return 0;
}