//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add an element to the end of the queue
void enqueue(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    Node* last = *head_ref;

    // If the queue is empty, set the new node as the head
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    // Traverse to the end of the queue and add the new node
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to remove an element from the front of the queue
int dequeue(Node** head_ref) {
    Node* temp = *head_ref;
    int data = temp->data;

    // If the queue is empty, return -1
    if (*head_ref == NULL) {
        return -1;
    }

    // Set the next node as the new head
    *head_ref = temp->next;

    // Free the memory of the removed node
    free(temp);
    return data;
}

// Function to print the elements of the queue
void print_queue(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    // Add elements to the queue
    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);
    enqueue(&head, 40);

    // Print the queue
    printf("Queue: ");
    print_queue(head);

    // Remove an element from the queue
    int removed_data = dequeue(&head);
    printf("\nRemoved element: %d\n", removed_data);

    // Print the queue again
    printf("Queue after removal: ");
    print_queue(head);

    return 0;
}