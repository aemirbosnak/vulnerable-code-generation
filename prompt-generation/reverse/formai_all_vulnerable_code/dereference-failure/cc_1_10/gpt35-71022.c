//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *new_queue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->array = (int *) malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

int is_empty(Queue *queue) {
    return (queue->front == -1);
}

int is_full(Queue *queue) {
    return ((queue->front == 0 && queue->rear == queue->capacity - 1) || queue->front == queue->rear + 1);
}

void enqueue(Queue *queue, int item) {
    if (is_full(queue)) {
        printf("Queue Overflow!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == queue->capacity - 1) {
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->array[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == queue->capacity - 1) {
        queue->front = 0;
    } else {
        queue->front++;
    }
    return item;
}

void display(Queue *queue) {
    int i;
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    i = queue->front;
    printf("Queue Elements: ");
    if (queue->front <= queue->rear) {
        while (i <= queue->rear) {
            printf("%d ", queue->array[i]);
            i++;
        }
    } else {
        while (i < queue->capacity) {
            printf("%d ", queue->array[i]);
            i++;
        }
        i = 0;
        while (i <= queue->rear) {
            printf("%d ", queue->array[i]);
            i++;
        }
    }
    printf("\n");
}

int main() {
    Queue *queue = new_queue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);

    display(queue);

    enqueue(queue, 70);

    return 0;
}