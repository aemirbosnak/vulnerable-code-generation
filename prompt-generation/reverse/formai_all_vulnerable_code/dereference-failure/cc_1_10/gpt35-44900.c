//FormAI DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10
// Queue implementation using circular buffer
typedef struct {
    int front;
    int rear;
    int size;
    int buffer[MAX_QUEUE_SIZE];
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int isFull(Queue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Unable to enqueue.\n");
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->buffer[queue->rear] = data;
        queue->size++;
        printf("Enqueued %d in the queue. Queue size is now %d.\n", data, queue->size);
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Unable to dequeue.\n");
        return -1;
    } else {
        int data = queue->buffer[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->size--;
        printf("Dequeued %d from the queue. Queue size is now %d.\n", data, queue->size);
        return data;
    }
}

sem_t semaphore;

void *consumer(void *queue) {
    Queue *q = (Queue *) queue;
    while (1) {
        sem_wait(&semaphore);
        dequeue(q);
        sem_post(&semaphore);
        sleep(1); // Delay to simulate work being done
    }
}

void *producer(void *queue) {
    Queue *q = (Queue *) queue;
    while (1) {
        sem_wait(&semaphore);
        int data = rand() % 100;
        enqueue(q, data);
        sem_post(&semaphore);
        sleep(1); // Delay to simulate work being done
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Queue *queue = createQueue();
    sem_init(&semaphore, 0, 1); // Initialize semaphore with value 1
    
    pthread_t consumer_thread, producer_thread;
    pthread_create(&consumer_thread, NULL, consumer, queue);
    pthread_create(&producer_thread, NULL, producer, queue);
    
    pthread_join(consumer_thread, NULL);
    pthread_join(producer_thread, NULL);
    
    sem_destroy(&semaphore);
    free(queue);

    return 0;
}