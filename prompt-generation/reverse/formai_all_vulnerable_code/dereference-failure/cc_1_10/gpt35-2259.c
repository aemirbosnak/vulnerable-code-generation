//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

//Defining the structure of the node for the linked list
struct node {
    int data;
    struct node *next;
};

//Function to insert a node at the end of the linked list
void insert_node(struct node **head_node, int new_data) {
    //Creating a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    //If linked list is empty
    if (*head_node == NULL) {
        *head_node = new_node;
        return;
    }

    //Traversing to the end of the linked list
    struct node *current_node = *head_node;
    while (current_node->next != NULL)
        current_node = current_node->next;

    //Inserting the new node at the end of the linked list
    current_node->next = new_node;
}

//Function to recursively display the content of the linked list
void display_list(struct node *head_node) {
    if (head_node == NULL)
        return;
    printf("%d ", head_node->data);
    display_list(head_node->next);
}

//Main function to test the above functions
int main() {
    struct node *head_node = NULL;

    //Inserting nodes at the end of the linked list
    insert_node(&head_node, 10);
    insert_node(&head_node, 20);
    insert_node(&head_node, 30);
    insert_node(&head_node, 40);

    //Displaying the content of the linked list recursively
    display_list(head_node);

    return 0;
}