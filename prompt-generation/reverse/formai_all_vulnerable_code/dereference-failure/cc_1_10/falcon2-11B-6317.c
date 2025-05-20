//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int* elements;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->size = size;
    queue->elements = (int*) malloc(sizeof(int) * size);
    return queue;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->size == 0) {
        printf("Queue is full\n");
    } else {
        queue->elements[queue->size] = value;
        queue->size++;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
    } else {
        int value = queue->elements[0];
        for (int i = 1; i < queue->size; i++) {
            queue->elements[i - 1] = queue->elements[i];
        }
        queue->size--;
        return value;
    }
}

int peek(struct Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
    } else {
        return queue->elements[0];
    }
}

void destroyQueue(struct Queue* queue) {
    free(queue->elements);
    free(queue);
}

int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 42);
    enqueue(queue, 41);
    enqueue(queue, 40);
    enqueue(queue, 39);
    enqueue(queue, 38);

    printf("Elements in Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", peek(queue));
    }
    printf("\n");

    dequeue(queue);

    printf("Elements in Queue after dequeueing: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", peek(queue));
    }
    printf("\n");

    destroyQueue(queue);

    return 0;
}