//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(const char *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to add an item to the queue
void enqueue(Queue *q, const char *data) {
    Node *newNode = createNode(data);
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
    q->size++;
    printf("Enqueued: %s\n", data);
}

// Function to remove an item from the queue
char* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to dequeue.\n");
        return NULL;
    }
    Node *temp = q->front;
    char *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    printf("Dequeued: %s\n", data);
    return data;
}

// Function to get the front item of the queue
char* front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, no front element.\n");
        return NULL;
    }
    return q->front->data;
}

// Function to get the rear item of the queue
char* rear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, no rear element.\n");
        return NULL;
    }
    return q->rear->data;
}

// Function to get the size of the queue
int getSize(Queue *q) {
    return q->size;
}

// Function to free the queue
void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        free(dequeue(q));
    }
    free(q);
}

// Test the Queue implementation
void testQueue() {
    Queue *q = createQueue();

    enqueue(q, "Alice");
    enqueue(q, "Bob");
    enqueue(q, "Charlie");

    printf("Current front: %s\n", front(q));
    printf("Current rear: %s\n", rear(q));
    printf("Current size: %d\n", getSize(q));

    char *dequeued1 = dequeue(q);
    free(dequeued1);

    printf("After one dequeue:\n");
    printf("Current front: %s\n", front(q));
    printf("Current rear: %s\n", rear(q));
    printf("Current size: %d\n", getSize(q));

    dequeue(q);
    dequeue(q);

    dequeue(q); // Trying to dequeue from an empty queue

    freeQueue(q);
}

int main() {
    testQueue();
    return 0;
}