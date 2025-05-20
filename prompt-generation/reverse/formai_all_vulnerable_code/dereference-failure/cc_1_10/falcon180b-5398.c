//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int count = 0;

sem_t mutex;
sem_t empty;
sem_t full;

void init() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, MAX_QUEUE_SIZE);
    sem_init(&full, 0, 0);
}

void enqueue(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    sem_wait(&mutex);
    sem_wait(&empty);

    if (count == MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        sem_post(&mutex);
        return;
    }

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    count++;
    sem_post(&mutex);
    sem_post(&full);
}

void dequeue() {
    Node* temp_front;
    int data;

    sem_wait(&mutex);
    sem_wait(&full);

    if (front == NULL) {
        printf("Queue is empty\n");
        sem_post(&mutex);
        return;
    }

    temp_front = front;
    front = front->next;
    data = temp_front->data;
    free(temp_front);

    count--;
    sem_post(&mutex);
    sem_post(&empty);

    printf("Dequeued element: %d\n", data);
}

void* producer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        enqueue(i);
        sleep(1);
    }

    return NULL;
}

void* consumer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        dequeue();
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int i;

    init();

    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    for (i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}