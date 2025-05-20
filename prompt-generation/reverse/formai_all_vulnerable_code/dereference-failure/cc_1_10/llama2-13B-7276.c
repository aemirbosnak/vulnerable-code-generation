//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define a linked list
struct Node* head = NULL;

// Function to insert a node at the beginning of the list
void insert_head(int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Function to insert a node at the end of the list
void insert_tail(int data) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = NULL;
}

// Function to remove the first node from the list
void remove_head() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* removed_node = head;
    head = head->next;
    free(removed_node);
}

// Function to remove the last node from the list
void remove_tail() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
}

// Function to traverse the list
void traverse() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert_head(1);
    insert_head(2);
    insert_head(3);
    insert_tail(4);
    insert_tail(5);
    remove_head();
    remove_tail();
    traverse();
    return 0;
}