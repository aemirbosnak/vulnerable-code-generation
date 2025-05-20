//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    int next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Error: Could not create queue.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int isFull(Queue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Error: Could not enqueue data.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Could not dequeue data.\n");
        exit(1);
    }
    QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        QueueNode *temp = queue->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    display(queue);
    enqueue(queue, 40);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}