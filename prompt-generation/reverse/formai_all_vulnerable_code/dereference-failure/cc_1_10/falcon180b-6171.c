//Falcon-180B DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for the linked list
typedef struct list {
    Node* head;
    Node* tail;
} List;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(List* lst, int data) {
    Node* new_node = create_node(data);
    if (lst->head == NULL) {
        lst->head = new_node;
        lst->tail = new_node;
    } else {
        lst->tail->next = new_node;
        lst->tail = new_node;
    }
}

// Function to print the list
void print_list(List* lst) {
    Node* curr_node = lst->head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverse_list(List* lst) {
    Node* curr_node = lst->head;
    Node* prev_node = NULL;
    while (curr_node!= NULL) {
        Node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    lst->head = prev_node;
}

int main() {
    List lst;
    lst.head = NULL;
    lst.tail = NULL;

    add_node(&lst, 1);
    add_node(&lst, 2);
    add_node(&lst, 3);
    add_node(&lst, 4);
    add_node(&lst, 5);

    printf("Original list:\n");
    print_list(&lst);

    reverse_list(&lst);

    printf("Reversed list:\n");
    print_list(&lst);

    return 0;
}