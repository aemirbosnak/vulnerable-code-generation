//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
 
#define MAX_SIZE 100
 
// Define our custom data structure
typedef struct _Data {
    int value;
    struct _Data *next;
} Data;
 
// Declare the head and tail pointers for our linked list
Data *head = NULL, *tail = NULL;
 
// Define the mutex and condition variables for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
 
// Define our producer function
void *producer(void *arg) {
    int i, value;
 
    for (i = 1; i <= MAX_SIZE; i++) {
        // Generate a random value between 0 and 99
        value = rand() % 100;
 
        // Allocate memory for the new data node
        Data *newData = (Data *) malloc(sizeof(Data));
        newData->value = value;
        newData->next = NULL;
 
        // Lock the mutex and add the new data node to the end of the linked list
        pthread_mutex_lock(&mutex);
 
        if (tail == NULL) {
            head = tail = newData;
        } else {
            tail->next = newData;
            tail = newData;
        }
 
        // Signal the consumer that there is new data available
        pthread_cond_signal(&cond_full);
 
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }
 
    // Signal the consumer that there are no new data nodes to be produced
    pthread_mutex_lock(&mutex);
    tail = (Data *) malloc(sizeof(Data));
    tail->value = -1;
    tail->next = NULL;
 
    pthread_cond_signal(&cond_full);
    pthread_mutex_unlock(&mutex);
 
    pthread_exit(NULL);
}
 
// Define our consumer function
void *consumer(void *arg) {
    Data *current;
 
    while (1) {
        // Lock the mutex and check if there is data in the queue
        pthread_mutex_lock(&mutex);
 
        while (head == NULL) {
            // If there is no data, wait for the producer to signal there is new data available
            pthread_cond_wait(&cond_full, &mutex);
        }
 
        // Check if we have reached the end of the data queue
        if (head == tail && tail->value == -1) {
            pthread_mutex_unlock(&mutex);
            break;
        }
 
        // Take the first element from the queue
        current = head;
        head = head->next;
 
        // Signal the producer that there is space for new data
        pthread_cond_signal(&cond_empty);
 
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
 
        // Display the value of the dequeued node
        printf("Dequeued value: %d\n", current->value);
        free(current);
    }
 
    pthread_exit(NULL);
}
 
int main() {
    pthread_t prod_thread, cons_thread;
 
    // Create the producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);
 
    // Wait for the producer and consumer threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
 
    // Destroy the mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_empty);
    pthread_cond_destroy(&cond_full);
 
    return 0;
}