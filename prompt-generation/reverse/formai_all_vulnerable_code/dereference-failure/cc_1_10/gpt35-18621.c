//FormAI DATASET v1.0 Category: Linked list operations ; Style: excited
// Woohoo! I'm so excited to show you my C Linked list program.
// This program has all the operations you need to manipulate and get the most out of a linked list
// Brace yourself because it's going to be awesome!
#include<stdio.h>
#include<stdlib.h>

// Alright, let's create our node structure. This structure will hold a value and a reference to the next node.
struct Node {
    int val;
    struct Node* next;
};

// Now let's implement our insert function. This function will add a new node to the beginning of the linked list.
void insert(struct Node** head, int value) {
    // First, let's create a new node with the value we want to add.
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = value;
    new_node->next = (*head);
    // If the list is already populated, the head will now point to the new node.
    (*head) = new_node;
    printf("Added %d to the linked list!\n", value);
}

// The next operation we have is the search operation. This operation will search the linked list for a particular value and return its corresponding node.
struct Node* search(struct Node* head, int value) {
    // We will iterate through the list to find the node that matches the given value.
    struct Node* current_node = head;
    while (current_node != NULL) {
        if (current_node->val == value) {
            printf("Found node with value %d!\n", value);
            return current_node;
        }
        current_node = current_node->next;
    }
    printf("Node with value %d doesn't exist!\n", value);
    return NULL;
}

// The third operation we have is the delete operation. This operation will remove a node from the linked list by referencing the value it holds.
void delete(struct Node** head, int value) {
    struct Node* current_node = *head;
    struct Node* prev_node = NULL;
    // We will iterate through the list to find the node with the given value.
    while (current_node != NULL && current_node->val != value) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    // If there's no node with the given value we'll output a message saying so.
    if (current_node == NULL) {
        printf("There's no node with value %d in the list!\n", value);
        return;
    }
    // If the node we're deleting is the head we will move the head to the next node.
    if (prev_node == NULL) {
        *head = current_node->next;
    } else {
        // Otherwise, we will change the reference of the previous node to the next node.
        prev_node->next = current_node->next;
    }
    // Free the memory allocated for the node.
    free(current_node);
    printf("Node with value %d was deleted!\n", value);
}

// Lastly, we need to create a print function to visualize the list again.
void print(struct Node* head) {
    printf("Linked list: ");
    struct Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->val);
        current_node = current_node->next;
    }
    printf("\n");
}

// Let's test everything out with main.
int main() {
    struct Node* head = NULL;
    // Populating the list.
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    print(head);
    // Testing search functionality.
    search(head, 3);
    search(head, 6);
    // Deleting nodes.
    delete(&head, 3);
    print(head);
    delete(&head, 10);
    // Freeing memory
    struct Node* current_node = head;
    while (current_node != NULL) {
        struct Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    // This has been an amazing journey! Thank you for witnessing my C linked list program!
    return 0;
}