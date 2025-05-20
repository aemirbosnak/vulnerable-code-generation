//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to store the data
struct node {
    int key;
    int value;
    struct node *next;
};

// Function to search an element in the list
struct node* search(struct node* head, int key) {
    struct node* current = head;
    while (current != NULL && current->key != key) {
        current = current->next;
    }
    return current;
}

// Function to insert an element in the list
struct node* insert(struct node** head_ref, int key, int value) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return new_node;
}

// Function to print the list
void print(struct node* head) {
    while (head != NULL) {
        printf("%d -> %d\n", head->key, head->value);
        head = head->next;
    }
}

int main() {
    struct node* head = NULL;

    // Insert some elements
    insert(&head, 1, 10);
    insert(&head, 2, 20);
    insert(&head, 3, 30);
    insert(&head, 4, 40);

    // Search an element
    struct node* search_node = search(head, 3);
    if (search_node != NULL) {
        printf("Element found at position %d\n", search_node->key);
    } else {
        printf("Element not found\n");
    }

    // Print the list
    print(head);

    return 0;
}