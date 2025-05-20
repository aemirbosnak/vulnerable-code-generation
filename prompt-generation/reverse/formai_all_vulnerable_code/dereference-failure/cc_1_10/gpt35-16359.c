//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new node at the beginning of the list
void insertAtStart(Node** head, int data) {
    Node* newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
    printf("Inserted node with data %d at the beginning of the list.\n", data);
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newnode = createNode(data);
    Node* curr = *head;
    if (*head == NULL) {
        *head = newnode;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newnode;
    }
    printf("Inserted node with data %d at the end of the list.\n", data);
}

// Function to delete the node with the given data
void deleteNode(Node** head, int data) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Could not find a node with data %d in the list.\n", data);
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    printf("Deleted node with data %d from the list.\n", data);
}

// Function to print the nodes of the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;
    do {
        printf("Choose an operation to perform on the list:\n");
        printf("1. Insert a node at the beginning of the list.\n");
        printf("2. Insert a node at the end of the list.\n");
        printf("3. Delete a node from the list.\n");
        printf("4. Print the nodes of the list.\n");
        printf("5. Quit.\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                break;
            case 2:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data for the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}