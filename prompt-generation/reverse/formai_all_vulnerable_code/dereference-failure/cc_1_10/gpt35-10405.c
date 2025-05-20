//FormAI DATASET v1.0 Category: Queue ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF_SIZE 10
#define MAX_QUEUE_SIZE 5

typedef struct Queue {
    char buffer[MAX_QUEUE_SIZE][MAX_BUF_SIZE];
    int front, rear;
    int count;
} Queue;

Queue cq1, cq2;

void print_queue(Queue queue) {
    printf("\nQueue contents: ");
    for (int i = 0; i < queue.count; i++) {
        printf("%s", queue.buffer[(queue.front + i) % MAX_QUEUE_SIZE]);
    }
    printf("\n");
}

bool is_queue_empty(Queue queue) {
    return queue.count == 0 ? true : false;
}

bool is_queue_full(Queue queue) {
    return queue.count == MAX_QUEUE_SIZE ? true : false;
}

void enqueue(Queue *queue, char *item) {
    if (is_queue_full(*queue)) {
        printf("Queue is full!\n");
        return;
    }
    strcpy(queue->buffer[queue->rear], item);
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->count++;
}

char *dequeue(Queue *queue) {
    if (is_queue_empty(*queue)) {
        printf("Queue is empty! Returning null.\n");
        return NULL;
    }
    char *item = queue->buffer[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->count--;
    return item;
}

void producer() {
    printf("\nProducer: Entering producer...\n");

    for (int i = 1; i <= MAX_QUEUE_SIZE; i++) {
        char item[MAX_BUF_SIZE];
        sprintf(item, "Data Item %d\n", i);
        enqueue(&cq1, item);
        printf("Producer: Added item %d to cq1.\n", i);
    }

    printf("Producer: cq1 is now full. Handing over to consumer.\n");

    kill(getpid(), SIGUSR1);
}

void consumer() {
    printf("\nConsumer: Entering consumer...\n");

    while (!is_queue_empty(cq2)) {
        char *item = dequeue(&cq2);
        printf("Consumer: Consumed item: %s", item);
    }

    printf("Consumer: cq2 is now empty. Handing over to producer.\n");

    kill(getppid(), SIGUSR2);
}

void sigusr1_handler(int signum) {
    printf("Signal %d received by Producer. Handing over to consumer.\n", signum);

    while (!is_queue_empty(cq1)) {
        char *item = dequeue(&cq1);
        printf("Producer: Removing item: %s", item);
        enqueue(&cq2, item);
        printf("Producer: Added item to cq2.\n");
    }

    print_queue(cq2);

    printf("Producer: cq1 is now empty. Handing over to consumer.\n");

    kill(getppid(), SIGUSR1);
}

void sigusr2_handler(int signum) {
    printf("Signal %d received by Consumer. Handing over to producer.\n", signum);

    printf("Consumer: Done consuming. Handing over to producer.\n");

    producer();
}

int main() {
    cq1.front = 0;
    cq1.rear = 0;
    cq1.count = 0;

    cq2.front = 0;
    cq2.rear = 0;
    cq2.count = 0;

    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    printf("\nStarting Asynchronous C Queue Program\n");

    producer();

    while (true) {
        printf("Main Process: Waiting for signals...\n");
        sleep(1);
    }

    return 0;
}