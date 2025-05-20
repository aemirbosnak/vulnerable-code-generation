//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for our nodes
typedef struct node {
    int data;
    struct node* next;
} Node;

// function prototypes
void create_node(Node** head_ref, int data);
void delete_node(Node** head_ref, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;

    // create some nodes
    create_node(&head, 1);
    create_node(&head, 2);
    create_node(&head, 3);

    // print the list
    printf("Initial list:\n");
    print_list(head);

    // delete a node
    delete_node(&head, 2);

    // print the list again
    printf("\nList after deleting node with data 2:\n");
    print_list(head);

    return 0;
}

// function to create a new node with given data
void create_node(Node** head_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // link the new node to the head
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    Node* last_node = *head_ref;
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    new_node->next = NULL;
}

// function to delete a node with given data
void delete_node(Node** head_ref, int data) {
    Node* temp_node = *head_ref;

    // check if the head is the node to be deleted
    if (temp_node!= NULL && temp_node->data == data) {
        *head_ref = temp_node->next;
        free(temp_node);
        return;
    }

    // traverse the list to find the node to be deleted
    while (temp_node!= NULL && temp_node->data!= data) {
        temp_node = temp_node->next;
    }

    // node not found
    if (temp_node == NULL) {
        return;
    }

    // unlink the node from the list
    Node* next_node = temp_node->next;
    free(temp_node);
    temp_node = next_node;
}

// function to print the list
void print_list(Node* head) {
    Node* current_node = head;
    while (current_node!= NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}