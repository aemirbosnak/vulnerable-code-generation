//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the data to be searched
struct node {
    int key;
    int value;
    struct node* next;
};

// Function to search an element in the list
struct node* search(struct node* head, int key) {
    struct node* current = head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to insert an element in the list
struct node* insert(struct node** head_ref, int key, int value) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

// Function to print the list
void print_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> %d\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;

    // Insert some elements into the list
    insert(&head, 1, 10);
    insert(&head, 2, 20);
    insert(&head, 3, 30);
    insert(&head, 4, 40);

    // Search an element in the list
    struct node* search_node = search(head, 2);
    if (search_node != NULL) {
        printf("Element found at position %d\n", search_node->key);
    } else {
        printf("Element not found\n");
    }

    // Print the list
    print_list(head);

    return 0;
}