//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

void enqueue(Queue *queue, int data) {
    if (queue->size == queue->rear) {
        printf("Queue Overflow!\n");
        return;
    }

    queue->arr[queue->rear] = data;
    queue->rear++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int data = queue->arr[queue->front];
    queue->front++;
    return data;
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = MAX_SIZE;
    queue->front = 0;
    queue->rear = 0;
    queue->arr = (int *)malloc(MAX_SIZE * sizeof(int));

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    int data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    free(queue->arr);
    free(queue);

    return 0;
}