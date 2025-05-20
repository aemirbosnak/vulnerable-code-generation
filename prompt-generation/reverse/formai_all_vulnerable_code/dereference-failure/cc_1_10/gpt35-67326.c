//FormAI DATASET v1.0 Category: Scientific ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct Node { 
    int data;
    struct Node* next; 
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    pthread_mutex_t lock;
    pthread_cond_t notEmpty;
} Queue;

Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->notEmpty, NULL);
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->head == NULL;
}

void enqueue(Queue* queue, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;

    pthread_mutex_lock(&queue->lock);
    if(isEmpty(queue)) {
        queue->head = node;
    }
    else {
        queue->tail->next = node;
    }
    queue->tail = node;
    pthread_mutex_unlock(&queue->lock);

    pthread_cond_signal(&queue->notEmpty);
}

int dequeue(Queue* queue) {
    pthread_mutex_lock(&queue->lock);
    while(isEmpty(queue)) {
        pthread_cond_wait(&queue->notEmpty, &queue->lock);
    }

    Node* node = queue->head;
    int value = node->data;
    queue->head = node->next;
    free(node);

    pthread_mutex_unlock(&queue->lock);
    return value;
}

void* producer(void* arg) {
    Queue* queue = (Queue*)arg;

    for(int i = 0; i < 10; i++) {
        enqueue(queue, i);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    Queue* queue = (Queue*)arg;

    for(int i = 0; i < 10; i++) {
        int value = dequeue(queue);
        printf("Dequeued: %d\n", value);
    }

    pthread_exit(NULL);
}

int main() {
    Queue* queue = initQueue();

    pthread_t producerId, consumerId;
    pthread_create(&producerId, NULL, &producer, queue);
    pthread_create(&consumerId, NULL, &consumer, queue);

    pthread_join(producerId, NULL);
    pthread_join(consumerId, NULL);

    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->notEmpty);
    free(queue);
    return 0;
}