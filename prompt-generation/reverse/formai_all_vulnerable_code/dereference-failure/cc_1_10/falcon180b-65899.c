//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new queue
Queue* create_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    if (new_queue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

// Function to check if the queue is empty
bool is_empty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to check if the queue is full
bool is_full(Queue* queue) {
    return (queue->size == 100); // Assuming maximum size of 100
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    Node* new_node = create_node(data);
    if (is_full(queue)) {
        printf("Queue is full\n");
        exit(1);
    }
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    Node* temp_node;
    int data;
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    temp_node = queue->front;
    data = temp_node->data;
    queue->front = temp_node->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp_node);
    queue->size--;
    return data;
}

// Function to display the queue
void display(Queue* queue) {
    Node* temp_node = queue->front;
    printf("Queue: ");
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue* queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    return 0;
}