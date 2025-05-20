//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->size == MAX_SIZE)
        return 1;
    else
        return 0;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (isEmpty(queue)) {
        queue->front = temp;
        queue->rear = temp;
    }
    else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
    queue->size++;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    int value;
    struct Node* temp = queue->front;
    if (isEmpty(queue))
        return -1;
    else {
        value = temp->data;
        queue->front = temp->next;
        free(temp);
        queue->size--;
        return value;
    }
}

// Function to display the queue
void display(struct Queue* queue) {
    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    return 0;
}