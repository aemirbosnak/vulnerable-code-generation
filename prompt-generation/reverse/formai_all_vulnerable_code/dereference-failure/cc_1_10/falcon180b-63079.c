//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    pthread_mutex_lock(&mutex);
    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    pthread_mutex_unlock(&mutex);

    printf("Enqueued: %d\n", data);
}

void dequeue() {
    int data;
    node* temp = front;

    pthread_mutex_lock(&mutex);
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        data = front->data;
        front = front->next;
        free(temp);
    }
    pthread_mutex_unlock(&mutex);

    printf("Dequeued: %d\n", data);
}

void* consumer(void* arg) {
    int i = 0;

    while (i < 10) {
        dequeue();
        sleep(1);
        i++;
    }

    return NULL;
}

void* producer(void* arg) {
    int i = 0;

    while (i < 10) {
        enqueue(i);
        sleep(1);
        i++;
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    int i, j;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            pthread_create(&thread_id[i], NULL, producer, NULL);
        } else {
            pthread_create(&thread_id[i], NULL, consumer, NULL);
        }
    }

    for (j = 0; j < 2; j++) {
        pthread_join(thread_id[j], NULL);
    }

    return 0;
}