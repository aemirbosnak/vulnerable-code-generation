//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct node {
    int data;
    struct node* next;
};

// Define a queue structure
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create a new node with given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new queue
struct queue* create_queue() {
    struct queue* new_queue = (struct queue*)malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to insert an element into the queue
void enqueue(struct queue* q, int data) {
    struct node* new_node = create_node(data);
    
    // If the queue is empty, set the front and rear pointers to the new node
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    }
    
    // Otherwise, add the new node to the rear of the queue
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Function to delete an element from the queue
void dequeue(struct queue* q) {
    // If the queue is empty, print an error message
    if (q->front == NULL) {
        printf("Queue is empty\n");
    }
    
    // Otherwise, remove the front node from the queue
    else {
        struct node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

// Function to print the elements in the queue
void print_queue(struct queue* q) {
    struct node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct queue* q = create_queue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    
    printf("Queue elements: ");
    print_queue(q);
    
    dequeue(q);
    dequeue(q);
    
    printf("Queue elements after deletion: ");
    print_queue(q);
    
    return 0;
}