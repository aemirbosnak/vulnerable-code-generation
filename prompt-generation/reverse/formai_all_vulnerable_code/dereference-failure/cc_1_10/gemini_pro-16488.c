//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

sem_t mutex;

void *producer(void *arg) {
    int *num = (int *)arg;
    while (1) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = *num;
        new_node->next = NULL;

        sem_wait(&mutex);
        if (head == NULL) {
            head = new_node;
        } else {
            struct node *curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
        sem_post(&mutex);

        printf("Produced %d\n", *num);
        *num += 1;
        usleep(100000);
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        sem_wait(&mutex);
        if (head == NULL) {
            sem_post(&mutex);
            usleep(100000);
            continue;
        }
        struct node *curr = head;
        head = head->next;
        sem_post(&mutex);

        printf("Consumed %d\n", curr->data);
        free(curr);
        usleep(100000);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    sem_init(&mutex, 0, 1);
    int num = 0;
    pthread_create(&producer_thread, NULL, producer, &num);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    sem_destroy(&mutex);
    return 0;
}