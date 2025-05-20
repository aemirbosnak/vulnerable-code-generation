//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
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

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node after a given position
void addNode(struct Node **head_ref, int new_data, int position) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;
    struct Node* prev_node = NULL;

    if (*head_ref == NULL || position == 0) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last!= NULL && position-- > 0) {
        prev_node = last;
        last = last->next;
    }

    if (last == NULL) {
        printf("Position out of range");
        return;
    }

    prev_node->next = new_node;
    new_node->next = last;

    return;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    new_node->next = NULL;

    return;
}

// Function to delete a node at a given position
void deleteNode(struct Node **head_ref, int position) {
    struct Node* temp = *head_ref;
    struct Node* prev_node = NULL;

    if (*head_ref == NULL)
        return;

    if (position == 0) {
        temp = temp->next;
        *head_ref = temp;
        free(temp);
        return;
    }

    while (temp!= NULL && position-- > 0) {
        prev_node = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev_node->next = temp->next;
    free(temp);

    return;
}

// Function to display the contents of the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Add 7 to the beginning.
    push(&head, 7);

    // Add 1 at the end.
    append(&head, 1);

    // Add 6 at position 2.
    addNode(&head, 6, 2);

    // Display the list.
    printf("Created Linked List: ");
    printList(head);

    // Delete node which has data as 7.
    deleteNode(&head, 7);

    // Display the modified list.
    printf("\nLinked List after deleting first node: ");
    printList(head);

    return 0;
}