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

void enqueue(int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    int value = -1;
    node* temp = NULL;

    pthread_mutex_lock(&mutex);

    if (front!= NULL) {
        temp = front;
        front = front->next;
        value = temp->data;
        free(temp);
    }

    pthread_mutex_unlock(&mutex);

    return value;
}

void* consumer(void* arg) {
    int value;

    while (1) {
        pthread_mutex_lock(&mutex);
        value = dequeue();
        pthread_mutex_unlock(&mutex);

        if (value == -1)
            break;

        printf("Consumer %d consumed %d\n", (int) pthread_self(), value);
        sleep(1);
    }

    return NULL;
}

void* producer(void* arg) {
    int value = 0;

    while (1) {
        pthread_mutex_lock(&mutex);
        enqueue(value);
        value++;
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int i;

    for (i = 0; i < 2; i++) {
        pthread_create(&thread_id[i], NULL, (i == 0)? producer : consumer, NULL);
    }

    for (i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}