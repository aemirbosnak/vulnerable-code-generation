//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
struct Queue {
    struct Node *head;
    struct Node *tail;
    pthread_mutex_t lock;
};

// Create a new queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    return queue;
}

// Enqueue an element to the queue
void enqueue(struct Queue *queue, int data) {
    pthread_mutex_lock(&queue->lock);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    pthread_mutex_unlock(&queue->lock);
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    pthread_mutex_lock(&queue->lock);
    if (queue->head == NULL) {
        pthread_mutex_unlock(&queue->lock);
        return -1; // Queue is empty
    }
    struct Node *temp = queue->head;
    int data = temp->data;
    queue->head = temp->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    pthread_mutex_unlock(&queue->lock);
    return data;
}

// Print the queue
void printQueue(struct Queue *queue) {
    pthread_mutex_lock(&queue->lock);
    struct Node *temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    pthread_mutex_unlock(&queue->lock);
}

// Thread function to enqueue elements to the queue
void *enqueueThread(void *arg) {
    struct Queue *queue = (struct Queue*)arg;
    for (int i = 0; i < 10; i++) {
        enqueue(queue, i);
    }
    return NULL;
}

// Thread function to dequeue elements from the queue
void *dequeueThread(void *arg) {
    struct Queue *queue = (struct Queue*)arg;
    for (int i = 0; i < 10; i++) {
        int data = dequeue(queue);
        if (data != -1) {
            printf("Dequeued: %d\n", data);
        }
    }
    return NULL;
}

int main() {
    // Create a queue
    struct Queue *queue = createQueue();

    // Create threads to enqueue and dequeue elements
    pthread_t enqueueTid, dequeueTid;
    pthread_create(&enqueueTid, NULL, enqueueThread, queue);
    pthread_create(&dequeueTid, NULL, dequeueThread, queue);

    // Wait for threads to finish
    pthread_join(enqueueTid, NULL);
    pthread_join(dequeueTid, NULL);

    // Print the final state of the queue
    printQueue(queue);

    // Destroy the queue
    pthread_mutex_destroy(&queue->lock);
    free(queue);

    return 0;
}