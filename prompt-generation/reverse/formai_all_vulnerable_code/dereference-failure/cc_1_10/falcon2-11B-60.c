//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent the nodes of the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to initialize the queue
void init_queue(Node** queue) {
    *queue = NULL;
}

// Function to enqueue a node to the queue
void enqueue(Node** queue, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*queue == NULL) {
        *queue = new_node;
    } else {
        Node* current = *queue;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to dequeue a node from the queue
void dequeue(Node** queue) {
    if (*queue == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

// Function to print the queue
void print_queue(Node* queue) {
    Node* current = queue;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize the queue
    Node* queue = NULL;
    init_queue(&queue);

    // Enqueue some elements
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    // Print the queue
    print_queue(queue);

    // Dequeue some elements
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Print the queue again
    print_queue(queue);

    return 0;
}