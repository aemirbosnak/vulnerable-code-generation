//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct {
    int size;
    int capacity;
    int front;
    int rear;
    int* data;
} myQueue;

key_t key;
int shmid;
myQueue* q;

void enqueue(int item) {
    if (q->rear == q->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->data[q->rear++] = item;
}

int dequeue() {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->data[q->front++];
    return item;
}

void initQueue() {
    key = 5122;
    q = (myQueue*) malloc(sizeof(myQueue));
    q->size = 10;
    q->capacity = 10;
    q->front = 0;
    q->rear = 0;
    q->data = (int*) shmget(key, q->size * sizeof(int), 0666 | IPC_CREAT);
    shmid = shmget(key, q->size * sizeof(int), 0666 | IPC_CREAT);
}

int main() {
    initQueue();

    while (1) {
        int choice, item;

        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;

            case 3:
                printf("Queue: ");
                for (int i = q->front; i < q->rear; i++)
                    printf("%d ", q->data[i]);
                printf("\n");
                break;

            case 4:
                shmdt(q->data);
                shmctl(shmid, IPC_RMID, 0);
                free(q);
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}