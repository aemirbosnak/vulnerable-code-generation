//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to initialize a new queue
Queue* newQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to insert an element at the rear of the queue
void enqueue(Queue *queue, int data) {
    Node *node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = queue->front->data;
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

// Function to print the elements in the queue
void printQueue(Queue *queue) {
    Node *temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create a thread for enqueue operation
void *enqueueThread(void *param) {
    Queue *queue = (Queue*)param;
    int data;
    for (int i = 1; i <= 10; i++) {
        data = rand() % 100;
        enqueue(queue, data);
        printf("Enqueued %d\n", data);
        sleep(1);
    }
    return NULL;
}

// Function to create a thread for dequeue operation
void *dequeueThread(void *param) {
    Queue *queue = (Queue*)param;
    int data;
    for (int i = 1; i <= 10; i++) {
        data = dequeue(queue);
        printf("Dequeued %d\n", data);
        sleep(1);
    }
    return NULL;
}

int main() {
    Queue *queue = newQueue();
    pthread_t enqueueThreadID, dequeueThreadID;
    int enqueueThreadExitStatus = 0, dequeueThreadExitStatus = 0;
    enqueueThreadID = pthread_create(&enqueueThreadID, NULL, enqueueThread, (void *)queue);
    dequeueThreadID = pthread_create(&dequeueThreadID, NULL, dequeueThread, (void *)queue);
    pthread_join(enqueueThreadID, &enqueueThreadExitStatus);
    pthread_join(dequeueThreadID, &dequeueThreadExitStatus);
    printQueue(queue);
    return 0;
}