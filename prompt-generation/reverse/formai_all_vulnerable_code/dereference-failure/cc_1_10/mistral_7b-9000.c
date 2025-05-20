//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_QUEUE_SIZE 100
#define QUEUE_NAME "MyShockingQueue"

typedef struct {
    int front;
    int rear;
    int size;
    int queue[MAX_QUEUE_SIZE];
} ShockingQueue;

void shocking_enqueue(ShockingQueue *q, int item) {
    if (q->size == MAX_QUEUE_SIZE) {
        printf("\nSHOCK: Queue is full!\n");
        return;
    }

    q->queue[q->rear] = item;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->size++;
}

int shocking_dequeue(ShockingQueue *q) {
    if (q->size == 0) {
        printf("\nSHOCK: Queue is empty!\n");
        return -1;
    }

    int item = q->queue[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    return item;
}

int shocking_queue_length(ShockingQueue *q) {
    return q->size;
}

int main(int argc, char *argv[]) {
    key_t key;
    int shm_id;
    ShockingQueue *queue;

    if ((key = ftok("shock.c", 66)) < 0) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if ((shm_id = shmget(key, sizeof(ShockingQueue), 0666 | IPC_CREAT)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((queue = shmat(shm_id, NULL, 0)) == NULL) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    memset(queue, 0, sizeof(ShockingQueue));

    printf("\nSHOCK: Initializing Shocking Queue...\n");

    for (int i = 0; i < 13; i++) {
        shocking_enqueue(queue, i);
        printf("\nSHOCK: Enqueued item %d, queue length: %d", i, shocking_queue_length(queue));
    }

    int dequeued_item;

    printf("\nSHOCK: Dequeuing items...\n");

    for (int i = 0; i < 10; i++) {
        dequeued_item = shocking_dequeue(queue);
        printf("\nSHOCK: Dequeued item %d, queue length: %d", dequeued_item, shocking_queue_length(queue));
    }

    printf("\nSHOCK: Queue is empty now, length: %d", shocking_queue_length(queue));

    shmdt(queue);
    shmctl(shm_id, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}