//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node structure
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new node with a given value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the current state of the linked list
void printList(Node* head) {
    printf("List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to add a new node with the given value to the end of the list
void addToEnd(Node** headPtr, int value) {
    Node* newNode = createNode(value);
    if (*headPtr == NULL) {
        *headPtr = newNode;
    } else {
        Node* current = *headPtr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete the first node with the given value from the list
void deleteNode(Node** headPtr, int value) {
    if (*headPtr == NULL) {
        printf("List is empty!\n");
    } else if ((*headPtr)->value == value) {
        Node* temp = *headPtr;
        *headPtr = (*headPtr)->next;
        free(temp);
    } else {
        Node* current = *headPtr;
        while (current->next != NULL && current->next->value != value) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Value not found!\n");
        } else {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

// Main program
int main() {
    Node* head = NULL;  // Start with an empty linked list

    // Add some nodes to the list
    addToEnd(&head, 5);
    addToEnd(&head, 2);
    addToEnd(&head, 8);
    addToEnd(&head, 3);
    printList(head);  // Should print "List: 5 -> 2 -> 8 -> 3 -> NULL"

    // Delete some nodes from the list
    deleteNode(&head, 2);
    deleteNode(&head, 5);
    deleteNode(&head, 6);  // Invalid value, should print "Value not found!"
    printList(head);  // Should print "List: 8 -> 3 -> NULL"

    // Add some more nodes to the list
    addToEnd(&head, 1);
    addToEnd(&head, 4);
    addToEnd(&head, 9);
    printList(head);  // Should print "List: 8 -> 3 -> 1 -> 4 -> 9 -> NULL"

    return 0;
}