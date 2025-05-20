//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our doubly-linked list
typedef struct node {
    int data;
    struct node* previous;
    struct node* next;
} Node;

// Function to visualize our doubly-linked list
void visualizeList(Node* head) {
    printf("Current List: \n");
    Node* temp = head;
    while(temp != NULL) {
        // Print out each node's data value
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the head node of our list
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->previous = NULL;
    head->next = NULL;

    // Create additional nodes
    Node* second = (Node*)malloc(sizeof(Node));
    second->data = 2;
    second->previous = head;
    second->next = NULL;
    head->next = second;

    Node* third = (Node*)malloc(sizeof(Node));
    third->data = 3;
    third->previous = second;
    third->next = NULL;
    second->next = third;

    visualizeList(head);

    // Free up memory used by the nodes
    free(head);
    free(second);
    free(third);

    return 0;
}