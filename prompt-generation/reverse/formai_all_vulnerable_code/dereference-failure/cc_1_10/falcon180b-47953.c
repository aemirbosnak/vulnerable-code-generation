//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
void createQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if queue is full
int isFull(struct Queue* queue) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

// Function to add element to queue
void enqueue(struct Queue* queue, int element) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full. Cannot enqueue %d\n", element);
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove element from queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    return element;
}

// Function to display queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        struct Node* temp = queue->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    createQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    display(&queue);

    int element = dequeue(&queue);
    printf("Dequeued element: %d\n", element);

    display(&queue);

    element = dequeue(&queue);
    printf("Dequeued element: %d\n", element);

    display(&queue);

    enqueue(&queue, 50);
    enqueue(&queue, 60);

    display(&queue);

    return 0;
}