//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
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

// Function to append a node to the list
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete a node with a given value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* node) {
    printf("\nCurrent List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to visualize list operations
void visualizeListOperations() {
    struct Node* head = NULL;
    
    printf("\033[1;34mAdding nodes:\033[0m\n");
    for (int i = 1; i <= 5; i++) {
        appendNode(&head, i);
        printf("Added %d", i);
        displayList(head);
    }

    printf("\033[1;33mDeleting nodes:\033[0m\n");
    deleteNode(&head, 3);
    printf("Deleted 3");
    displayList(head);
    
    deleteNode(&head, 1);
    printf("Deleted 1");
    displayList(head);

    printf("\033[1;31mFinalizing list visualization:\033[0m\n");
    while (head != NULL) {
        printf("Removing %d\n", head->data);
        deleteNode(&head, head->data);
        displayList(head);
    }
    
    printf("All nodes removed!\n");
}

// Entry point of the program
int main() {
    visualizeListOperations();
    return 0;
}