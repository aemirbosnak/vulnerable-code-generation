//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
} graph;

void add_node(graph *g) {
    node *new_node = malloc(sizeof(node));
    new_node->data = rand() % 100;
    new_node->next = g->head;
    g->head = new_node;
}

void *add_node_thread(void *arg) {
    int sleep_time = (rand() % 10) + 1;
    printf("Sleeping for %d seconds...\n", sleep_time);
    sleep(sleep_time);
    add_node((graph *) arg);
    return NULL;
}

int main() {
    graph *g = malloc(sizeof(graph));
    g->head = NULL;
    
    pthread_t threads[10];
    
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, add_node_thread, (void *) g);
    }
    
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    for (node *node = g->head; node!= NULL; node = node->next) {
        printf("Node data: %d\n", node->data);
    }
    
    free(g);
    
    return 0;
}