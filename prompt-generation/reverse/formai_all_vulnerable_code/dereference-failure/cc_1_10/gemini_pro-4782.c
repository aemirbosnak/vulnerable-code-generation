//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Message queue to store the translated messages
struct msg_queue {
    char **messages;
    int head;
    int tail;
    int capacity;
};

// Mutex lock to protect the message queue
pthread_mutex_t queue_lock = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when messages are available in the queue
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;

// Create a new message queue with the given capacity
struct msg_queue *msg_queue_create(int capacity) {
    struct msg_queue *queue = malloc(sizeof(struct msg_queue));
    queue->messages = malloc(sizeof(char *) * capacity);
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = capacity;
    return queue;
}

// Destroy the message queue, freeing all memory
void msg_queue_destroy(struct msg_queue *queue) {
    for (int i = 0; i < queue->capacity; i++) {
        free(queue->messages[i]);
    }
    free(queue->messages);
    free(queue);
}

// Add a message to the message queue
void msg_queue_push(struct msg_queue *queue, char *message) {
    pthread_mutex_lock(&queue_lock);
    queue->messages[queue->tail] = message;
    queue->tail = (queue->tail + 1) % queue->capacity;
    if (queue->tail == queue->head) {
        // Queue is full, overwrite the oldest message
        queue->head = (queue->head + 1) % queue->capacity;
    }
    pthread_cond_signal(&queue_cond);
    pthread_mutex_unlock(&queue_lock);
}

// Get the next message from the message queue
char *msg_queue_pop(struct msg_queue *queue) {
    pthread_mutex_lock(&queue_lock);
    while (queue->head == queue->tail) {
        // Queue is empty, wait for a message
        pthread_cond_wait(&queue_cond, &queue_lock);
    }
    char *message = queue->messages[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    pthread_mutex_unlock(&queue_lock);
    return message;
}

// Alien language translator function
void *alien_language_translator(void *arg) {
    // Get the message queue from the argument
    struct msg_queue *queue = (struct msg_queue *)arg;

    // Loop until the program terminates
    while (1) {
        // Get the next message from the message queue
        char *message = msg_queue_pop(queue);

        // Translate the message from alien language to English
        char *translated_message = malloc(strlen(message) + 1);
        for (int i = 0; i < strlen(message); i++) {
            translated_message[i] = message[i] - 1;
        }
        translated_message[strlen(message)] = '\0';

        // Print the translated message
        printf("Translated message: %s\n", translated_message);

        // Free the translated message
        free(translated_message);
    }

    return NULL;
}

int main() {
    // Create a message queue with a capacity of 10 messages
    struct msg_queue *queue = msg_queue_create(10);

    // Create a thread pool with 4 threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, alien_language_translator, (void *)queue);
    }

    // Loop until the user enters "quit"
    while (1) {
        // Get the input message from the user
        char message[100];
        printf("Enter a message in alien language (or \"quit\" to exit): ");
        scanf("%s", message);

        // Check if the user entered "quit"
        if (strcmp(message, "quit") == 0) {
            break;
        }

        // Add the message to the message queue
        msg_queue_push(queue, message);
    }

    // Join all the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the message queue
    msg_queue_destroy(queue);

    return 0;
}