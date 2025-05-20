//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// Structure to represent a node in the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure to represent the queue
typedef struct Queue {
    Node *front;
    Node *rear;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} Queue;

// Initialize a new queue
Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);
    return queue;
}

// Enqueue an item to the queue
void enqueue(Queue* queue, int data) {
    // Acquire the lock
    pthread_mutex_lock(&queue->lock);
    
    // Wait until the queue is not full
    while(queue->rear != NULL && queue->rear->next != queue->front) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    
    // Create a new node
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    // If the queue is empty, set both front and rear to the new node
    if(queue->front == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    }
    // Otherwise, add the new node to the rear of the queue
    else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    
    // Signal that the queue is not empty
    pthread_cond_signal(&queue->not_empty);
    
    // Release the lock
    pthread_mutex_unlock(&queue->lock);
}

// Dequeue an item from the queue
int dequeue(Queue* queue) {
    // Acquire the lock
    pthread_mutex_lock(&queue->lock);
    
    // Wait until the queue is not empty
    while(queue->front == NULL) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    
    // Get the data from the front of the queue
    int data = queue->front->data;
    
    // Remove the front node from the queue
    queue->front = queue->front->next;
    
    // If the queue is now empty, set both front and rear to NULL
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    
    // Signal that the queue is not full
    pthread_cond_signal(&queue->not_full);
    
    // Release the lock
    pthread_mutex_unlock(&queue->lock);
    
    // Return the data from the front of the queue
    return data;
}

// Destroy the queue
void destroy_queue(Queue* queue) {
    // Acquire the lock
    pthread_mutex_lock(&queue->lock);
    
    // Free all the nodes in the queue
    while(queue->front != NULL) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    
    // Destroy the lock and condition variables
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_empty);
    pthread_cond_destroy(&queue->not_full);
    
    // Free the queue
    free(queue);
}

// Main function
int main() {
    // Create a new queue
    Queue* queue = create_queue();
    
    // Create a thread to enqueue items to the queue
    pthread_t producer_thread;
    pthread_create(&producer_thread, NULL, (void*) enqueue, queue);
    
    // Create a thread to dequeue items from the queue
    pthread_t consumer_thread;
    pthread_create(&consumer_thread, NULL, (void*) dequeue, queue);
    
    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    // Destroy the queue
    destroy_queue(queue);
    
    return 0;
}