//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the linked list
void deleteFirst(struct Node** head_ref) {
    if (*head_ref != NULL) {
        struct Node* first_node = *head_ref;
        *head_ref = first_node->next;
        free(first_node);
    }
}

// Function to search for a specific node in the linked list
struct Node* search(struct Node* head, int data) {
    while (head != NULL && head->data != data) {
        head = head->next;
    }
    return head;
}

// Function to reverse the linked list
void reverse(struct Node** head_ref) {
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

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    deleteFirst(&head);

    struct Node* found = search(head, 2);
    if (found != NULL) {
        printf("Found node with value %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    reverse(&head);

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}