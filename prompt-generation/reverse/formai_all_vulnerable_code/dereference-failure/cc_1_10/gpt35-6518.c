//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include<stdio.h>
#include<stdlib.h>

// Defining structure for a node in a linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* create_new_node(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void print_linked_list(struct node* head) {
    struct node* ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    // Creating a linked list of 5 nodes
    struct node* head = create_new_node(1);
    struct node* second = create_new_node(2);
    struct node* third = create_new_node(3);
    struct node* fourth = create_new_node(4);
    struct node* fifth = create_new_node(5);

    // Connecting the nodes together
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Printing the original linked list
    printf("Original linked list:\n");
    print_linked_list(head);

    // Reversing the linked list
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Printing the reversed linked list
    printf("Reversed linked list:\n");
    print_linked_list(head);

    return 0;
}