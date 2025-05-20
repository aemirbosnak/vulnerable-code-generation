//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the data structure to be visualized
struct node {
    int data;
    struct node *next;
};

// Define the semaphore to synchronize access to the data structure
sem_t semaphore;

// Define the function to be executed by each thread
void *thread_function(void *arg) {
    // Get the thread's ID
    int tid = *(int *)arg;

    // Acquire the semaphore
    sem_wait(&semaphore);

    // Access the data structure
    struct node *current_node = (struct node *)arg;

    // Perform some operations on the data structure
    current_node->data++;

    // Release the semaphore
    sem_post(&semaphore);

    // Return the thread's ID
    return (void *)tid;
}

// Main function
int main() {
    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // Create an array of threads
    pthread_t threads[10];

    // Create the head of the linked list
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    // Create the rest of the linked list
    for (int i = 1; i < 10; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    // Create and start the threads
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *)head);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the data structure
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d\n", current_node->data);
        current_node = current_node->next;
    }

    // Free the data structure
    current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}