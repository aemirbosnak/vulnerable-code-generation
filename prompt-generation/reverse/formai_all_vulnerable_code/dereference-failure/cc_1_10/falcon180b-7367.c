//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void addNode(Node** head, char* data) {
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

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
    } else {
        Node* temp = head;
        while (temp!= NULL) {
            printf("%s -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    // Create an empty list
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, "Hello");
    addNode(&head, "World");
    addNode(&head, "!");

    // Print the list
    printList(head);

    // Free the memory used by the nodes
    Node* temp = head;
    while (temp!= NULL) {
        free(temp->data);
        free(temp);
        temp = temp->next;
    }

    return 0;
}