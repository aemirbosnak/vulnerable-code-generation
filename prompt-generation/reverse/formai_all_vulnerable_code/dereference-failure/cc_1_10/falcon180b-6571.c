//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#define MAX 5

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

sem_t mutex;
sem_t full;
sem_t empty;

void init() {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, MAX);
}

void enqueue(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    sem_wait(&empty);
    sem_wait(&mutex);

    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    sem_post(&mutex);
    sem_post(&full);
}

void dequeue() {
    sem_wait(&full);
    sem_wait(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        sem_post(&mutex);
        sem_post(&empty);
        return;
    }

    node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    sem_post(&mutex);
    sem_post(&empty);

    printf("Dequeued element is %d\n", temp->data);
    free(temp);
}

void* consumer(void* arg) {
    int i;
    for (i = 0; i < 10; i++) {
        dequeue();
        sleep(1);
    }
    return NULL;
}

void* producer(void* arg) {
    int i;
    for (i = 0; i < 10; i++) {
        enqueue(i);
        sleep(1);
    }
    return NULL;
}

int main() {
    init();

    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}