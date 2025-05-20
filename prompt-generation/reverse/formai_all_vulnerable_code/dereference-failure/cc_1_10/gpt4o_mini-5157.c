//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a node in the linked list
struct Node {
    char data[100];
    struct Node* next;
};

// Function prototypes
struct Node* createNode(char* data);
void insertAtEnd(struct Node** head, char* data);
void deleteNode(struct Node** head, char* key);
void displayList(struct Node* node);
void freeList(struct Node* head);

// Function to create a new node
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node by key
void deleteNode(struct Node** head, char* key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && strcmp(temp->data, key) == 0) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free the memory
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    printf("Linked List Operations\n");
    printf("========================\n");

    // Insert elements
    insertAtEnd(&head, "Node 1");
    insertAtEnd(&head, "Node 2");
    insertAtEnd(&head, "Node 3");
    insertAtEnd(&head, "Node 4");

    printf("Current List: ");
    displayList(head);

    // Deleting a node
    printf("Deleting 'Node 2'\n");
    deleteNode(&head, "Node 2");
    printf("Updated List: ");
    displayList(head);

    // Inserting a new element
    insertAtEnd(&head, "Node 5");
    printf("After inserting 'Node 5': ");
    displayList(head);

    // Freeing the list
    freeList(head);
    printf("List freed. Exiting program.\n");

    return 0;
}