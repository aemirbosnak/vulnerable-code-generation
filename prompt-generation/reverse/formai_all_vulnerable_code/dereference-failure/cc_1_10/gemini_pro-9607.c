//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear;
    int capacity;
    int *queue_arr;
};

struct queue* createQueue(int capacity) {
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->queue_arr = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct queue* queue) {
    return (queue->front == -1);
}

int isFull(struct queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

void enqueue(struct queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->queue_arr[queue->rear] = item;
    }
}

int dequeue(struct queue* queue) {
    int item;
    if (isEmpty(queue)) {
        return (-1);
    }
    else {
        item = queue->queue_arr[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return (item);
    }
}

int front(struct queue* queue) {
    if (isEmpty(queue)) {
        return (-1);
    }
    return (queue->queue_arr[queue->front]);
}

int rear(struct queue* queue) {
    if (isEmpty(queue)) {
        return (-1);
    }
    return (queue->queue_arr[queue->rear]);
}

void display(struct queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements:\n");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->queue_arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));

    enqueue(queue, 6);
    display(queue);

    dequeue(queue);
    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }

    return 0;
}