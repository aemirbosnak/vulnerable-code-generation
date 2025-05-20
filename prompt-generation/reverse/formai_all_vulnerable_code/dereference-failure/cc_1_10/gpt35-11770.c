//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// maximum size of the buffer queue
#define MAX_BUFFER_SIZE 50

// number of producer and consumer threads
#define PRODUCER_THREADS 5
#define CONSUMER_THREADS 3

// structure that represents a baggage
typedef struct {
    int id;     // baggage id
    int weight; // baggage weight in kg
} baggage_t;

// variables for buffer queue
baggage_t buffer[MAX_BUFFER_SIZE];
int buffer_front = 0, buffer_end = 0, buffer_count = 0;

// variable for keeping track of number of baggage processed
int baggage_processed = 0;

// function for producing a baggage
baggage_t produce_baggage(int id) {
    baggage_t b;
    b.id = id;
    b.weight = rand() % 50 + 1; // random weight
    return b;
}

// function for printing a baggage
void print_baggage(baggage_t b) {
    printf("Baggage ID: %d | Weight: %d kg\n", b.id, b.weight);
}

// function for adding a baggage to the buffer queue
void add_to_buffer(baggage_t b) {
    buffer[buffer_end] = b;
    buffer_end = (buffer_end + 1) % MAX_BUFFER_SIZE;
    buffer_count++;
}

// function for removing a baggage from the buffer queue
baggage_t remove_from_buffer() {
    baggage_t b = buffer[buffer_front];
    buffer_front = (buffer_front + 1) % MAX_BUFFER_SIZE;
    buffer_count--;
    return b;
}

// producer function
void *producer(void *arg) {
    int id = *((int *) arg);
    free(arg);

    while (1) {
        // produce a new baggage
        baggage_t b = produce_baggage(baggage_processed + 1);
        printf("Producer %d produced a new baggage:\n", id);
        print_baggage(b);

        // add the baggage to the buffer queue
        while (buffer_count == MAX_BUFFER_SIZE) {
            // wait if the buffer is full
            printf("Producer %d waiting to add baggage to buffer...\n", id);
            sleep(1);
        }
        add_to_buffer(b);
        printf("Producer %d added a baggage to the buffer queue.\n", id);

        // increment the number of baggage processed
        baggage_processed++;

        // wait for a random amount of time before producing the next baggage
        int wait_time = rand() % 5 + 1;
        printf("Producer %d waiting for %d seconds...\n", id, wait_time);
        sleep(wait_time);
    }

    pthread_exit(NULL);
}

// consumer function
void *consumer(void *arg) {
    int id = *((int *) arg);
    free(arg);

    while (1) {
        // remove a baggage from the buffer queue
        while (buffer_count == 0) {
            // wait if the buffer is empty
            printf("Consumer %d waiting to remove baggage from buffer...\n", id);
            sleep(1);
        }
        baggage_t b = remove_from_buffer();
        printf("Consumer %d removed a baggage from the buffer queue:\n", id);
        print_baggage(b);

        // wait for a random amount of time before consuming the next baggage
        int wait_time = rand() % 5 + 1;
        printf("Consumer %d waiting for %d seconds...\n", id, wait_time);
        sleep(wait_time);
    }

    pthread_exit(NULL);
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // create producer threads
    for (int i = 1; i <= PRODUCER_THREADS; i++) {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_t tid;
        pthread_create(&tid, NULL, producer, (void *) index);
    }

    // create consumer threads
    for (int i = 1; i <= CONSUMER_THREADS; i++) {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_t tid;
        pthread_create(&tid, NULL, consumer, (void *) index);
    }

    // wait for all threads to finish (this should never happen)
    pthread_exit(NULL);

    return 0;
}