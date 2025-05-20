//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at the start of the list
void insertStart(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with a specific value
void deleteNode(Node** head, int value) {
    Node* temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (prev == NULL) {
        *head = temp->next; // Node to delete is the head
    } else {
        prev->next = temp->next; // Bypass the node to delete
    }
    free(temp);
}

// Function to search for a node with a specific value
Node* search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    *head = prev; // Update head to the last processed node
}

// Demonstration of linked list operations
int main() {
    Node* head = NULL;

    printf("Mysterious Linked List Operations:\n");
    
    // Insert elements
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertStart(&head, 5);
    insertEnd(&head, 30);
    
    printf("Current List: ");
    displayList(head);

    // Search for elements
    int searchValue = 20;
    Node* foundNode = search(head, searchValue);
    if (foundNode) {
        printf("Found node with value: %d\n", foundNode->data);
    } else {
        printf("Node with value %d not found.\n", searchValue);
    }

    // Delete a node
    int deleteValue = 10;
    printf("Deleting node with value %d...\n", deleteValue);
    deleteNode(&head, deleteValue);
    
    printf("List after deletion: ");
    displayList(head);

    // Reverse the list
    printf("Reversing the list...\n");
    reverseList(&head);
    printf("Reversed List: ");
    displayList(head);

    // Clean up the linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}