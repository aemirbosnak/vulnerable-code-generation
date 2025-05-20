//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void print_list(Node* head) {
    Node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Function to reverse the linked list recursively
Node* reverse_list(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Function to sort the linked list recursively
Node* sort_list(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = sort_list(head->next);
    if (head->data > head->next->data) {
        int temp_data = head->data;
        head->data = head->next->data;
        head->next->data = temp_data;
    }
    return head;
}

// Main function
int main() {
    Node* head = create_node(5);
    head->next = create_node(3);
    head->next->next = create_node(7);
    head->next->next->next = create_node(2);
    head->next->next->next->next = create_node(4);
    head->next->next->next->next->next = create_node(6);
    head->next->next->next->next->next->next = create_node(1);
    printf("Original list: ");
    print_list(head);
    printf("Reversed list: ");
    head = reverse_list(head);
    print_list(head);
    printf("Sorted list: ");
    head = sort_list(head);
    print_list(head);
    return 0;
}