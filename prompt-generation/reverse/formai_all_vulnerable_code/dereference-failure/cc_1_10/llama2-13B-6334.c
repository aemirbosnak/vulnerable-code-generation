//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Declare a function to allocate memory for a node
struct Node* allocateNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Declare a function to deallocate memory for a node
void deallocateNode(struct Node** node) {
    if (*node != NULL) {
        free((*node)->next);
        free(*node);
        *node = NULL;
    }
}

// Declare a function to insert a node into a linked list
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = allocateNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Declare a function to print the contents of a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the contents of the list
    printList(head);

    // Deallocate the memory for the list
    deallocateNode(&head);

    return 0;
}