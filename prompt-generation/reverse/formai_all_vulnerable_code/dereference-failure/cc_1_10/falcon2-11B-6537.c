//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue
typedef struct {
    int size;
    int front;
    int rear;
    int *data;
} queue;

// Function to create a new queue
queue* createQueue(int size) {
    queue *q = (queue*)malloc(sizeof(queue));
    q->size = size;
    q->front = 0;
    q->rear = -1;
    q->data = (int*)malloc(q->size * sizeof(int));
    return q;
}

// Function to push an element onto the queue
void push(queue *q, int element) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = element;
}

// Function to pop an element from the queue
int pop(queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = q->data[q->front];
    q->front++;
    return element;
}

// Function to display the elements in the queue
void display(queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    queue *q = createQueue(size);

    // Push elements onto the queue
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);

    // Pop elements from the queue
    int element = pop(q);
    printf("Popped element: %d\n", element);
    element = pop(q);
    printf("Popped element: %d\n", element);
    element = pop(q);
    printf("Popped element: %d\n", element);

    // Display the elements in the queue
    display(q);

    return 0;
}