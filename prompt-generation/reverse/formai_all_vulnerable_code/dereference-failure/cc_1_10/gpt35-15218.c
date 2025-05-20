//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create the head of the linked list and initialize it with NULL (empty list)
Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the end of the linked list
void addNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found.\n", data);
}

// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addNode(10); // Add 10 to the linked list
    addNode(20); // Add 20 to the linked list
    addNode(30); // Add 30 to the linked list
    displayList(); // Output: 10 20 30
    deleteNode(20); // Delete the node with data 20
    displayList(); // Output: 10 30
    deleteNode(40); // Delete the node with data 40 (not in the linked list)
    return 0;
}