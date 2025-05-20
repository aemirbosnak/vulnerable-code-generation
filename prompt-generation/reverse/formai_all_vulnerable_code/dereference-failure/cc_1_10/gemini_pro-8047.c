//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Node struct to represent a queue element
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue struct to represent the queue
typedef struct Queue {
    Node *front, *rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
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
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to get the front element of the queue
int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

// Function to get the rear element of the queue
int rear(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->rear->data;
}

// Function to print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver program to test the queue implementation
int main() {
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    printf("The queue is:\n");
    printQueue(queue);
    printf("The front element is: %d\n", front(queue));
    printf("The rear element is: %d\n", rear(queue));
    dequeue(queue);
    printf("The queue after dequeuing is:\n");
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("The queue is empty: %d\n", isEmpty(queue));
    return 0;
}