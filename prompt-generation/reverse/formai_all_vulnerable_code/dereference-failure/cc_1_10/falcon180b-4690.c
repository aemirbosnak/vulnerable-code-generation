//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the linked list
void add_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    struct node *temp = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to search for a node with given data in the linked list
struct node *search_node(struct node *head, int data) {
    struct node *temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node with given data from the linked list
void delete_node(struct node **head, int data) {
    struct node *temp = search_node(*head, data);

    if (temp == NULL) {
        return;
    }

    if (temp == *head) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct node *prev = *head;
    while (prev->next!= temp) {
        prev = prev->next;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    // Add nodes to the linked list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    // Print the linked list
    print_list(head);

    // Search for a node with given data
    struct node *result = search_node(head, 3);
    if (result!= NULL) {
        printf("Node found with data: %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node with given data
    delete_node(&head, 3);

    // Print the linked list after deletion
    print_list(head);

    return 0;
}