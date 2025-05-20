//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        newNode->prev = NULL;
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue underflow error: Cannot dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;
    if (queue->front != NULL)
        queue->front->prev = NULL;
    else
        queue->rear = NULL; // Queue becomes empty

    free(temp);
    queue->size--;
    printf("Dequeued: %d\n", value);
    return value;
}

int peekFront(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty. Cannot peek front element.\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}

int peekRear(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty. Cannot peek rear element.\n");
        exit(EXIT_FAILURE);
    }
    return queue->rear->data;
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clearQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    printf("Queue cleared.\n");
}

void freeQueue(Queue* queue) {
    clearQueue(queue);
    free(queue);
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    displayQueue(queue);
    
    printf("Front element: %d\n", peekFront(queue));
    printf("Rear element: %d\n", peekRear(queue));

    dequeue(queue);
    displayQueue(queue);
    
    clearQueue(queue);
    displayQueue(queue);

    freeQueue(queue);
    return 0;
}