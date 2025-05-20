//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data and link it to the end of the list
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the beginning of the list
void add_to_front(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to add a node at the end of the list
void add_to_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    struct Node* last = *head;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete a node with a given data from the list
void delete_node(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp!= NULL) {
        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

int main() {
    // Create a new linked list
    struct Node* head = NULL;

    // Add some nodes to the list
    add_to_end(&head, 1);
    add_to_end(&head, 2);
    add_to_end(&head, 3);

    // Print the linked list
    printf("Original list: ");
    print_list(head);

    // Delete a node with data 2
    delete_node(&head, 2);

    // Print the updated list
    printf("\nUpdated list: ");
    print_list(head);

    return 0;
}