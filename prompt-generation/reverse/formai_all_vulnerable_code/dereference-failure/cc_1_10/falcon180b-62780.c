//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&lock);
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    pthread_mutex_unlock(&lock);
}

int dequeue() {
    int data = -1;
    pthread_mutex_lock(&lock);
    if (head!= NULL) {
        Node* temp = head;
        data = temp->data;
        head = temp->next;
        free(temp);
    } else {
        printf("Queue is empty\n");
    }
    pthread_mutex_unlock(&lock);
    return data;
}

void* thread_enqueue(void* arg) {
    int* data = (int*) arg;
    enqueue(*data);
    pthread_exit(0);
}

void* thread_dequeue(void* arg) {
    int data = dequeue();
    printf("Dequeued element: %d\n", data);
    pthread_exit(0);
}

int main() {
    pthread_t thread_id[10];
    int i;

    for (i = 0; i < 10; i++) {
        pthread_create(&thread_id[i], NULL, thread_enqueue, (void*) &i);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(thread_id[i], NULL);
    }

    for (i = 0; i < 10; i++) {
        pthread_create(&thread_id[i], NULL, thread_dequeue, NULL);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}