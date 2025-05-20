//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to remove the first node from the list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    struct Node* current = *head_ref;
    *head_ref = current->next;
    free(current);
}

// Function to find the node with the given value and return its address
struct Node* findNode(struct Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        struct Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head_ref = previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Remove the first node from the list
    removeFirst(&head);

    // Find the node with the value 2 and print its address
    struct Node* node = findNode(head, 2);
    if (node != NULL) {
        printf("Node with value 2 found at address %p\n", node);
    } else {
        printf("Node with value 2 not found\n");
    }

    // Reverse the list
    reverseList(&head);

    // Print the reversed list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}