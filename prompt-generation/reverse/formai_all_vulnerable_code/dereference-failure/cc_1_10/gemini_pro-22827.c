//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// Our very own interprocess communicator!
typedef struct {
    char *msg;
    int size;
} msg_t;

// Our very own semaphore for synchronization!
sem_t sem;

// Our very own thread function for sending messages!
void *sender(void *arg) {
    // Get the message from the argument
    msg_t *msg = (msg_t *)arg;

    // Wait for the semaphore to be signaled
    sem_wait(&sem);

    // Send the message
    printf("Sender: %s\n", msg->msg);

    // Signal the semaphore to wake up the receiver
    sem_post(&sem);

    // Free the message
    free(msg->msg);
    free(msg);

    // Return NULL to indicate success
    return NULL;
}

// Our very own thread function for receiving messages!
void *receiver(void *arg) {
    // Wait for the semaphore to be signaled
    sem_wait(&sem);

    // Receive the message
    printf("Receiver: %s\n", (char *)arg);

    // Signal the semaphore to wake up the sender
    sem_post(&sem);

    // Return NULL to indicate success
    return NULL;
}

int main() {
    // Initialize the semaphore
    sem_init(&sem, 0, 0);

    // Create the sender thread
    pthread_t sender_thread;
    pthread_create(&sender_thread, NULL, sender, NULL);

    // Create the receiver thread
    pthread_t receiver_thread;
    pthread_create(&receiver_thread, NULL, receiver, "Hello from the receiver!");

    // Wait for the threads to finish
    pthread_join(sender_thread, NULL);
    pthread_join(receiver_thread, NULL);

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}