//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL && rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued %d\n", temp->data);
    free(temp);
}

void* producer(void* arg) {
    int id = *(int*)arg;
    int count = 0;

    while (count < 10) {
        pthread_mutex_lock(&mutex);
        enqueue(id*100 + count);
        pthread_mutex_unlock(&mutex);
        count++;
        sleep(1);
    }

    return NULL;
}

void* consumer(void* arg) {
    int id = *(int*)arg;
    int count = 0;

    while (count < 10) {
        pthread_mutex_lock(&mutex);
        dequeue();
        pthread_mutex_unlock(&mutex);
        count++;
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    int producer_data[2] = {1, 2};
    int consumer_data[2] = {3, 4};

    for (int i = 0; i < 2; i++) {
        pthread_create(&thread_id[i], NULL, (i % 2 == 0)? producer : consumer, (void*)&producer_data[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}