//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
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
        new_node->next = NULL;
        *head = new_node;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
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

// Function to reverse the list
void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to sort the list in ascending order
void sort_list(Node** head) {
    Node* temp = *head;
    while (temp!= NULL && temp->next!= NULL) {
        if (temp->data > temp->next->data) {
            int temp_data = temp->data;
            temp->data = temp->next->data;
            temp->next->data = temp_data;
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    add_node(&head, 5);
    add_node(&head, 3);
    add_node(&head, 7);

    // Print the list
    printf("Original list:\n");
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the reversed list
    printf("Reversed list:\n");
    print_list(head);

    // Sort the list
    sort_list(&head);

    // Print the sorted list
    printf("Sorted list:\n");
    print_list(head);

    return 0;
}