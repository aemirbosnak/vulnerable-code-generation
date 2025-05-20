//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: funny
/*

A unique C Queue Implementation program in a funny style.
This program demonstrates the use of a queue data structure
to store and retrieve elements in a first-in-first-out manner.
The program uses a circular queue, which means that the queue
is implemented using a linked list, with the last element
pointing to the first element, and the first element pointing
to the last element.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, int data) {
    // Create a new node with the given data
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // If the queue is empty, set the front and rear pointers to the new node
    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, append the new node to the end of the queue
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    // If the queue is empty, return -1
    if (queue->front == NULL) {
        return -1;
    }

    // Otherwise, remove the front node from the queue
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    // Add some elements to the queue
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);

    // Print the elements in the queue
    printf("Elements in the queue: ");
    while (queue->front!= NULL) {
        printf("%d ", queue->front->data);
        queue->front = queue->front->next;
    }

    // Remove the first element from the queue
    printf("\nDequeueing the first element: %d\n", dequeue(queue));

    // Print the remaining elements in the queue
    printf("Elements in the queue after dequeue: ");
    while (queue->front!= NULL) {
        printf("%d ", queue->front->data);
        queue->front = queue->front->next;
    }

    return 0;
}