//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void append(struct Node** head, int newData);
void insertAtBeginning(struct Node** head, int newData);
void insertAfter(struct Node* prev_node, int newData);
void deleteNode(struct Node** head, int key);
void printList(struct Node* node);
void freeList(struct Node** head);
void reverseList(struct Node** head);
void findMiddle(struct Node* head);

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    // Append some nodes
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("Initial Linked List: ");
    printList(head);

    // Insert at the beginning
    insertAtBeginning(&head, 5);
    printf("After inserting 5 at the beginning: ");
    printList(head);

    // Insert after the second node
    insertAfter(head->next, 25);
    printf("After inserting 25 after second node: ");
    printList(head);

    // Delete a node
    deleteNode(&head, 20);
    printf("After deleting node with data 20: ");
    printList(head);

    // Find the middle element of the linked list
    findMiddle(head);

    // Reverse the linked list
    reverseList(&head);
    printf("After reversing the linked list: ");
    printList(head);

    // Free the allocated memory
    freeList(&head);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the linked list
void append(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node after a given node
void insertAfter(struct Node* prev_node, int newData) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(newData);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

// Function to delete a node by its key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
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

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL; // Set head to NULL after freeing
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    *head = prev; // Change head pointer to point to the new first node
}

// Function to find the middle element of the linked list
void findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("The middle element is %d\n", slow->data);
    }
}