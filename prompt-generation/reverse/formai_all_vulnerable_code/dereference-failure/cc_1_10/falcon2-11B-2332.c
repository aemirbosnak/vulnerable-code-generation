//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUE_SIZE 10

struct queue_node {
    int data;
    struct queue_node* next;
};

typedef struct queue_node queue_node_t;

queue_node_t* head;
queue_node_t* tail;

int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == QUEUE_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    queue_node_t* new_node = (queue_node_t*)malloc(sizeof(queue_node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (rear == -1) {
        head = new_node;
        tail = new_node;
        rear++;
    } else {
        tail->next = new_node;
        tail = new_node;
        rear++;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = head->data;

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        free(head);
    }

    front++;

    return data;
}

void* consumer(void* arg) {
    int data;

    while (1) {
        data = dequeue();
        if (data == -1) {
            pthread_exit(NULL);
        }
        printf("Consumer: %d\n", data);
    }
}

void* producer(void* arg) {
    int data;

    while (1) {
        data = rand() % 100;
        enqueue(data);
        printf("Producer: %d\n", data);
    }
}

int main() {
    pthread_t consumer_thread;
    pthread_t producer_thread;

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(consumer_thread, NULL);
    pthread_join(producer_thread, NULL);

    return 0;
}