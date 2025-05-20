//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Check if the node to be deleted is the head
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to search for a node by value
int searchNode(struct Node* head, int value) {
    struct Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == value) {
            return position; // Return the position of the node
        }
        position++;
        current = current->next;
    }
    return -1; // Value not found
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    // Inserting nodes
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    displayList(head);

    // Searching for a value
    int searchValue = 20;
    int position = searchNode(head, searchValue);
    if (position != -1) {
        printf("Value %d found at position %d.\n", searchValue, position);
    } else {
        printf("Value %d not found in list.\n", searchValue);
    }

    // Deleting a node
    deleteNode(&head, 20);
    displayList(head);

    // Attempting to delete a non-existent node
    deleteNode(&head, 100);

    // Final display of the list
    displayList(head);

    return 0;
}