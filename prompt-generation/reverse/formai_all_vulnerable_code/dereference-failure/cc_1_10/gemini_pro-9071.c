//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear;
    int size;
    int *arr;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->rear == queue->size - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->arr[queue->rear] = data;
        printf("%d inserted into the queue.\n", data);
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    }
    else {
        int data = queue->arr[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
        printf("%d deleted from the queue.\n", data);
        return data;
    }
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    else {
        printf("Queue elements:\n");
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d  ", queue->arr[i]);
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);

    displayQueue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    displayQueue(queue);

    return 0;
}