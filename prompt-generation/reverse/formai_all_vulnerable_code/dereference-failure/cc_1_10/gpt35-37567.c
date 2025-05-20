//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NodePtr;

int main() {
    NodePtr head = NULL;
    NodePtr tail = NULL;
    int size = 0;
    
    // Print empty linked list
    printf("The linked list is currently empty.\n");
    
    // Add new node to linked list
    NodePtr newNode = malloc(sizeof(struct node));
    newNode->data = 5;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    
    printf("Added a new node containing 5 to the linked list.\n");
    
    // Add another node
    newNode = malloc(sizeof(struct node));
    newNode->data = 10;
    newNode->next = NULL;
    
    tail->next = newNode;
    tail = newNode;
    size++;
    
    printf("Added a new node containing 10 to the linked list.\n");
    
    // Add third node
    newNode = malloc(sizeof(struct node));
    newNode->data = 15;
    newNode->next = NULL;
    
    tail->next = newNode;
    tail = newNode;
    size++;
    
    printf("Added a new node containing 15 to the linked list.\n");
    
    // Print linked list size and values
    printf("The linked list now contains %d nodes and their values are:\n", size);
    
    NodePtr current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    // Remove second node
    NodePtr previous = head;
    current = head->next;
    
    head->next = current->next;
    free(current);
    size--;
    
    printf("\nRemoved the node containing 10 from the linked list.\n");
    
    // Print updated linked list size and values
    printf("The linked list now contains %d nodes and their values are:\n", size);
    
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    // Free memory
    NodePtr temp;
    current = head;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    
    printf("\nFreed all memory allocated for the linked list.\n");
    
    return 0;
}