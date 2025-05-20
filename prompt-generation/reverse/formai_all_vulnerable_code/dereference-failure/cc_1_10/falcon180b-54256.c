//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of a linked list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a value in a linked list
Node* searchList(Node* head, int value) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node from a linked list
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    // Create a linked list with initial values
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the initial list
    printf("Initial list:\n");
    printList(head);

    // Search for a value in the list
    Node* foundNode = searchList(head, 4);
    if (foundNode!= NULL) {
        printf("Found node with value %d\n", foundNode->data);
    } else {
        printf("Value not found in the list\n");
    }

    // Delete a node from the list
    deleteNode(&head, 3);

    // Print the updated list
    printf("Updated list:\n");
    printList(head);

    return 0;
}