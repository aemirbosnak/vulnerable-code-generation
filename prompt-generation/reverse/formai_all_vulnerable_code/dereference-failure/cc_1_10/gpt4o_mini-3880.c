//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head_ref, int new_data) {
    // Create a new node
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    // If the linked list is empty, then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete a node by value from the linked list
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position forward
        current = next;
    }
    *head_ref = prev; // Change head to point to the new first node
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original linked list: ");
    printList(head);

    // Deleting a node
    printf("Deleting 30 from the linked list.\n");
    deleteNode(&head, 30);
    printf("Updated linked list: ");
    printList(head);

    // Reversing the linked list
    printf("Reversing the linked list.\n");
    reverseList(&head);
    printf("Reversed linked list: ");
    printList(head);

    // Cleaning up before exiting
    printf("Freeing up the linked list memory.\n");
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}