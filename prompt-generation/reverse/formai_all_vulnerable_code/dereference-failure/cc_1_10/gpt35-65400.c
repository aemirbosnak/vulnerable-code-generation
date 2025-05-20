//FormAI DATASET v1.0 Category: Data mining ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct node Node;
typedef struct queue Queue;

struct node {
    int data;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
    int size;
};

Queue* queue_create() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void queue_enqueue(Queue* q, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    if (q->size == 0) {
        q->head = q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->size++;
}

int queue_dequeue(Queue* q) {
    if (q->size == 0) {
        return -1;
    }
    Node* node = q->head;
    int val = node->data;
    q->head = node->next;
    if (q->size == 1) {
        q->tail = NULL;
    }
    free(node);
    q->size--;
    return val;
}

void* producer(void* arg) {
    Queue* q = (Queue*) arg;
    for (int i = 0; i < 10; i++) {
        queue_enqueue(q, i);
        printf("Producer: Enqueued %d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    Queue* q = (Queue*) arg;
    int val;
    while ((val = queue_dequeue(q)) != -1) {
        printf("Consumer: Dequeued %d\n", val);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    Queue* q = queue_create();
    pthread_t tid_producer, tid_consumer;
    pthread_create(&tid_producer, NULL, producer, q);
    pthread_create(&tid_consumer, NULL, consumer, q);
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);
    return 0;
}