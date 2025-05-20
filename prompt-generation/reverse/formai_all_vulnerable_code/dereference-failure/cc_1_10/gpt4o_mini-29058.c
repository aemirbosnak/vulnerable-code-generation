//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
void displayList(struct Node* node);
void findTreasure(struct Node* head);

int main() {
    struct Node* head = NULL;  // Starting point of the treasure map

    // The mystery begins by inserting clues (nodes)
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    // Display the current clues on the map
    printf("The clues on the treasure map:\n");
    displayList(head);
    
    // A clue was false; we need to remove it!
    printf("\nRemoving clue 20...\n");
    deleteNode(&head, 20);

    // Display the updated clues
    printf("The map after removing the false clue:\n");
    displayList(head);

    // Maybe the treasure lies within? Let’s search!
    printf("\nSearching for the treasure (value 30) on the map...\n");
    findTreasure(head);

    // The journey continues as we add more clues
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    
    // Final display of the treasure map
    printf("\nThe final clues on the treasure map:\n");
    displayList(head);
    
    // Releasing the treasure map (Freeing the linked list)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
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

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free the old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the linked list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free the memory
}

// Function to display the entire linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to search for the treasure
void findTreasure(struct Node* head) {
    int treasure = 30; // The mythical treasure we seek
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == treasure) {
            printf("Treasure found! It was at clue %d.\n", treasure);
            return;
        }
        current = current->next;
    }
    printf("The treasure is not on this map.\n");
}