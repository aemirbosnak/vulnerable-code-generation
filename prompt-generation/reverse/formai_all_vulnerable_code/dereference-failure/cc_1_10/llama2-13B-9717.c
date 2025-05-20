//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of a linked list
void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
}

// Function to find the middle node of a linked list
struct Node* findMiddle(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    current = head;
    count /= 2;
    while (count-- > 0) {
        current = current->next;
    }
    return current;
}

// Function to reverse a linked list
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

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Delete the first node
    deleteFirst(&head);

    // Find the middle node
    struct Node* middle = findMiddle(head);
    printf("Middle node: %d\n", middle->data);

    // Reverse the linked list
    reverse(&head);

    // Print the linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}