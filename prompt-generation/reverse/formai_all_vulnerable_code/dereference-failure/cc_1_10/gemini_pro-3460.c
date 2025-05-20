//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure (implemented using a linked list)
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    int data = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

// Function to visualize the queue using ASCII art
void visualizeQueue(Queue *queue) {
    Node *current = queue->front;
    printf("----------------------\n");
    printf("|     Queue     |\n");
    printf("----------------------\n");
    printf("| Front | Rear |\n");
    printf("----------------------\n");
    while (current != NULL) {
        printf("| %4d | %4d |\n", current->data, current->next == NULL ? -1 : current->next->data);
        current = current->next;
    }
    printf("----------------------\n");
}

// Main function
int main() {
    // Create a new queue
    Queue *queue = createQueue();

    // Enqueue some elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Visualize the queue
    visualizeQueue(queue);

    // Dequeue some elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Visualize the queue again
    visualizeQueue(queue);

    return 0;
}