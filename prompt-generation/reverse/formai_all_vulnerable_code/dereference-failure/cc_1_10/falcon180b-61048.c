//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the rear of the queue
void enqueue(struct node** front_ref, struct node** rear_ref, int data) {
    struct node* node = newNode(data);

    // If the queue is empty, set both front and rear to the new node
    if (*front_ref == NULL && *rear_ref == NULL) {
        *front_ref = node;
        *rear_ref = node;
        return;
    }

    // Otherwise, add the node to the rear of the queue
    (*rear_ref)->next = node;
    (*rear_ref) = node;
}

// Function to remove an element from the front of the queue
int dequeue(struct node** front_ref, struct node** rear_ref) {
    struct node* node = *front_ref;

    // If the queue is empty, return -1 to indicate failure
    if (node == NULL)
        return -1;

    // Move the front pointer to the next node
    *front_ref = node->next;

    // If the queue becomes empty, set the rear pointer to NULL as well
    if (*front_ref == NULL)
        *rear_ref = NULL;

    // Free the memory occupied by the removed node
    free(node);

    // Return the data of the removed node
    return node->data;
}

// Function to print the elements of the queue
void printQueue(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    // Add elements to the queue
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    // Print the queue
    printf("Queue: ");
    printQueue(front);
    printf("\n");

    // Remove an element from the queue
    int removed_element = dequeue(&front, &rear);
    printf("Removed element: %d\n", removed_element);

    // Print the queue again
    printf("Queue after removal: ");
    printQueue(front);
    printf("\n");

    return 0;
}