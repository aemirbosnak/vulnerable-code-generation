//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

void initQueue(struct queue *q) {
    q->head = NULL;
    q->tail = NULL;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->cond, NULL);
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&q->mutex);
    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    pthread_cond_signal(&q->cond);
    pthread_mutex_unlock(&q->mutex);
}

int dequeue(struct queue *q) {
    pthread_mutex_lock(&q->mutex);
    while (q->head == NULL) {
        pthread_cond_wait(&q->cond, &q->mutex);
    }

    struct node *temp = q->head;
    int data = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);

    pthread_mutex_unlock(&q->mutex);
    return data;
}

void *producer(void *args) {
    struct queue *q = (struct queue *)args;
    for (int i = 0; i < 1000; i++) {
        enqueue(q, i);
    }
    return NULL;
}

void *consumer(void *args) {
    struct queue *q = (struct queue *)args;
    for (int i = 0; i < 1000; i++) {
        int data = dequeue(q);
        printf("%d\n", data);
    }
    return NULL;
}

int main() {
    struct queue q;
    initQueue(&q);

    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread, NULL, producer, &q);
    pthread_create(&consumer_thread, NULL, consumer, &q);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}