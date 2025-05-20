//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_QUEUE_SIZE 100
#define QUEUE_KEY 1234
#define EMPTY 0
#define FULL 1

typedef struct {
    int front;
    int rear;
    int queue[MAX_QUEUE_SIZE];
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = EMPTY;
    q->rear = EMPTY;
    memset(q->queue, 0, sizeof(q->queue));
    return q;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full! Data not added.\n");
        return;
    }
    q->queue[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Data not removed.\n");
        return -1;
    }
    int data = q->queue[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return data;
}

int main() {
    int shmid;
    Queue *queue;
    key_t key = QUEUE_KEY;

    shmid = shmget(key, sizeof(Queue), IPC_CREAT | 0666);
    queue = (Queue *) shmget(shmid, sizeof(Queue), 0);

    queue = createQueue();

    printf("Producer started.\n");
    for (int i = 0; i < 10; i++) {
        enqueue(queue, i);
        printf("Enqueued: %d\n", i);
        sleep(1);
    }

    printf("Producer finished producing.\n");

    printf("Consumer started.\n");
    while (!isEmpty(queue)) {
        int data = dequeue(queue);
        printf("Dequeued: %d\n", data);
    }

    printf("Consumer finished consuming.\n");

    shmdt(queue);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}