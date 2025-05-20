//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define QUEUE_SIZE 10
#define BUFFER_SIZE 20

typedef struct {
    int front;
    int rear;
    int count;
    char data[QUEUE_SIZE][BUFFER_SIZE];
} Queue;

void enqueue(Queue *q, char *str) {
    if (q->count == QUEUE_SIZE) {
        fprintf(stderr, "Queue is full!\n");
        return;
    }

    strcpy(q->data[q->rear], str);
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->count++;
}

char *dequeue(Queue *q) {
    if (q->count == 0) {
        fprintf(stderr, "Queue is empty!\n");
        return NULL;
    }

    char *str = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;

    return str;
}

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    q->count = 0;

    return q;
}

int main() {
    Queue *q = createQueue();

    char str[BUFFER_SIZE];
    int i;

    printf("Queue implemented in a surprised style!\n");
    printf("Adding elements to the queue one by one...\n");

    for (i = 0; i < 10; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(str, BUFFER_SIZE, stdin);
        enqueue(q, str);
    }

    printf("\nElements in the queue:\n");
    while (q->count > 0) {
        printf("%s", dequeue(q));
    }

    printf("\nQueue is empty!\n");

    free(q);
    return 0;
}