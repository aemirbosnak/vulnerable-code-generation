//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    int i;
    node *head = NULL;
    node *temp;

    // Allocate memory for the head node
    head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Allocate memory for the temp node
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the head node
    head->data = 0;
    head->next = NULL;

    // Initialize the temp node
    temp->data = 0;
    temp->next = NULL;

    // Insert nodes into the linked list
    for (i = 1; i <= MAX_SIZE; i++) {
        // Allocate memory for a new node
        node *new_node = (node *)malloc(sizeof(node));
        if (new_node == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Initialize the new node
        new_node->data = i;
        new_node->next = NULL;

        // Insert the new node at the end of the linked list
        new_node->next = NULL;
        temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Free the temp node
    free(temp);

    // Free the head node
    free(head);

    printf("Memory management complete.\n");

    return 0;
}