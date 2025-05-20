//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* previous = NULL;

    // If the list is empty
    if (current == NULL) return;

    // If the node to be deleted is the head
    if (current->data == key) {
        *head = current->next;
        free(current);
        return;
    }
    
    // Traverse the list to find the node to delete
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If the node was not found
    if (current == NULL) return;

    // Unlink the node from the linked list
    previous->next = current->next;
    free(current);
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node
        prev = current;       // Move pointers one position forward
        current = next;
    }
    *head = prev; // Update the head to new first node
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL; // Initialize the head of the list

    // Inserting elements into the linked list
    for (int i = 1; i <= 5; i++) {
        insertEnd(&head, i * 10); // Insert multiples of 10
    }

    printf("Original Linked List: ");
    displayList(head); // Display the list

    printf("Count of nodes: %d\n", countNodes(head)); // Count and display number of nodes

    printf("Reversing the Linked List...\n");
    reverseList(&head); // Reverse the linked list

    printf("Reversed Linked List: ");
    displayList(head); // Display the reversed list

    // Deleting elements from the linked list
    deleteNode(&head, 30); // Delete node with value 30
    printf("After Deleting 30: ");
    displayList(head); // Display the list after deletion

    deleteNode(&head, 10); // Delete node with value 10
    printf("After Deleting 10: ");
    displayList(head); // Display the list after deletion

    // Cleanup: free the remaining nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}