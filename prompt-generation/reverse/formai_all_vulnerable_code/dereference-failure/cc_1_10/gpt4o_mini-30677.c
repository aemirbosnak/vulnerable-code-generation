//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int key);
void displayList(Node* node);
void freeList(Node* head);
int searchNode(Node* head, int key);
void reverseList(Node** head);
void sortList(Node** head);

// Main function
int main() {
    Node* head = NULL; // Initialize the linked list

    // Insert elements at the end of the linked list
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    
    printf("Original list: ");
    displayList(head);
    
    // Search for a node in the list
    int key = 10;
    if (searchNode(head, key)) {
        printf("Node with data %d found in the list.\n", key);
    } else {
        printf("Node with data %d not found in the list.\n", key);
    }

    // Delete a node with a specific key
    deleteNode(&head, 15);
    printf("List after deleting node with data 15: ");
    displayList(head);

    // Reverse the linked list
    reverseList(&head);
    printf("Reversed list: ");
    displayList(head);
    
    // Sort the linked list
    sortList(&head);
    printf("Sorted list: ");
    displayList(head);
    
    // Free the list
    freeList(head);
    
    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with specific key
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Key not found
    prev->next = temp->next; // Unlink the node
    free(temp); // Free memory
}

// Function to display all nodes in the list
void displayList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to search for a node with a specific key
int searchNode(Node* head, int key) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key) {
            return 1; // Node found
        }
        curr = curr->next;
    }
    return 0; // Node not found
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    *head = prev; // Update head
}

// Function to sort the linked list
void sortList(Node** head) {
    if (*head == NULL) return;
    
    Node *current, *index;
    int temp;
    for (current = *head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}