//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head_ref, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
void printList(struct Node* node);
struct Node* searchNode(struct Node* head, int key);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;
    
    // Insert nodes
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 15);
    
    printf("Linked List: ");
    printList(head);
    
    // Searching a node
    int searchKey = 10;
    struct Node* foundNode = searchNode(head, searchKey);
    if (foundNode != NULL) {
        printf("Node with value %d found.\n", foundNode->data);
    } else {
        printf("Node with value %d not found.\n", searchKey);
    }
    
    // Deleting a node
    printf("Deleting node with value 10.\n");
    deleteNode(&head, 10);
    
    printf("Linked List after deletion: ");
    printList(head);
    
    // Free the memory allocated for the list
    freeList(head);
    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Insertion at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
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

// Deleting a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;
    
    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // Key was not present in the list
    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

// Printing the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Searching for a node with a specific key
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Freeing the allocated memory for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}