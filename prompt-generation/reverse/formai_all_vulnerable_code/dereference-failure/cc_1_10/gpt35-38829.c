//FormAI DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Declare struct for node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Declare linked list head pointer
Node *head = NULL;

void allocate_memory() {
    int *ptr;
    ptr = malloc(sizeof(int)*10); // Allocating 10 integers worth of memory
    
    if(ptr == NULL) { // Check if malloc was successful
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
    
    // Enter values into the dynamically allocated memory
    for(int i=0; i<10; i++) {
        *(ptr+i) = i+1;
    }
    
    // Print out the dynamically allocated memory
    printf("The dynamically allocated memory contains: ");
    for(int i=0; i<10; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");
    
    free(ptr); // Free the dynamically allocated memory
}

void add_node(int data) {
    Node *new_node = malloc(sizeof(Node)); // Allocate memory for new node
    
    if(new_node == NULL) { // Check if malloc was successful
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
    
    new_node->data = data; // Set data of new node
    
    if(head == NULL) { // Check if linked list is empty
        head = new_node; // Set head to new node
        head->next = NULL; // Set next pointer to NULL
    } else {
        Node *temp = head; // Create temporary pointer to head
        
        while(temp->next != NULL) { // Traverse linked list to end
            temp = temp->next;
        }
        
        temp->next = new_node; // Set last node's next to the new node
        new_node->next = NULL; // Set new node's next to NULL
    }
}

void free_memory() {
    Node *temp = head; // Create temporary pointer to head
    
    while(temp != NULL) { // Traverse linked list
        Node *prev = temp; // Create previous pointer
        temp = temp->next; // Set temp to the next node
        free(prev); // Free previous node
    }
    
    printf("Memory freed.\n");
}

int main() {
    printf("Welcome to the Memory Management Program!\n");
    
    allocate_memory();
    
    printf("\nLet's create a linked list...\n");
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    
    printf("The data in the linked list is: ");
    Node *temp = head; // Create temporary pointer to head
    
    while(temp != NULL) { // Traverse linked list
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    printf("Now let's free the memory...\n");
    free_memory();
    
    return 0;
}