//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_QUEUE_SIZE 10
#define QUEUE_NAME "MyQueue"
#define ELEMENT_SIZE sizeof(int)

struct QueueElement {
    int data;
    int next;
};

typedef struct QueueElement QueueElement;

void enqueue(int data) {
    int shmid = shmget(IPC_PRIVATE, sizeof(QueueElement) * (MAX_QUEUE_SIZE + 1), 0666 | IPC_CREAT);
    QueueElement *queue = (QueueElement *) shmat(shmid, NULL, 0);

    if (queue == (void *) -1) {
        perror("Error attaching shared memory\n");
        exit(EXIT_FAILURE);
    }

    if (queue->next == -1 && queue->data == -1) {
        queue->data = data;
        queue->next = 0;
    } else {
        QueueElement *current = queue;
        while (current->next != -1) {
            current = (QueueElement *) ((long) current + ELEMENT_SIZE);
        }
        current->next = (int) (long) queue + sizeof(QueueElement);
        queue->data = data;
    }

    shmdt(queue);
    shmctl(shmid, IPC_SET, 0666);
}

int dequeue() {
    int shmid = shmget(IPC_PRIVATE, sizeof(QueueElement) * (MAX_QUEUE_SIZE + 1), 0666 | IPC_EXCL | IPC_CREAT);
    QueueElement *queue = (QueueElement *) shmat(shmid, NULL, 0);

    if (queue == (void *) -1) {
        perror("Error attaching shared memory\n");
        exit(EXIT_FAILURE);
    }

    if (queue->next == -1 && queue->data == -1) {
        int data = queue->data;
        shmdt(queue);
        shmctl(shmid, IPC_RMID, 0);
        return data;
    }

    QueueElement *current = queue;
    while (current->next != 0) {
        current = (QueueElement *) ((long) current + ELEMENT_SIZE);
    }

    int data = current->next;
    current->next = queue->next;
    queue->next = data;

    shmdt(queue);
    shmctl(shmid, IPC_SET, 0666);

    return data;
}

int main() {
    int i;

    for (i = 0; i < 15; i++) {
        enqueue(i);
        printf("Enqueued %d\n", i);
    }

    for (i = 0; i < 10; i++) {
        printf("Dequeued %d\n", dequeue());
    }

    return 0;
}