//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if(queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if(isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int data;
    struct Node* temp = queue->front;

    if(isEmpty(queue))
        return -1;

    data = temp->data;
    queue->front = temp->next;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return data;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct Node* temp = queue->front;

    if(isEmpty(queue))
        printf("Queue is empty\n");
    else {
        printf("Elements in the queue are: ");
        while(temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int data = dequeue(queue);
    printf("Dequeued element is: %d\n", data);

    display(queue);

    data = dequeue(queue);
    printf("Dequeued element is: %d\n", data);

    display(queue);

    data = dequeue(queue);
    printf("Dequeued element is: %d\n", data);

    display(queue);

    data = dequeue(queue);
    printf("Dequeued element is: %d\n", data);

    display(queue);

    return 0;
}