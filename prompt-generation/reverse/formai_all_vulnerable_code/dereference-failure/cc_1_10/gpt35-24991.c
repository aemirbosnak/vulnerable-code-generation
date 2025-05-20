//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
// Welcome to the world of Linked Lists!

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the Linked List
struct node {
    int data;
    struct node *next;
};

// Declare the head of the Linked List
struct node *head = NULL;

// Function to insert elements into the Linked List
void insert(int data) {
    // Create a new node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    // If the Linked List is empty, insert at head
    if (head == NULL) {
        head = new_node;
    }
    // Else, insert at end of Linked List
    else {
        struct node *temp_node = head;
        while (temp_node->next != NULL) {
            temp_node = temp_node->next;
        }
        temp_node->next = new_node;
    }
}

// Function to delete an element from the Linked List
void delete(int data) {
    struct node *prev_node, *curr_node;
    curr_node = head;
    
    // If the head is to be deleted
    if (curr_node->data == data) {
        head = curr_node->next;
        free(curr_node);
    }
    // If any other element is to be deleted
    else {
        prev_node = curr_node;
        curr_node = curr_node->next;
        while (curr_node != NULL) {
            if (curr_node->data == data) {
                prev_node->next = curr_node->next;
                free(curr_node);
                break;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
}

// Function to display the Linked List
void display() {
    struct node *temp_node = head;
    while (temp_node != NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    // Insert some elements into the Linked List
    insert(5);
    insert(8);
    insert(3);
    insert(2);
    printf("Linked List: ");
    display();
    
    // Delete an element from the Linked List
    delete(3);
    printf("Linked List after deleting 3: ");
    display();
    
    // Insert another element into the Linked List
    insert(9);
    printf("Linked List after inserting 9: ");
    display();
    
    return 0;
}