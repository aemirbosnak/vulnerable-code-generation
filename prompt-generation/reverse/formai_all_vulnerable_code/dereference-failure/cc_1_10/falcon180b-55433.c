//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_BAGS 10
#define NUM_THREADS 4

typedef struct {
    int id;
    char *destination;
} Bag;

Bag bags[NUM_BAGS];

int thread_ids[NUM_THREADS];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
    int thread_id = *(int *) arg;
    Bag *bag;

    for (int i = 0; i < NUM_BAGS; i++) {
        pthread_mutex_lock(&lock);
        if (bags[i].destination!= NULL) {
            bag = &bags[i];
            bags[i].destination = NULL;
        }
        pthread_mutex_unlock(&lock);

        if (bag!= NULL) {
            printf("Thread %d is handling bag %d with destination %s\n", thread_id, bag->id, bag->destination);
            free(bag->destination);
        }
    }

    return NULL;
}

int main() {
    int i;

    for (i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].destination = malloc(10 * sizeof(char));
        sprintf(bags[i].destination, "Destination %d", i + 1);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&thread_ids[i], NULL, thread_function, &thread_ids[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    return 0;
}