//FormAI DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked-list node
struct Node {
    int data;
    struct Node* next;
};

// Initialize the head node of the linked list
struct Node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode; // If the linked list is empty, the head node is the new node
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Assign the next pointer of the last node to this new node
}

// Function to insert a new node at a given position in the linked list
void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete the first occurrence of a node with a given value in the linked list
void deleteNode(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node containing value %d not found!\n", value);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to print the contents of the linked list
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    int choice, value, position;

    while (1) {
        printf("\n----Linked List Operations Menu----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete node\n");
        printf("5. Print list\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            printf("Enter the position: ");
            scanf("%d", &position);
            insertAtPosition(value, position);
            break;
        case 4:
            printf("Enter the node value to be deleted: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 5:
            printf("The linked list is: ");
            printList();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}