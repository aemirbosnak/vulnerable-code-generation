//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* This is a surreal implementation of a queue in C */

struct Queue {
    int front;
    int rear;
    int array[10];
};

void enqueue(struct Queue* queue, int value) {
    if (queue->rear >= 10) {
        printf("The queue is full!\n");
        return;
    }
    queue->array[queue->rear++] = value;
    printf("\nA fish with the value %d swims into the queue!\n", value);
}

int dequeue(struct Queue* queue) {
    if (queue->front >= queue->rear) {
        printf("\nThere are no more fishes in the queue!\n");
        return -1;
    }
    int value = queue->array[queue->front++];
    printf("\nA fish with the value %d swims out of the queue!\n", value);
    return value;
}

void print_queue(struct Queue* queue) {
    printf("\nThe fishes currently in the queue are: ");
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {

    srand(time(NULL));
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = 0;

    for (int i = 0; i < 5; i++) {
        int value = rand() % 10 + 1;
        enqueue(queue, value);
    }

    print_queue(queue);

    printf("\nThe first fish in the queue has been eaten!\n");
    dequeue(queue);

    print_queue(queue);

    printf("\nA new fish with value 7 is trying to swim into the queue!\n");
    enqueue(queue, 7);

    print_queue(queue);

    printf("\nThe second fish in the queue has been eaten!\n");
    dequeue(queue);

    print_queue(queue);

    printf("\nThe third fish in the queue has been eaten!\n");
    dequeue(queue);

    print_queue(queue);

    free(queue);

    return 0;
}