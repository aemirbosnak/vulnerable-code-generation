//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_QUEUE_SIZE 10

typedef struct CLQueueNode {
    int data;
    struct CLQueueNode *next;
} CLQueueNode;

typedef struct CircularLinkedQueue {
    CLQueueNode *head;
    CLQueueNode *tail;
    int size;
    int capacity;
} CircularLinkedQueue;

CircularLinkedQueue *createCircularLinkedQueue() {
    CircularLinkedQueue *queue = (CircularLinkedQueue *) calloc(1, sizeof(CircularLinkedQueue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = MAX_QUEUE_SIZE;
    return queue;
}

int isFull(CircularLinkedQueue *queue) {
    return queue->size == queue->capacity;
}

int isEmpty(CircularLinkedQueue *queue) {
    return queue->size == 0;
}

void enqueue(CircularLinkedQueue *queue, int data) {
    CLQueueNode *newNode = (CLQueueNode *) malloc(sizeof(CLQueueNode));
    newNode->data = data;

    if (queue->size == queue->capacity) {
        // Overflow, remove the head node
        if (queue->head == queue->tail) {
            free(newNode);
            printf("Error: Queue Overflow\n");
            return;
        }

        CLQueueNode *temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
    }

    if (isEmpty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

int dequeue(CircularLinkedQueue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue Underflow\n");
        return -1;
    }

    int data = queue->head->data;
    CLQueueNode *temp = queue->head;
    queue->head = queue->head->next;

    if (queue->size == queue->capacity) {
        // Underflow, tail moves to head to maintain circular buffer
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        queue->tail = queue->head;
    }

    free(temp);
    queue->size--;

    return data;
}

void printQueue(CircularLinkedQueue *queue) {
    if (isEmpty(queue)) {
        printf("Empty Queue\n");
        return;
    }

    CLQueueNode *temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    CircularLinkedQueue *queue = createCircularLinkedQueue();

    // Enqueue elements
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);

    // Check capacity and print queue
    printf("Queue Size: %d, Capacity: %d\n", queue->size, queue->capacity);
    printQueue(queue);

    // Dequeue elements
    int data;
    for (int i = 0; i < 3; i++) {
        data = dequeue(queue);
        printf("Dequeued: %d\n", data);
    }

    // Check size and print queue
    printf("Queue Size: %d, Capacity: %d\n", queue->size, queue->capacity);
    printQueue(queue);

    // Enqueue an element and check if it's full
    enqueue(queue, 20);
    printf("Queue Size: %d, Capacity: %d\n", queue->size, queue->capacity);
    printQueue(queue);

    return 0;
}