//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Queue node we will reuse for both operations
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Our queue will be a collection of nodes
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Our queue operations, yeay!
void enqueue(struct Queue *queue, int data);
int dequeue(struct Queue *queue);
void display(struct Queue *queue);

int main() {
    // Create a new shiny queue
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;

    // Let's enqueue some data
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Display the queue, just to be sure
    display(queue);

    // Now, let's dequeue a few items
    printf("Dequeued %d from the queue\n", dequeue(queue));
    printf("Dequeued %d from the queue\n", dequeue(queue));
    printf("Dequeued %d from the queue\n", dequeue(queue));

    // Display the queue, again, just to be sure
    display(queue);

    return 0;
}

void enqueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty, can't dequeue\n");
        return -1;
    }

    int data = queue->front->data;
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void display(struct Queue *queue) {
    struct QueueNode *temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}