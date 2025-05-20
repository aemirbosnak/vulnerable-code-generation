//FormAI DATASET v1.0 Category: Queue ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

/* Defining the structure of Queue */
typedef struct {
    int *arr;
    int front, rear;
    int size, capacity;
} queue;

/* Function to create the Queue */
queue *createQueue(int capacity) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->size = 0;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(sizeof(int)*capacity);
    return q;
}

/* Function to check if Queue is full */
int isFull(queue *q) {
    return q->size == q->capacity;
}

/* Function to check if Queue is empty */
int isEmpty(queue *q) {
    return q->size == 0;
}

/* Function to add an element to the Queue */
void enqueue(queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % q->capacity;
    }
    q->arr[q->rear] = element;
    q->size += 1;
}

/* Function to remove an element from the Queue */
int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size -= 1;
    if (isEmpty(q)) {
        q->front = -1;
        q->rear = -1;
    }
    return element;
}

/* Function to display the Queue */
void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = 0; i < q->size; i++) {
        printf("%d ", q->arr[(q->front+i)%q->capacity]);
    }
    printf("\n");
}

/* Main Function */
int main() {
    queue *q = createQueue(5); // Creating a Queue of capacity 5
    enqueue(q, 1); // Adding elements to the Queue
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q); // Displaying the contents of the Queue
    dequeue(q); // Removing the first element from the Queue
    dequeue(q); // Removing the second element from the Queue
    printf("After dequeuing two elements: ");
    display(q); // Displaying the contents of the Queue after dequeuing elements
    enqueue(q, 6); // Adding an element to the Queue
    enqueue(q, 7); // Adding another element to the Queue
    printf("After enqueuing two elements: ");
    display(q); // Displaying the contents of the Queue after adding elements
    return 0;
}