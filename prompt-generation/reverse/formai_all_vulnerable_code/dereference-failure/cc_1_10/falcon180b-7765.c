//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int data;
    struct node *next;
} Node;

Node *front, *rear;
pthread_mutex_t mutex;

void initQueue() {
    front = rear = NULL;
    pthread_mutex_init(&mutex, NULL);
}

void enqueue(int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    pthread_mutex_lock(&mutex);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    int data = -1;
    pthread_mutex_lock(&mutex);
    if (front!= NULL) {
        data = front->data;
        Node *temp = front;
        front = front->next;
        free(temp);
    }
    pthread_mutex_unlock(&mutex);
    return data;
}

void *consumerThread(void *arg) {
    int count = 0;
    while (count < 10) {
        int data = dequeue();
        printf("Consumer %d consumed %d\n", count + 1, data);
        count++;
        sleep(1);
    }
    pthread_exit(0);
}

void *producerThread(void *arg) {
    int count = 0;
    while (count < 10) {
        int data = count;
        enqueue(data);
        printf("Producer %d produced %d\n", count + 1, data);
        count++;
        sleep(1);
    }
    pthread_exit(0);
}

int main() {
    initQueue();
    pthread_t producerThreadId, consumerThreadId;

    pthread_create(&producerThreadId, NULL, producerThread, NULL);
    pthread_create(&consumerThreadId, NULL, consumerThread, NULL);

    pthread_join(producerThreadId, NULL);
    pthread_join(consumerThreadId, NULL);

    return 0;
}