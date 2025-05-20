//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// define a struct to hold the data
struct node {
    int data;
    struct node* next;
};

// allocate memory for a new node with the given data
struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// add a node to the beginning of the linked list
void add_node(struct node** headRef, int data) {
    struct node* newNode = create_node(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// remove the first node from the linked list
void remove_node(struct node** headRef) {
    if (*headRef == NULL) {
        printf("The list is empty!\n");
        return;
    }
    struct node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

// print the data stored in each node of the linked list
void print_list(struct node* head) {
    printf("Current data in the linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    printf("Initial data in the linked list: ");
    print_list(head);
    
    add_node(&head, 5); 
    printf("After adding node 5: ");
    print_list(head);
    
    add_node(&head, 7); 
    printf("After adding node 7: ");
    print_list(head);
    
    remove_node(&head); 
    printf("After removing first node: ");
    print_list(head);

    remove_node(&head); 
    printf("After removing first node again: ");
    print_list(head);

    remove_node(&head); 
    printf("After removing first node again: ");
    print_list(head);
    
    return 0;
}