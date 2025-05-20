//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct Queue {
    struct Node *front, *rear;
    int size;
} Queue;

// Function to create a queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Function to get the size of the queue
int size(Queue *queue) {
    return queue->size;
}

// Function to print the queue
void printQueue(Queue *queue) {
    struct Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    printf("Size of the queue: %d\n", size(queue));

    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    printQueue(queue);

    printf("Size of the queue: %d\n", size(queue));

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}