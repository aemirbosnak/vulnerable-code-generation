//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define QUEUE_SIZE 10
#define SHM_KEY 1234

typedef struct {
    int front;
    int rear;
    int count;
    int queue[QUEUE_SIZE];
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
    return queue;
}

int isFull(Queue *queue) {
    return (queue->count == QUEUE_SIZE);
}

int isEmpty(Queue *queue) {
    return (queue->count == 0);
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->queue[queue->rear] = data;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->count++;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->queue[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->count--;
    return data;
}

int main() {
    int shm_id;
    Queue *queue;
    char *shm_ptr;

    queue = createQueue();

    shm_id = shmget(SHM_KEY, sizeof(Queue), IPC_CREAT | 0666);
    shm_ptr = shmget(SHM_KEY, sizeof(Queue), 0);

    memcpy(shm_ptr, queue, sizeof(Queue));

    printf("Shared memory queue created with size %d\n", QUEUE_SIZE);

    pid_t pid = fork();

    if (pid > 0) { // Parent process
        int data = 0;

        while (1) {
            sleep(1);
            if (!isFull(queue)) {
                enqueue(queue, getpid());
                printf("Enqueued PID %d\n", getpid());
            }

            if (!isEmpty(queue)) {
                data = dequeue(queue);
                printf("Dequeued PID %d\n", data);
            }
        }
    } else if (pid == 0) { // Child process
        int data;

        while (1) {
            sleep(2);
            if (!isFull(queue)) {
                enqueue(queue, getpid());
                printf("Child enqueued PID %d\n", getpid());
            }

            if (!isEmpty(queue)) {
                data = dequeue(queue);
                printf("Child dequeued PID %d\n", data);
            }
        }
    }

    shmctl(shm_id, IPC_RMID, 0);

    return 0;
}