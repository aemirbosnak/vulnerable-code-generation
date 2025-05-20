//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100

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

void init_queue(struct queue *q) {
    q->head = NULL;
    q->tail = NULL;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->cond, NULL);
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&q->mutex);
    if (q->tail == NULL) {
        q->head = new_node;
    } else {
        q->tail->next = new_node;
    }
    q->tail = new_node;
    pthread_mutex_unlock(&q->mutex);

    pthread_cond_signal(&q->cond);
}

int dequeue(struct queue *q) {
    int data;
    struct node *temp;

    pthread_mutex_lock(&q->mutex);
    while (q->head == NULL) {
        pthread_cond_wait(&q->cond, &q->mutex);
    }
    temp = q->head;
    data = temp->data;
    q->head = temp->next;
    free(temp);
    pthread_mutex_unlock(&q->mutex);

    return data;
}

void *producer(void *arg) {
    struct queue *q = (struct queue *) arg;
    int i;

    for (i = 0; i < 10; i++) {
        enqueue(q, i);
        printf("Produced: %d\n", i);
        sleep(1);
    }

    return NULL;
}

void *consumer(void *arg) {
    struct queue *q = (struct queue *) arg;
    int data;

    while (1) {
        data = dequeue(q);
        printf("Consumed: %d\n", data);
        sleep(1);
    }

    return NULL;
}

int main() {
    struct queue q;
    pthread_t thread_id[2];

    init_queue(&q);

    pthread_create(&thread_id[0], NULL, producer, &q);
    pthread_create(&thread_id[1], NULL, consumer, &q);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}