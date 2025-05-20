//FormAI DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Declare the struct for the linked list
typedef struct LinkedListNode {
    int value;
    struct LinkedListNode* next;
} LinkedListNode;

// Function to create a new node and add it to the linked list
void add_to_list(LinkedListNode** head, int value) {

    // Allocate memory for the new node
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    
    // Add the value to the new node
    new_node->value = value;
    
    // Set the next node to null as it will be tail
    new_node->next = NULL;

    // Check if head is null, if it is then this is the first item in the list
    if (*head == NULL) {
        printf("Empty list.\nAdding %d as first item.\n", value);
        *head = new_node; // Set the head to the new node as it is the only node in the list
        printf("Head: %d |", (*head)->value);
        printf("\tList: %d", (*head)->value);
    } 
    else {
        printf("\nAdding %d to end of list.\n", value);
        LinkedListNode* current = *head; // Set current to the current head

        // Loop through the list until the tail is found
        while (current->next != NULL) {
            printf("%d -> ", current->value); 
            current = current->next;
        }

        // Set the next node of the tail node to the new node
        current->next = new_node;
        printf("%d", current->value);
        printf(" -> %d", new_node->value);
    }
}

int main() {
    LinkedListNode* head = NULL; // Set the head to null as the list is empty
    
    add_to_list(&head, 5);
    add_to_list(&head, 10);
    add_to_list(&head, 15);
    add_to_list(&head, 20);

    printf("\nList: %d -> %d -> %d -> %d", head->value, head->next->value, head->next->next->value, head->next->next->next->value);

    return 0;
}