//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// Structure for queue node
struct Node {
    int data;
    struct Node* next;
};

// Queue class definition
typedef struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
} Queue;

// Function to enqueue an element
void enqueue(Queue* q, int data) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->size == 0) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->head;
    int data = temp->data;
    if (q->size == 1) {
        q->head = q->tail = NULL;
    } else {
        q->head = temp->next;
        free(temp);
    }
    q->size--;
    return data;
}

// Function to check if queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to check if queue is full
int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

// Function to get the size of the queue
int getSize(Queue* q) {
    return q->size;
}

// Function to get the front element of the queue
int peek(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->head->data;
}

// Function to clear the queue
void clear(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

// Function to print the elements of the queue
void toString(Queue* q) {
    struct Node* temp = q->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to test the queue implementation
void testQueue() {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Queue size: %d\n", getSize(&q));
    printf("Front element: %d\n", peek(&q));

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    printf("Queue size: %d\n", getSize(&q));
    printf("Front element: %d\n", peek(&q));

    clear(&q);

    printf("Queue size: %d\n", getSize(&q));
    printf("Front element: %d\n", peek(&q));
}

int main() {
    testQueue();
    return 0;
}