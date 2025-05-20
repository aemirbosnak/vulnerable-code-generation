//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    int data;
    struct node* temp_node;

    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return -1;
    } else {
        temp_node = front;
        data = front->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp_node);
    }

    pthread_mutex_unlock(&mutex);

    return data;
}

void* consumer(void* arg) {
    int data;

    while (1) {
        data = dequeue();
        if (data == -1) {
            break;
        }
        printf("Consumed: %d\n", data);
    }

    return 0;
}

void* producer(void* arg) {
    int data;

    for (int i = 0; i < 10; i++) {
        data = i;
        enqueue(data);
        printf("Produced: %d\n", data);
        sleep(1);
    }

    return 0;
}

int main() {
    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    for (int i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}