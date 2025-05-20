//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtHead(struct Node** head_ref, int new_data);
void insertAtTail(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
void displayList(struct Node* node);
void searchList(struct Node* head, int key);
void freeList(struct Node* head);

// Main function
int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    // Displaying the linked list
    printf("Linked List: ");
    displayList(head);

    // Searching for elements
    searchList(head, 3);
    searchList(head, 6);

    // Deleting a node
    printf("Deleting element 3\n");
    deleteNode(&head, 3);
    
    // Displaying after deletion
    printf("Linked List after deletion: ");
    displayList(head);

    // Freeing the list memory
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

// Function to insert a node at the head
void insertAtHead(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("Inserted %d at the head\n", new_data);
}

// Function to insert a node at the tail
void insertAtTail(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("Inserted %d at the tail (also head)\n", new_data);
        return;
    }
    
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    printf("Inserted %d at the tail\n", new_data);
}

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Change head
        free(temp); // Free old head
        printf("%d deleted\n", key);
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("%d deleted\n", key);
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to search an element in the linked list
void searchList(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("%d found in the list\n", key);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list\n", key);
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory freed\n");
}