//Falcon-180B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode!= NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && temp->data!= data) {
            temp = temp->next;
        }
        if (temp!= NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        Node* temp = head;
        while (temp!= NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 2);

    // Print the list again
    printf("List after deleting node with data 2:\n");
    printList(head);

    return 0;
}