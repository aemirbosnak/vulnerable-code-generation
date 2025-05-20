//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define the linked list head
struct Node* head = NULL;

// Function to add a new node to the beginning of the linked list
void add_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Function to display the elements of the linked list
void display_list() {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Add some nodes to the linked list
    add_node(1);
    add_node(2);
    add_node(3);

    // Display the elements of the linked list
    display_list();

    // Add a new node to the beginning of the linked list
    add_node(0);

    // Display the elements of the updated linked list
    display_list();

    // Free the memory allocated for the linked list
    struct Node* temp = head;
    while (temp!= NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}