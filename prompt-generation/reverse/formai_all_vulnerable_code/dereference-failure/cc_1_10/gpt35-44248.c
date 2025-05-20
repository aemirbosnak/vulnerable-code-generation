//FormAI DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Shape-shifting example program for C linked list operations

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

// Function to create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_beg(struct node **head_ref, struct node *new_node) {
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else {
        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
    }
}

// Function to insert a node at the end of the list
void insert_end(struct node **head_ref, struct node *new_node) {
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else {
        struct node *temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Function to delete a node with a given value from the list
void delete_node(struct node **head_ref, int value) {
    struct node *current_node = *head_ref;
    struct node *prev_node = NULL;

    while (current_node != NULL && current_node->value != value) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node with value %d not found in list\n", value);
    }
    else {
        if (prev_node == NULL) {
            *head_ref = current_node->next;
        }
        else {
            prev_node->next = current_node->next;
            if (current_node->next != NULL) {
                current_node->next->prev = prev_node;
            }
        }
        free(current_node);
        printf("Node with value %d deleted from list\n", value);
    }
}

// Function to display the list
void display_list(struct node *head) {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    struct node *node1 = create_node(5);
    struct node *node2 = create_node(10);
    struct node *node3 = create_node(15);
    struct node *node4 = create_node(20);

    // Shape shift the program to insert nodes at the beginning of the list
    printf("Inserting nodes at the beginning of the list\n");
    insert_beg(&head, node1);
    insert_beg(&head, node2);
    insert_beg(&head, node3);
    display_list(head);

    // Shape shift the program to insert nodes at the end of the list
    printf("Inserting nodes at the end of the list\n");
    insert_end(&head, node4);
    display_list(head);
    
    // Shape shift the program to delete a node from the list
    printf("Deleting node with value 10 from the list\n");
    delete_node(&head, 10);
    display_list(head);

    // Shape shift the program to delete a node that doesn't exist in the list
    printf("Deleting node with value 25 from the list\n");
    delete_node(&head, 25);

    return 0;
}