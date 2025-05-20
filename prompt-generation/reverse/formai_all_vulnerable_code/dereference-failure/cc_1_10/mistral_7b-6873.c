//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define QUEUE_SIZE 10
#define SHM_KEY 12345

typedef struct {
    int front, rear;
    int data[QUEUE_SIZE];
} Queue;

Queue *queue;
int shmid;

void init_queue() {
    queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Error allocating memory for queue");
        exit(EXIT_FAILURE);
    }

    memset(queue, 0, sizeof(Queue));

    if ((shmid = shmget(SHM_KEY, sizeof(Queue), 0644 | IPC_CREAT)) < 0) {
        perror("Error creating shared memory segment");
        exit(EXIT_FAILURE);
    }

    if (shmctl(shmid, IPC_SET, queue) < 0) {
        perror("Error setting shared memory segment");
        exit(EXIT_FAILURE);
    }
}

void enqueue(int data) {
    if ((queue->rear + 1) % QUEUE_SIZE == queue->front) {
        printf("Queue is full!\n");
        return;
    }

    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
}

int dequeue() {
    if (queue->front == queue->rear) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;

    return data;
}

void print_queue() {
    int i;

    if (queue->front == queue->rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: [");
    for (i = queue->front; i != queue->rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%d, ", queue->data[i]);
    }
    printf("%d]\n", queue->data[i]);
}

void destroy_queue() {
    shmctl(shmid, IPC_RMID, 0);
    free(queue);
}

int main() {
    init_queue();

    int i;
    for (i = 0; i < 15; i++) {
        enqueue(i);
        print_queue();
    }

    for (i = 0; i < 5; i++) {
        printf("Dequeued: %d\n", dequeue());
        print_queue();
    }

    destroy_queue();

    return 0;
}