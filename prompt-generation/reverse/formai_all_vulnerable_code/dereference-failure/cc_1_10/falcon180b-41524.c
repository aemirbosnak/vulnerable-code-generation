//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_NODES 10

struct node {
    int id;
    int degree;
    int *neighbors;
};

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    struct node *graph = (struct node *) malloc(NUM_NODES * sizeof(struct node));

    for (int i = 0; i < NUM_NODES; i++) {
        graph[i].id = i;
        graph[i].degree = 0;
        graph[i].neighbors = malloc(NUM_NODES * sizeof(int));
        for (int j = 0; j < NUM_NODES; j++) {
            graph[i].neighbors[j] = 0;
        }
    }

    int start_node = thread_id * (NUM_NODES / NUM_THREADS);
    int end_node = (thread_id + 1) * (NUM_NODES / NUM_THREADS) - 1;

    for (int i = start_node; i <= end_node; i++) {
        graph[i].degree = rand() % (NUM_NODES - 1) + 1;
        for (int j = 0; j < graph[i].degree; j++) {
            int neighbor = rand() % NUM_NODES;
            while (graph[neighbor].degree >= NUM_NODES - 1) {
                neighbor = rand() % NUM_NODES;
            }
            graph[i].neighbors[graph[neighbor].degree] = neighbor;
            graph[neighbor].degree++;
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}