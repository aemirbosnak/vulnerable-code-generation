//FormAI DATASET v1.0 Category: Linked list operations ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

// defining a structure of the linked list node
struct node{
    int data;
    struct node* next;
};

// function to append a node at the end of the linked list
void append(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

// function to insert a node at the beginning of the linked list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

// function to insert a node after a given node in the linked list
void insertAfter(struct node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Given previous node cannot be NULL");
        return;
    }

    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

// function to print the linked list
void printList(struct node *node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    printf("Linked list: ");
    printList(head);

    return 0;
}