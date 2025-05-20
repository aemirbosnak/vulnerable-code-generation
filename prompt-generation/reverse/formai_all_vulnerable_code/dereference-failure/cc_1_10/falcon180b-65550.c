//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void addNode(struct Node** head, int data) {
    struct Node* node = newNode(data);
    struct Node* last = *head;

    if (*head == NULL) {
        *head = node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = node;
}

// Function to add a node at the beginning of the list
void addNodeAtBeginning(struct Node** head, int data) {
    struct Node* node = newNode(data);

    node->next = *head;
    *head = node;
}

// Function to add a node at a specific position in the list
void addNodeAtPosition(struct Node** head, int data, int pos) {
    struct Node* node = newNode(data);
    struct Node* temp = *head;
    int count = 1;

    if (pos == 1) {
        node->next = *head;
        *head = node;
        return;
    }

    while (temp!= NULL && count!= pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
        printf("Invalid position\n");
    else
        temp->next = node;
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

    if (temp == NULL)
        printf("Node not found\n");
    else {
        prev->next = temp->next;
        free(temp);
    }
}

// Function to display the list
void displayList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Add nodes
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);

    // Display the list
    printf("List after adding nodes:\n");
    displayList(head);

    // Add a node at the beginning
    addNodeAtBeginning(&head, 5);

    // Display the list
    printf("\nList after adding a node at the beginning:\n");
    displayList(head);

    // Add a node at a specific position
    addNodeAtPosition(&head, 25, 2);

    // Display the list
    printf("\nList after adding a node at a specific position:\n");
    displayList(head);

    // Delete a node
    deleteNode(&head, 30);

    // Display the list
    printf("\nList after deleting a node:\n");
    displayList(head);

    return 0;
}