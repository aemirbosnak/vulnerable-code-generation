//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertNode(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node in the list
void deleteNode(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty! :(");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! :(");
        return;
    }

    printf("Here's the list: \n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Delete the first node
    deleteNode(&head);

    // Print the list
    printList(head);

    return 0;
}