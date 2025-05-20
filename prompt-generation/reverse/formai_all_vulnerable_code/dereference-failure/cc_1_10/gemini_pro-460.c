//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

// Define the maximum size of the queue
#define MAX_QUEUE_SIZE 10

// Define the structure of a queue node
typedef struct queue_node {
    int data;
    struct queue_node *next;
} queue_node;

// Define the structure of a queue
typedef struct queue {
    queue_node *head;
    queue_node *tail;
    int size;
} queue;

// Initialize a queue
void queue_init(queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

// Enqueue an item to the queue
void queue_enqueue(queue *q, int data) {
    // Create a new queue node
    queue_node *new_node = (queue_node *)malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;

    // If the queue is empty, the new node is the head and the tail
    if (q->size == 0) {
        q->head = new_node;
        q->tail = new_node;
    }
    // Otherwise, the new node is added to the tail of the queue
    else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    // Increment the size of the queue
    q->size++;
}

// Dequeue an item from the queue
int queue_dequeue(queue *q) {
    // If the queue is empty, return -1
    if (q->size == 0) {
        return -1;
    }

    // Get the data from the head of the queue
    int data = q->head->data;

    // If the queue has only one item, the head and the tail are set to NULL
    if (q->size == 1) {
        q->head = NULL;
        q->tail = NULL;
    }
    // Otherwise, the head of the queue is moved to the next node
    else {
        q->head = q->head->next;
    }

    // Decrement the size of the queue
    q->size--;

    // Return the data from the head of the queue
    return data;
}

// Get the size of the queue
int queue_size(queue *q) {
    return q->size;
}

// Print the queue
void queue_print(queue *q) {
    queue_node *current = q->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Create a thread that will enqueue items to the queue
void *enqueue_thread(void *arg) {
    queue *q = (queue *)arg;

    for (int i = 0; i < 10; i++) {
        // Sleep for a random amount of time
        usleep(rand() % 1000000);

        // Enqueue an item to the queue
        queue_enqueue(q, i);
    }

    return NULL;
}

// Create a thread that will dequeue items from the queue
void *dequeue_thread(void *arg) {
    queue *q = (queue *)arg;

    while (1) {
        // Sleep for a random amount of time
        usleep(rand() % 1000000);

        // Dequeue an item from the queue
        int data = queue_dequeue(q);

        // If the queue is empty, break out of the loop
        if (data == -1) {
            break;
        }

        // Print the data that was dequeued
        printf("Dequeued: %d\n", data);
    }

    return NULL;
}

int main() {
    // Create a queue
    queue q;
    queue_init(&q);

    // Create a thread that will enqueue items to the queue
    pthread_t enqueue_thread_id;
    pthread_create(&enqueue_thread_id, NULL, enqueue_thread, &q);

    // Create a thread that will dequeue items from the queue
    pthread_t dequeue_thread_id;
    pthread_create(&dequeue_thread_id, NULL, dequeue_thread, &q);

    // Join the threads
    pthread_join(enqueue_thread_id, NULL);
    pthread_join(dequeue_thread_id, NULL);

    return 0;
}