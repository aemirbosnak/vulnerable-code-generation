//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning of the linked list
struct node* insert_at_beginning(struct node* head, int data) {
    // Allocate memory for the new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Error: Memory allocation failed!");
        exit(1);
    }
    // Initialize the data and next pointer of the new node
    new_node->data = data;
    new_node->next = head;
    // Return the new head of the linked list
    return new_node;
}

// Function to insert a new node at the end of the linked list
struct node* insert_at_end(struct node* head, int data) {
    // Allocate memory for the new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Error: Memory allocation failed!");
        exit(1);
    }
    // Initialize the data and next pointer of the new node
    new_node->data = data;
    new_node->next = NULL;
    // Handle the case when the linked list is empty
    if(head == NULL) {
        return new_node;
    }
    // Traverse the linked list to find the last node
    struct node* current_node = head;
    while(current_node->next != NULL) {
        current_node = current_node->next;
    }
    // Add the new node to the end of the linked list
    current_node->next = new_node;
    // Return the head of the linked list
    return head;
}

// Function to delete the first occurrence of a node with the given data
struct node* delete_node(struct node* head, int data) {
    // Handle the case when the linked list is empty
    if(head == NULL) {
        printf("Error: Linked list is empty!");
        exit(1);
    }
    // Handle the case when the node to be deleted is the first node
    if(head->data == data) {
        struct node* temp_node = head;
        head = head->next;
        free(temp_node);
        return head;
    }
    // Traverse the linked list to find the node to be deleted
    struct node* current_node = head;
    while(current_node->next != NULL && current_node->next->data != data) {
        current_node = current_node->next;
    }
    // Handle the case when the node to be deleted is not found
    if(current_node->next == NULL) {
        printf("Error: Node not found in the linked list!");
        exit(1);
    }
    // Delete the node
    struct node* temp_node = current_node->next;
    current_node->next = current_node->next->next;
    free(temp_node);
    // Return the head of the linked list
    return head;
}

// Function to print the linked list
void print_linked_list(struct node* head) {
    printf("Linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    // Initialize the head of the linked list to NULL
    struct node* head = NULL;
    // Insert some nodes at the beginning of the linked list
    head = insert_at_beginning(head, 3);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 1);
    print_linked_list(head);
    // Insert some nodes at the end of the linked list
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);
    print_linked_list(head);
    // Delete some nodes from the linked list
    head = delete_node(head, 3);
    head = delete_node(head, 6);
    print_linked_list(head);
    // Free memory allocated for the linked list
    while(head != NULL) {
        struct node* temp_node = head;
        head = head->next;
        free(temp_node);
    }
    return 0;
}