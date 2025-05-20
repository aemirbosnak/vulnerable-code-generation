//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Structure definition for node of the indexing system linked list
struct node {
    int key;
    int index;
    struct node* next;
};

// Function to insert a new key and index into the indexing system
void insert(struct node** head, int key, int index) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->index = index;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* current = *head;
    while (current->next != NULL) {
        if (current->key == key) {
            // If key already exists, update index and return
            current->index = index;
            return;
        }
        current = current->next;
    }

    if (current->key == key) {
        // If key already exists, update index and return
        current->index = index;
        return;
    }

    current->next = new_node;
}

// Function to find the index of a key in the indexing system
int find(struct node* head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return head->index;
        }
        head = head->next;
    }
    return -1;  // Key not found in indexing system
}

int main() {
    struct node* head = NULL;

    // Insert some keys and indices into the indexing system
    insert(&head, 5, 100);
    insert(&head, 2, 200);
    insert(&head, 7, 300);
    insert(&head, 5, 400);  // Update index of existing key
    insert(&head, 3, 500);
    insert(&head, 9, 600);

    // Find some indices using the indexing system
    int index1 = find(head, 5);
    int index2 = find(head, 7);
    int index3 = find(head, 4);

    printf("Index of key 5: %d\n", index1);
    printf("Index of key 7: %d\n", index2);
    printf("Index of key 4: %d\n", index3);

    return 0;
}