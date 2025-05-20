//FormAI DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
// Welcome to my magnificent C Data Structures Visualization Example Program!
// Fasten your seatbelts and get ready for a colorful adventure!

#include <stdio.h>
#include <stdlib.h>

// First, let's create a struct that represents a node in a linked list.
struct Node {
    int data;           // data stored in the node
    struct Node* next;  // pointer to the next node in the list
};

// Next, let's define some helper functions for our linked list.
void printList(struct Node* node) {
    printf("[ ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("]\n");
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

// Finally, let's put it all together in a main function.
int main() {
    struct Node* head = NULL;

    // Let's add some nodes to our linked list.
    push(&head, 6);
    push(&head, 3);
    push(&head, 9);
    push(&head, 2);
    push(&head, 8);

    // Now let's print out our linked list and then delete it.
    printf("Here's our linked list: ");
    printList(head);
    printf("Now we'll delete the list...\n");
    deleteList(&head);
    printf("The list has been deleted!\n");

    return 0;
}