//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Declare a structure for node
struct node{
    int data;
    struct node *next;
};

// Function to allocate memory for a new node
struct node *create_node(int data){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

// Function to insert a node at the end of the linked list
void insert_node(struct node **head, int data){
    // Create a new node
    struct node *new_node = create_node(data);
    // Check if the linked list is empty
    if(*head == NULL){
        *head = new_node;
        return;
    }
    // Traverse through the linked list to reach the last node
    struct node *last_node = *head;
    while(last_node->next != NULL){
        last_node = last_node->next;
    }
    // Insert the new node at the end of the linked list
    last_node->next = new_node;
}

// Function to display the linked list
void display_list(struct node *head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void free_list(struct node **head){
    struct node *current_node = *head;
    struct node *next_node = NULL;
    while(current_node != NULL){
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    *head = NULL;
}

int main(){
    // Declare a pointer to head of the linked list
    struct node *head = NULL;

    // Insert some nodes to the linked list
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);

    // Display the linked list
    printf("Linked list: ");
    display_list(head);

    // Free the memory allocated for the linked list
    free_list(&head);

    return 0;
}