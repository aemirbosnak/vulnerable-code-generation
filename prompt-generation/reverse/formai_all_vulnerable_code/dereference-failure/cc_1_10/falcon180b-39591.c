//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }

    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void* consumer(void* arg) {
    int sum = 0;

    while (1) {
        pthread_mutex_lock(&mutex);

        if (front!= NULL) {
            Node* temp = front;
            front = front->next;

            sum += temp->data;
            free(temp);
        } else {
            pthread_mutex_unlock(&mutex);
            break;
        }

        pthread_mutex_unlock(&mutex);
    }

    printf("Sum: %d\n", sum);
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