//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertAtFront(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int value) {
    struct Node* temp = *head_ref, *prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head_ref = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Value not found
    prev->next = temp->next; // Unlink the node
    free(temp);
}

// Function to search for a node
int searchNode(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;
    
    // Inserting nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtFront(&head, 5);
    insertAtEnd(&head, 30);

    // Displaying the list
    printf("Current Linked List: ");
    displayList(head);

    // Searching for a node
    int searchValue = 20;
    if (searchNode(head, searchValue)) {
        printf("Value %d found in the list.\n", searchValue);
    } else {
        printf("Value %d not found in the list.\n", searchValue);
    }

    // Deleting a node
    int deleteValue = 10;
    printf("Deleting value %d from the list...\n", deleteValue);
    deleteNode(&head, deleteValue);
    printf("Linked List after deleting %d: ", deleteValue);
    displayList(head);

    // Free memory (to avoid memory leak)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}