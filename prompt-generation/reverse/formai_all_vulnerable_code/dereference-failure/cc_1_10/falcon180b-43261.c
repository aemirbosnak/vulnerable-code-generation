//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    node *newnode = (node *) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    pthread_mutex_lock(&lock);
    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    pthread_mutex_unlock(&lock);
}

void dequeue() {
    pthread_mutex_lock(&lock);
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        node *temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
    pthread_mutex_unlock(&lock);
}

void *producer(void *arg) {
    int i;
    for (i = 1; i <= 10; i++) {
        enqueue(i);
        sleep(1);
    }
    return (void *) 0;
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        dequeue();
        sleep(1);
    }
    return (void *) 0;
}

int main() {
    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}