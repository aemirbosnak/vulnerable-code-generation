//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;                // The data value of the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node by its value
void deleteNode(struct Node** headRef, int value) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == value) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Function to search for a value in the linked list
int searchValue(struct Node* head, int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1; // Value found
        }
        temp = temp->next;
    }
    return 0; // Value not found
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    displayList(head); // Displays: 1 -> 2 -> 3 -> NULL

    // Insert nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    displayList(head); // Displays: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Delete a node with a specific value
    deleteNode(&head, 3);
    displayList(head); // Displays: 1 -> 2 -> 4 -> 5 -> NULL

    // Search for a value in the linked list
    int valueToSearch = 2;
    if (searchValue(head, valueToSearch)) {
        printf("Value %d found in the list.\n", valueToSearch);
    } else {
        printf("Value %d not found in the list.\n", valueToSearch);
    }

    // Clean up memory before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}