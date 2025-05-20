//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: calm
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
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

int shm_id;
Queue *queue;

void init_queue() {
    shm_id = shmget(QUEUE_KEY, sizeof(Queue), IPC_CREAT | 0666);
    queue = (Queue *)shmget(shm_id, sizeof(Queue), 0);
    memset(queue, 0, sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(int data) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->items[queue->rear] = data;
}

int dequeue() {
    if (queue->front == -1 || queue->front == queue->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return data;
}

int main() {
    init_queue();

    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        int data;

        while (1) {
            data = dequeue();
            if (data == -1) {
                break;
            }
            printf("Parent dequeued %d\n", data);
        }

        printf("Parent exiting...\n");
        exit(0);
    } else {
        int i;

        for (i = 0; i < 15; i++) {
            enqueue(i);
        }

        printf("Child enqueued 15 elements\n");

        wait(&status);

        printf("Child exiting...\n");
        exit(0);
    }

    return 0;
}