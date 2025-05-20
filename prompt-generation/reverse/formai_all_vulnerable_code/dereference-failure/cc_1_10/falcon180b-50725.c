//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node with given data
Node* delete_node(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Function to print the list
void print_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);

    // Print the list
    print_list(head);

    // Delete a node
    head = delete_node(head, 3);

    // Print the list again
    print_list(head);

    return 0;
}