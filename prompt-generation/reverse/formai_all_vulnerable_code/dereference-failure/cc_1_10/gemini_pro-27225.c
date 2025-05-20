//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

typedef struct node {
    int id;
    double arrival_time;
    double service_time;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

void initialize_queue(queue_t *queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

bool is_empty_queue(queue_t *queue) {
    return queue->size == 0;
}

void enqueue(queue_t *queue, node_t *node) {
    if (is_empty_queue(queue)) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->size++;
}

node_t *dequeue(queue_t *queue) {
    if (is_empty_queue(queue)) {
        return NULL;
    }
    node_t *node = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    queue->size--;
    return node;
}

void destroy_queue(queue_t *queue) {
    while (!is_empty_queue(queue)) {
        free(dequeue(queue));
    }
}

double generate_arrival_time() {
    return (double)rand() / (double)RAND_MAX * 1000.0;
}

double generate_service_time() {
    return (double)rand() / (double)RAND_MAX * 1000.0;
}

void print_node(node_t *node) {
    printf("Baggage %d arrived at %.2f and will take %.2f to scan.\n", node->id, node->arrival_time, node->service_time);
}

int main() {
    srand(time(NULL));
    int num_bags = 100;
    queue_t queue;
    initialize_queue(&queue);
    for (int i = 0; i < num_bags; i++) {
        node_t *node = malloc(sizeof(node_t));
        node->id = i + 1;
        node->arrival_time = generate_arrival_time();
        node->service_time = generate_service_time();
        enqueue(&queue, node);
    }
    while (!is_empty_queue(&queue)) {
        node_t *node = dequeue(&queue);
        print_node(node);
        free(node);
    }
    destroy_queue(&queue);
    return 0;
}