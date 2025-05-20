//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return; // Key was not present
    
    prev->next = temp->next; // Unlink the node from linked list
    free(temp); // Free memory
}

// Function to search for a node
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head; // Start from head
    while (current != NULL) {
        if (current->data == key)
            return current; // Found the key
        current = current->next;
    }
    return NULL; // Key not found
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL; // Start with an empty list

    // Inserting values into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Current Linked List: ");
    displayList(head);
  
    // Inserting more values
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    printf("After adding more values: ");
    displayList(head);
    
    // Searching for a value
    int key = 30;
    struct Node* foundNode = searchNode(head, key);
    if (foundNode)
        printf("Node with value %d found in the list.\n", key);
    else
        printf("Node with value %d not found in the list.\n", key);
    
    // Deleting a node
    printf("Deleting %d from the linked list.\n", key);
    deleteNode(&head, key);
    printf("Linked List after deletion: ");
    displayList(head);
    
    // Free the entire linked list before ending
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}