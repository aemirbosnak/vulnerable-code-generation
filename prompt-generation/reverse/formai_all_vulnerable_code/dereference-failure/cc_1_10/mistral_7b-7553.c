//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    char data[QUEUE_SIZE][20];
} CircularQueue;

CircularQueue *createQueue() {
    CircularQueue *queue = (CircularQueue *) malloc(sizeof(CircularQueue));
    queue->front = queue->rear = -1;
    return queue;
}

int isQueueFull(CircularQueue *queue) {
    return ((queue->rear + 1) % QUEUE_SIZE == queue->front);
}

int isQueueEmpty(CircularQueue *queue) {
    return (queue->front == queue->rear);
}

void enqueue(CircularQueue *queue, const char *str) {
    if (isQueueFull(queue)) {
        fprintf(stderr, "Queue is full\n");
        return;
    }

    strcpy(queue->data[++queue->rear % QUEUE_SIZE], str);
}

const char *dequeue(CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        return NULL;
    }

    const char *str = queue->data[queue->front++ % QUEUE_SIZE];
    if (queue->front > queue->rear)
        queue->front = queue->rear;

    return str;
}

void printQueue(const CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = queue->front; i != queue->rear; i = (i + 1) % QUEUE_SIZE)
        printf("%s\n", queue->data[i]);
}

void destroyQueue(CircularQueue *queue) {
    free(queue);
}

key_t shm_key = 6666;
int shm_id;
CircularQueue *queue;

int main() {
    shm_id = shmget(shm_key, sizeof(CircularQueue), 0666 | IPC_CREAT);
    queue = (CircularQueue *) shmget(shm_key, sizeof(CircularQueue), 0);

    queue = createQueue();

    enqueue(queue, "Hello");
    enqueue(queue, "World");
    enqueue(queue, "Genius");

    printQueue(queue);

    const char *str = dequeue(queue);
    printf("Dequeued: %s\n", str);

    printQueue(queue);

    destroyQueue(queue);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}