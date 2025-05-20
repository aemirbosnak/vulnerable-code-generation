//FormAI DATASET v1.0 Category: Queue ; Style: content
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

// Queue data structure
typedef struct {
    int *arr;   // array to hold queue elements
    int front;  // front index of queue
    int rear;   // rear index of queue
    int count;  // count of elements in queue
} Queue;

// function to initialize queue
void initQueue(Queue *q) {
    q->arr = (int*)malloc(SIZE*sizeof(int)); // allocate memory for array
    q->front = 0; // initialize front to zero
    q->rear = -1; // initialize rear to -1
    q->count = 0; // initialize count to zero
}

// function to check if the queue is full
int isFull(Queue *q) {
    return (q->count == SIZE);
}

// function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->count == 0);
}

// function to add an element to the queue
void enqueue(Queue *q, int element) {
    if(isFull(q)) {
        printf("Queue is full. Element cannot be enqueued.\n");
        return;
    }
    q->rear = (q->rear+1)%SIZE; // update rear index
    q->arr[q->rear] = element; // add element to rear of queue
    q->count++; // increment count of elements in queue
}

// function to remove an element from the queue
int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty. Element cannot be dequeued.\n");
        return -1;
    }
    int temp = q->arr[q->front]; // get the element at the front of queue
    q->front = (q->front+1)%SIZE; // update front index
    q->count--; // decrement count of elements in queue
    return temp;
}

int main() {
    Queue q;
    initQueue(&q);

    // test enqueue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // test dequeue
    int element = dequeue(&q);
    printf("Dequeued element: %d\n", element);

    enqueue(&q, 40);
    enqueue(&q, 50);

    // test dequeue again
    element = dequeue(&q);
    printf("Dequeued element: %d\n", element);

    // test enqueue beyond max size
    enqueue(&q, 60);
    enqueue(&q, 70);

    // test dequeue beyond max size
    element = dequeue(&q);
    printf("Dequeued element: %d\n", element);

    // test dequeue all elements
    while(!isEmpty(&q)) {
        element = dequeue(&q);
        printf("Dequeued element: %d\n", element);
    }

    return 0;
}