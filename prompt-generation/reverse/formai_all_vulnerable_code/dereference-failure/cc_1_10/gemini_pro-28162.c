//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
    int size;
    bool is_full;
} queue_t;

queue_t *create_queue(int size) {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) {
        printf("Error: could not allocate memory for queue.\n");
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = size;
    queue->is_full = false;

    return queue;
}

void destroy_queue(queue_t *queue) {
    node_t *current = queue->front;

    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

bool is_empty(queue_t *queue) {
    return queue->front == NULL;
}

bool is_full(queue_t *queue) {
    return queue->size == queue->rear->data - queue->front->data + 1;
}

void enqueue(queue_t *queue, int data) {
    if (is_full(queue)) {
        printf("Error: queue is full.\n");
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: could not allocate memory for new node.\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

int dequeue(queue_t *queue) {
    if (is_empty(queue)) {
        printf("Error: queue is empty.\n");
        return -1;
    }

    int data = queue->front->data;
    node_t *old_front = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(old_front);

    queue->size--;

    return data;
}

void print_queue(queue_t *queue) {
    node_t *current = queue->front;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    queue_t *queue = create_queue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    print_queue(queue);

    dequeue(queue);
    dequeue(queue);

    print_queue(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);

    print_queue(queue);

    destroy_queue(queue);

    return 0;
}