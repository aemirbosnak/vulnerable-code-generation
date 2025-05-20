//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define QUEUE_SIZE 10

typedef struct {
    int front, rear;
    int data[QUEUE_SIZE];
} Queue;

Queue *queue;
int shm_id;

void init_queue() {
    shm_id = shmget(IPC_PRIVATE, sizeof(Queue), 0666 | IPC_CREAT);
    queue = (Queue *) shmat(shm_id, NULL, 0);
    memset(queue, 0, sizeof(Queue));
    queue->front = queue->rear = 0;
}

int is_full() {
    return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}

int is_empty() {
    return queue->front == queue->rear;
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full!\n");
        return;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
}

int dequeue() {
    if (is_empty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    return data;
}

void print_queue() {
    int i;
    if (is_empty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: [");
    for (i = queue->front; i != queue->rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%d, ", queue->data[i]);
    }
    printf("%d]\n", queue->data[queue->rear]);
}

void destroy_queue() {
    shmdt(queue);
    shmctl(shm_id, IPC_RMID, NULL);
}

int main() {
    init_queue();

    pid_t pid = fork();

    if (pid == 0) { // Child process
        for (int i = 0; i < 6; i++) {
            enqueue(i * 2);
            sleep(1);
        }
        print_queue();
        destroy_queue();
        exit(0);
    } else { // Parent process
        for (int i = 0; i < 5; i++) {
            int data = dequeue();
            printf("Parent: Dequeued %d\n", data);
        }
        destroy_queue();
        wait(NULL);
        exit(0);
    }
}