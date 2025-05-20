//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
/*

    This C program demonstrates memory management in a sophisticated way.
    It creates a dynamic linked list of integers, and allows the user to add, delete, or
    print elements of the list.

*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int value;
    struct node *next;
};

// Function prototypes
void insert_node(int value, struct node **head);
void delete_node(int value, struct node **head);
void print_list(struct node *head);

int main() {
    
    // Declare the head of the linked list
    struct node *head = NULL;
    
    while(1) {
        // Prompt the user for input
        char command;
        printf("\nEnter 'a' to add a node,\n'd' to delete a node,\n'p' to print the list, or\n'q' to quit: ");
        scanf(" %c", &command);
        
        // Process the user's command
        switch(command) {
            case 'a': {
                // Prompt the user for the value to insert
                int value;
                printf("\nEnter the value to add: ");
                scanf("%d", &value);
                
                // Add the value to the linked list
                insert_node(value, &head);
                break;
            }
            case 'd': {
                // Prompt the user for the value to delete
                int value;
                printf("\nEnter the value to delete: ");
                scanf("%d", &value);
                
                // Delete the value from the linked list
                delete_node(value, &head);
                break;
            }
            case 'p': {
                // Print the linked list
                print_list(head);
                break;
            }
            case 'q': {
                // Free memory and exit the program
                while(head != NULL) {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            }
            default: {
                printf("\nInvalid command, please try again.\n");
                break;
            }
        }
    }
}

// Function to insert a node with a given value into a linked list
void insert_node(int value, struct node **head) {
    
    // Create a new node and set its value
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    
    // Find the tail of the linked list and add the new node
    if(*head == NULL) {
        *head = new_node;
    }
    else {
        struct node *tail = *head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;
    }
    
}

// Function to delete a node with a given value from a linked list
void delete_node(int value, struct node **head) {
    
    // Find the node with the given value
    struct node *curr = *head;
    struct node *prev = NULL;
    while(curr != NULL && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }
    
    // If the node was found, remove it
    if(curr != NULL) {
        if(prev == NULL) {
            *head = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        free(curr);
    }
    else {
        printf("\nValue not found in the list.\n");
    }
    
}

// Function to print a linked list
void print_list(struct node *head) {
    
    printf("\nThe list contains: ");
    while(head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
    
}