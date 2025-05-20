//Falcon-180B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition 
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    if(node!= NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

// Function to add a node at the beginning of the list
void push(struct node** head_ref, int data) {
    struct node* node = newNode(data);
    node->next = *head_ref;
    *head_ref = node;
}

// Function to add a node at the end of the list
void append(struct node** head_ref, int data) {
    struct node* node = newNode(data);
    struct node* last = *head_ref;
    if(last == NULL) {
        last = node;
        *head_ref = last;
        return;
    }
    while(last->next!= NULL) {
        last = last->next;
    }
    last->next = node;
}

// Function to print the list
void printList(struct node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    struct node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    append(&head, 30);
    append(&head, 40);
    printList(head);
    return 0;
}