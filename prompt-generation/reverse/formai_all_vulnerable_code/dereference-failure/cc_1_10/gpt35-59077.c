//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure containing data and pointer to next node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Global variables for head and current node
Node *head = NULL;
Node *current = NULL;

// Function prototypes
void insertBeginning(int data);
void insertEnd(int data);
void insertAfter(int key, int data);
void deleteNode(int key);
void printList();

// Main function
int main() {
    int choice, data, key;
    do {
        // Menu to choose an operation
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Delete a node\n");
        printf("5. Print the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the chosen operation
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter the key to insert after: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAfter(key, data);
                break;
            case 4:
                printf("Enter the key of the node to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 5:
                printList();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to insert a node at the beginning of the list
void insertBeginning(int data) {
    // Create a new node
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // Set head and current node pointers
    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Function to insert a node at the end of the list
void insertEnd(int data) {
    // Create a new node
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // Set head and current node pointers
    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        current->next = newNode;
        current = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Function to insert a node after a given node
void insertAfter(int key, int data) {
    // Traverse the list to find the key node
    Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key node not found!\n");
        return;
    }

    // Create a new node
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully!\n");
}

// Function to delete a node with given key
void deleteNode(int key) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If head node itself holds the key to be deleted
    if (head->data == key) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }

    // Traverse the list to find the key node
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Key node not found!\n");
        return;
    }

    // Delete the key node
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    printf("Node deleted successfully!\n");
}

// Function to print the list
void printList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}