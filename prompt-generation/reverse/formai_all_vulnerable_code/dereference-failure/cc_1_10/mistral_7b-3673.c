//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_QUEUE_SIZE 10
#define QUEUE_KEY 1234

typedef struct {
    int front;
    int rear;
    int size;
    int *queue;
} MyQueue;

void initQueue(MyQueue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = MAX_QUEUE_SIZE;
    q->queue = (int*)shmget(QUEUE_KEY, sizeof(int) * q->size, 0666 | IPC_CREAT);
}

int isFull(MyQueue *q) {
    return (q->rear + 1) % q->size == q->front;
}

int isEmpty(MyQueue *q) {
    return q->front == q->rear;
}

void enqueue(MyQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }

    q->queue[q->rear] = value;
    q->rear = (q->rear + 1) % q->size;
}

int dequeue(MyQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = q->queue[q->front];
    q->front = (q->front + 1) % q->size;
    return value;
}

void printQueue(MyQueue *q) {
    for (int i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    MyQueue q;
    initQueue(&q);

    pid_t pid = fork();

    if (pid > 0) { // Parent process
        int i;
        for (i = 0; i < 5; i++) {
            enqueue(&q, i);
            printf("Parent: Enqueued %d\n", i);
        }
        printQueue(&q);
        printf("Parent: Dequeued %d\n", dequeue(&q));

        waitpid(pid, NULL, 0);
        printf("Parent: Child exited\n");
    } else if (pid == 0) { // Child process
        while (!isEmpty(&q)) {
            printf("Child: Dequeued %d\n", dequeue(&q));
        }
        exit(0);
    }

    shmctl(QUEUE_KEY, IPC_RMID, 0);
    return 0;
}