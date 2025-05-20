//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

// A structure for the node
struct node {
    int data;
    struct node* next;
};

// Function to add a node at the beginning of the linked list
void push(struct node** head_ref, int new_data) {
    // Allocating memory for new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // Assigning new value to the new node
    new_node->data = new_data;
    // Pointing the new node to the previous head as its next node
    new_node->next = (*head_ref);
    // Setting the new node as the head of the list
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct node* n) {
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating an empty list
    struct node* head = NULL;
    // Adding elements to the list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    // Printing the list
    printf("Original Linked List:\n");
    printList(head);

    // Swapping the positions of nodes at 2nd and 3rd index
    struct node* temp1 = head->next;
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
    head->next = temp2;

    // Printing the modified list
    printf("\nLinked List after swapping positions of 2nd and 3rd node:\n");
    printList(head);

    return 0;
}