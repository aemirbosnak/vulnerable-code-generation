//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Queue node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Structure for Queue
typedef struct queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(Queue* queue, int data) {
    Node* node = createNode(data);
    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    free(temp);

    return data;
}

// Function to print the queue
void printQueue(Queue* queue) {
    Node* current = queue->front;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to check if the queue is empty
bool isQueueEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to get the size of the queue
int getQueueSize(Queue* queue) {
    return queue->size;
}

int main() {
    Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue elements
    printf("Dequeued elements: ");
    int dequeuedElements[3];
    for (int i = 0; i < 3; i++) {
        dequeuedElements[i] = dequeue(queue);
        printf("%d ", dequeuedElements[i]);
    }

    // Print the queue after dequeue
    printf("Queue after dequeue: ");
    printQueue(queue);

    // Free memory
    free(queue);

    return 0;
}