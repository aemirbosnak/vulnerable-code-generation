//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4

// A linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// The linked list head
node_t *head;

// A semaphore to protect the linked list
sem_t list_lock;

// A thread function that adds a number to the linked list
void *add_number(void *arg) {
    int number = (int)arg;

    // Acquire the lock
    sem_wait(&list_lock);

    // Create a new node
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = number;
    new_node->next = NULL;

    // Add the new node to the end of the list
    node_t *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;

    // Release the lock
    sem_post(&list_lock);

    return NULL;
}

// A thread function that prints the linked list
void *print_list(void *arg) {
    // Acquire the lock
    sem_wait(&list_lock);

    // Print the list
    node_t *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Release the lock
    sem_post(&list_lock);

    return NULL;
}

int main() {
    // Initialize the linked list
    head = malloc(sizeof(node_t));
    head->data = 0;
    head->next = NULL;

    // Initialize the semaphore
    sem_init(&list_lock, 0, 1);

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, add_number, (void *)i);
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the list
    pthread_create(&threads[0], NULL, print_list, NULL);
    pthread_join(threads[0], NULL);

    // Destroy the semaphore
    sem_destroy(&list_lock);

    return 0;
}