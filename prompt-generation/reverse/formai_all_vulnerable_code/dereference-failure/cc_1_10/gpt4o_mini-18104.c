//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List Node
struct Node {
    int data;          // Data part of the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next; 
        free(temp);         
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);
}

// Function to search for an element in the list
struct Node* search(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value)
            return current; 
        current = current->next;
    }
    return NULL; 
}

// Function to display the contents of the list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list
int main() {
    struct Node* head = NULL; // Starting point of the linked list

    printf("Inserting elements at the beginning:\n");
    insertAtBeginning(&head, 10);
    displayList(head);
    insertAtBeginning(&head, 20);
    displayList(head);
    insertAtBeginning(&head, 30);
    displayList(head);

    printf("\nInserting elements at the end:\n");
    insertAtEnd(&head, 40);
    displayList(head);
    insertAtEnd(&head, 50);
    displayList(head);

    printf("\nSearching for an element (20):\n");
    struct Node* foundNode = search(head, 20);
    if (foundNode) {
        printf("Element %d found in the list.\n", foundNode->data);
    } else {
        printf("Element not found.\n");
    }

    printf("\nDeleting an element (20):\n");
    deleteNode(&head, 20);
    displayList(head);

    printf("\nFinal List:\n");
    displayList(head);

    // Free the allocated memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}