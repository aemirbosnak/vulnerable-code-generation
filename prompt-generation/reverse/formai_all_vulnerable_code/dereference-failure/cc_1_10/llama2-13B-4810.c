//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node struct for the database
struct node {
    int key;
    char value[50];
    struct node* next;
};

// Function to insert a record into the database
void insert(struct node** head_ref, int key, char value[]) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to search for a record in the database
struct node* search(struct node* head, int key) {
    struct node* current = head;
    while (current != NULL && current->key != key) {
        current = current->next;
    }
    return current;
}

// Function to delete a record from the database
void delete(struct node** head_ref, int key) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to traverse the database
void traverse(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;

    // Insert some records
    insert(&head, 1, "apple");
    insert(&head, 2, "banana");
    insert(&head, 3, "cherry");
    insert(&head, 4, "date");

    // Search for a record
    struct node* found = search(head, 3);
    if (found != NULL) {
        printf("Found %d: %s\n", found->key, found->value);
    } else {
        printf("Not found\n");
    }

    // Delete a record
    delete(&head, 2);

    // Traverse the database
    traverse(head);

    return 0;
}