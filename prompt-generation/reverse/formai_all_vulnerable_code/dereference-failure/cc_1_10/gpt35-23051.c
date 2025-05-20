//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NODE_COUNT 10
#define THREAD_COUNT 2

int graph[NODE_COUNT][NODE_COUNT] = {0};
pthread_t threads[THREAD_COUNT];

struct thread_params {
    int start_node;
    int end_node;
};

void* connect_nodes(void* args) {
    struct thread_params* params = (struct thread_params*) args;
    int i, j;

    for (i = params->start_node; i < params->end_node; i++) {
        for (j = 0; j < NODE_COUNT; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = 1;
            }
        }
    }

    return NULL;
}

void print_graph() {
    int i, j;
    printf("Graph Representation:\n");
    for (i = 0; i < NODE_COUNT; i++) {
        printf("%d: ", i);

        for (j = 0; j < NODE_COUNT; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    int nodes_per_thread = NODE_COUNT / THREAD_COUNT;

    for (i = 0; i < THREAD_COUNT; i++) {
        struct thread_params* params = malloc(sizeof(struct thread_params));
        params->start_node = i * nodes_per_thread;
        params->end_node = (i + 1) * nodes_per_thread;

        pthread_create(&threads[i], NULL, connect_nodes, params);
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    print_graph();

    return 0;
}