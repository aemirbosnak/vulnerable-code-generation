//FormAI DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct node { // Structure for a single node
    int data; // Data for the node
    struct node *next; // Pointer to the next node
} Node;

typedef struct list { // Structure for the linked list
    Node *head; // Pointer to the first node
    int count; // Count of nodes in the linked list
} List;

Node *create_node(int data) { // Function to create a new node
    Node *new_node = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node
    new_node->data = data; // Assign data for the new node
    new_node->next = NULL; // Initialize the next pointer to NULL
    return new_node; // Return a pointer to the new node
}

List *create_list() { // Function to create a new empty linked list
    List *new_list = (List*) malloc(sizeof(List)); // Allocate memory for the new list
    new_list->head = NULL; // Initialize the head pointer to NULL
    new_list->count = 0; // Initialize the count of nodes in the list to 0
    return new_list; // Return a pointer to the new list
}

void insert_node(List *list, int data) { // Function to insert a new node at the beginning of the linked list
    Node *new_node = create_node(data); // Create a new node with the specified data
    new_node->next = list->head; // Make the new node point to the head node
    list->head = new_node; // Make the head node point to the new node
    list->count++; // Increment the count of nodes in the list
}

void delete_node(List *list, int data) { // Function to delete a node from the linked list
    Node *current = list->head; // Start with the head node
    Node *previous = NULL; // Initialize the previous pointer to NULL
    while (current != NULL) { // Traverse through the list
        if (current->data == data) { // If a node with the specified data is found
            if (previous == NULL) { // If the node to be deleted is the first node
                list->head = current->next; // Make the head node point to the next node
            } else { // If the node to be deleted is not the first node
                previous->next = current->next; // Make the previous node point to the next node
            }
            free(current); // Free the memory allocated for the node
            list->count--; // Decrement the count of nodes in the list
            break; // Exit the loop
        }
        previous = current; // Move the previous pointer to the current node
        current = current->next; // Move the current pointer to the next node
    }
}

void print_list(List *list) { // Function to print the linked list
    Node *current = list->head; // Start with the head node
    while (current != NULL) { // Traverse through the list
        printf("%d ", current->data); // Print the data of the node
        current = current->next; // Move the current pointer to the next node
    }
    printf("\n"); // Print a new line at the end
}

int main() { // Main function
    List *my_list = create_list(); // Create a new empty linked list
    insert_node(my_list, 5); // Insert a new node with data 5
    insert_node(my_list, 10); // Insert a new node with data 10
    insert_node(my_list, 15); // Insert a new node with data 15
    insert_node(my_list, 20); // Insert a new node with data 20
    printf("Printing the initial list: "); // Print a message
    print_list(my_list); // Print the linked list
    delete_node(my_list, 10); // Delete the node with data 10
    printf("Printing the updated list: "); // Print a message
    print_list(my_list); // Print the linked list
    return 0; // End the program
}