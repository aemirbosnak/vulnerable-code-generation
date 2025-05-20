//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
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

// Function to delete the first node from the list
struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
    return temp;
}

// Function to find the node with the given data in the list
struct Node* findNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to reverse the list
struct Node* reverseList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        struct Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head_ref = previous;
    return previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Delete the first node from the list
    struct Node* first_node = deleteFirst(&head);
    printf("Deleted first node: %d\n", first_node->data);

    // Find a node with a given data in the list
    struct Node* node = findNode(&head, 2);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node with data %d not found\n", 2);
    }

    // Reverse the list
    struct Node* reversed_head = reverseList(&head);
    printf("Reversed list: ");
    while (reversed_head != NULL) {
        printf("%d ", reversed_head->data);
        reversed_head = reversed_head->next;
    }
    printf("\n");

    return 0;
}