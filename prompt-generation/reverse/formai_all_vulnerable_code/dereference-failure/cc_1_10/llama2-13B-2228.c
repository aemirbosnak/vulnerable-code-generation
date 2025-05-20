//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
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
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
    return first_node;
}

// Function to find the first node with the given data
struct Node* find(struct Node** head_ref, int data) {
    while (*head_ref != NULL) {
        if ((*head_ref)->data == data) {
            return *head_ref;
        }
        head_ref = &((*head_ref)->next);
    }
    return NULL;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);

    // Remove the first node
    struct Node* first_node = removeFirst(&head);
    printList(head);

    // Find the first node with the data 2
    struct Node* node = find(&head, 2);
    printList(node);

    return 0;
}