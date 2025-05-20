//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_QUEUE_SIZE 100

typedef struct {
    int value;
    int color_code;
} item_t;

item_t queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value, int color_code) {
    if ((rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear].value = value;
    queue[rear].color_code = color_code;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Dequeued value: %d, color code: %d\n", queue[front].value, queue[front].color_code);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
}

void *producer(void *arg) {
    int i = *(int *) arg;

    for (int j = 0; j < 10; j++) {
        enqueue(i, j);
        sleep(1);
    }

    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        dequeue();
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, producer, (void *) i);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}