//FormAI DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
struct node {
    int data;
    struct node *next;
};

// Function to add a node at the end of the linked list
void append(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));  // Allocate memory for the new node
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct node **head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node *prev = *head;
    struct node *curr = (*head)->next;
    while (curr != NULL) {
        if (curr->data == data) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to print all the nodes in the linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    
    // Append nodes
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    
    // Print the linked list
    printf("Initial Linked List:\n");
    print_list(head);
    
    // Delete a node
    delete_node(&head, 3);
    
    // Print the linked list
    printf("Linked List after deleting a node:\n");
    print_list(head);
    
    return 0;
}