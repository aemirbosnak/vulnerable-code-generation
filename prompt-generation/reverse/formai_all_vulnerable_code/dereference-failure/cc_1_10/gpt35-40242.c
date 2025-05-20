//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// struct to represent baggage
typedef struct baggage {
    int id;
    int weight;
} Baggage;

// queue to hold baggage
Baggage *queue[100];
int front = 0, rear = -1, items = 0;

// mutex and semaphores for synchronization
pthread_mutex_t mutex;
sem_t full, empty;

// function to add baggage to the queue
void enqueue(Baggage *b) {
    rear = (rear + 1) % 100;
    queue[rear] = b;
    items++;
}

// function to remove baggage from the queue
Baggage *dequeue() {
    Baggage *b = queue[front];
    front = (front + 1) % 100;
    items--;
    return b;
}

// function to generate random baggage
Baggage *generate_baggage() {
    Baggage *b = (Baggage *) malloc(sizeof(Baggage));
    b->id = rand() % 10000 + 1;
    b->weight = rand() % 30 + 1;
    return b;
}

// function for baggage handlers
void *handler(void *arg) {
    int id = *((int *) arg);
    while (1) {
        sem_wait(&full); // wait until there is baggage in the queue
        pthread_mutex_lock(&mutex); // acquire the lock
        Baggage *b = dequeue(); // get the next baggage
        pthread_mutex_unlock(&mutex); // release the lock
        sem_post(&empty); // signal that there is now an empty spot in the queue
        
        printf("Handler %d is handling baggage with id %d and weight %d\n", id, b->id, b->weight);
        sleep(rand() % 5 + 1); // simulate handling
        printf("Handler %d is done handling baggage with id %d\n", id, b->id);
    }
}

int main() {
    srand(time(NULL));
    
    // initialize mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 100);
    
    // create baggage handlers
    pthread_t handlers[5];
    int handler_ids[5];
    for (int i = 0; i < 5; i++) {
        handler_ids[i] = i + 1;
        pthread_create(&handlers[i], NULL, handler, (void *) &handler_ids[i]);
    }
    
    // generate and enqueue random baggage
    for (int i = 0; i < 100; i++) {
        Baggage *b = generate_baggage();
        enqueue(b);
        sem_post(&full); // signal that there is now baggage in the queue
    }
    
    // wait for the baggage handlers to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(handlers[i], NULL);
    }
    
    // clean up
    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;
}