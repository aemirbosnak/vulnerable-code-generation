//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 5

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

sem_t mutex;
sem_t empty;
sem_t full;

void init() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
}

void enqueue(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    sem_wait(&empty);
    sem_wait(&mutex);

    if(front == NULL) {
        front = new_node;
        rear = new_node;
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

    if(front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = front;
        front = front->next;
        free(temp);

        if(front == NULL) {
            rear = NULL;
        }
    }

    sem_post(&mutex);
    sem_post(&empty);
}

void* consumer(void* arg) {
    int i;

    for(i=0; i<10; i++) {
        dequeue();
        printf("Consumer %d consumed %d\n", i+1, i);
        sleep(1);
    }

    pthread_exit(0);
}

void* producer(void* arg) {
    int i;

    for(i=1; i<=10; i++) {
        enqueue(i);
        printf("Producer produced %d\n", i);
        sleep(1);
    }

    pthread_exit(0);
}

int main() {
    pthread_t thread_id[2];
    int i;

    init();

    for(i=0; i<2; i++) {
        if(i==0) {
            pthread_create(&thread_id[i], NULL, producer, NULL);
        } else {
            pthread_create(&thread_id[i], NULL, consumer, NULL);
        }
    }

    for(i=0; i<2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}