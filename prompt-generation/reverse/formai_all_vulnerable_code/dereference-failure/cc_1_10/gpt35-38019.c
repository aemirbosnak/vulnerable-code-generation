//FormAI DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to delete the first node of the linked list
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty!");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty!");
        return NULL;
    }
    Node* current = head;
    Node* prev = head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
    return head;
}

int main() {
    Node* head = NULL; // Initialize an empty linked list
    head = insertAtBeginning(head, 10); // Insert nodes at the beginning
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtEnd(head, 40); // Insert nodes at the end
    head = insertAtEnd(head, 50);
    display(head); // Display the linked list
    head = deleteAtBeginning(head); // Delete the first node
    display(head); // Display the linked list after deletion
    head = deleteAtEnd(head); // Delete the last node
    display(head); // Display the linked list after deletion
    return 0;
}