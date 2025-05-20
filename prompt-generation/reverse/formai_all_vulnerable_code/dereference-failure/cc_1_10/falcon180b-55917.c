//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

sem_t lock;

void init_semaphore() {
    sem_init(&lock, 0, 1);
}

void push(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    sem_wait(&lock);

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    sem_post(&lock);
}

void pop() {
    sem_wait(&lock);

    if (head == NULL) {
        printf("List is empty\n");
        sem_post(&lock);
        return;
    }

    Node* temp = head;
    head = head->next;

    printf("Popped element: %d\n", temp->data);

    free(temp);

    sem_post(&lock);
}

void* thread_push(void* arg) {
    int data = *(int*) arg;
    push(data);
    return NULL;
}

void* thread_pop(void* arg) {
    pop();
    return NULL;
}

int main() {
    init_semaphore();

    pthread_t threads[MAX_THREADS];
    int thread_data[MAX_THREADS];

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i] = i;
        pthread_create(&threads[i], NULL, thread_push, (void*) &thread_data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}