//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("Enqueued %d\n", value);

    pthread_mutex_unlock(&mutex);
}

void dequeue() {
    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    printf("Dequeued %d\n", temp->data);

    free(temp);
    pthread_mutex_unlock(&mutex);
}

void* consumer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        sleep(1);
        dequeue();
    }

    return NULL;
}

void* producer(void* arg) {
    int i;

    for (i = 1; i <= 10; i++) {
        enqueue(i);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}