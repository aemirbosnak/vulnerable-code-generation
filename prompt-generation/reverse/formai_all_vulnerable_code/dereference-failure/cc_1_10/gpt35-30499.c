//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the Linked List
struct node {
    int data;
    struct node* next;
};

// Function to insert a node at the beginning of the Linked List
void insertAtStart(struct node** head, int data) {
    // Create a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    // Set the data and next pointer of the new node
    newNode->data = data;
    newNode->next = *head;
    // Set the head of the Linked List to the new node
    *head = newNode;
    printf("%d inserted at the beginning of the Linked List!\n", data);
}

// Function to insert a node at the end of the Linked List
void insertAtEnd(struct node** head, int data) {
    // Create a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    // Set the data and next pointer of the new node
    newNode->data = data;
    newNode->next = NULL;
    // If the Linked List is empty, set the head of the Linked List to the new node
    if(*head == NULL) {
        *head = newNode;
        printf("%d inserted at the end of the Linked List!\n", data);
        return;
    }
    // Find the last node in the Linked List
    struct node* lastNode = *head;
    while(lastNode->next != NULL)
        lastNode = lastNode->next;
    // Set the next pointer of the last node to the new node
    lastNode->next = newNode;
    printf("%d inserted at the end of the Linked List!\n", data);
}

// Function to delete a node with a given value from the Linked List
void deleteNode(struct node** head, int key) {
    // If the Linked List is empty, return
    if(*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    // If the head of the Linked List contains the key, delete the head node
    if((*head)->data == key) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("%d deleted from the Linked List!\n", key);
        return;
    }
    // Find the node with the key and delete it
    struct node* currentNode = *head;
    struct node* prevNode = NULL;
    while(currentNode != NULL && currentNode->data != key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    // If the key is not found in the Linked List, return
    if(currentNode == NULL) {
        printf("%d not found in the Linked List!\n", key);
        return;
    }
    // Set the next pointer of the previous node to the next node of the current node
    prevNode->next = currentNode->next;
    free(currentNode);
    printf("%d deleted from the Linked List!\n", key);
}

// Function to display the contents of the Linked List
void displayLinkedList(struct node* head) {
    // If the Linked List is empty, return
    if(head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    // Traverse the Linked List and display the data of each node
    printf("Linked List: ");
    struct node* currentNode = head;
    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, data;
    while(1) {
        printf("1. Insert at start of Linked List\n");
        printf("2. Insert at end of Linked List\n");
        printf("3. Delete a node from Linked List\n");
        printf("4. Display Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data of the node to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayLinkedList(head);
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}