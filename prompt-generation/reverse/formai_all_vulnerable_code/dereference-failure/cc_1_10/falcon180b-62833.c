//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
sem_t empty, full;

// Initialize semaphores
void init_semaphores() {
    sem_init(&empty, 0, 0);
    sem_init(&full, 0, 1);
}

// Push operation
void* push(void* arg) {
    int data = *(int*)arg;

    pthread_mutex_lock(&lock);

    while (sem_wait(&empty)!= 0) {
        printf("Operation failed due to full buffer\n");
        pthread_mutex_unlock(&lock);
        return NULL;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("Pushed data: %d\n", data);
    pthread_mutex_unlock(&lock);
    return NULL;
}

// Pop operation
void* pop(void* arg) {
    pthread_mutex_lock(&lock);

    while (sem_wait(&full)!= 0) {
        printf("Operation failed due to empty buffer\n");
        pthread_mutex_unlock(&lock);
        return NULL;
    }

    Node* temp = head;
    int data = temp->data;
    head = head->next;
    free(temp);

    printf("Popped data: %d\n", data);
    pthread_mutex_unlock(&lock);
    return NULL;
}

// Main function
int main() {
    init_semaphores();

    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, push, (void*)5);
    pthread_create(&thread_id[1], NULL, pop, NULL);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}