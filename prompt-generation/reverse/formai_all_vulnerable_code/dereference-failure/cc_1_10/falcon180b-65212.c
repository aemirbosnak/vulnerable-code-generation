//Falcon-180B DATASET v1.0 Category: Recursive ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct Node{
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to reverse the linked list recursively
void reverseList(struct Node** head_ref){
    struct Node* prev_node = NULL;
    struct Node* current_node = (*head_ref);

    // Iterate through the list and reverse the links
    while(current_node!= NULL){
        struct Node* next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    // Update the head pointer
    (*head_ref) = prev_node;
}

int main(){
    struct Node* head = NULL;

    // Add nodes to the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    // Print the original list
    printf("Original list: ");
    printList(head);
    printf("\n");

    // Reverse the list recursively
    reverseList(&head);

    // Print the reversed list
    printf("Reversed list: ");
    printList(head);
    printf("\n");

    return 0;
}