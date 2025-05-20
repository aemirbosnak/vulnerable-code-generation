//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

queue_t *queue_create() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void queue_destroy(queue_t *queue) {
    if (queue == NULL) {
        return;
    }

    while (queue->head != NULL) {
        node_t *node = queue->head;
        queue->head = node->next;
        free(node);
    }

    free(queue);
}

int queue_is_empty(const queue_t *queue) {
    if (queue == NULL) {
        return 1;
    }

    return queue->size == 0;
}

int queue_enqueue(queue_t *queue, int data) {
    if (queue == NULL) {
        return -1;
    }

    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        return -1;
    }

    node->data = data;
    node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = node;
    } else {
        queue->tail->next = node;
    }

    queue->tail = node;
    queue->size++;

    return 0;
}

int queue_dequeue(queue_t *queue, int *data) {
    if (queue == NULL || queue_is_empty(queue)) {
        return -1;
    }

    node_t *node = queue->head;
    *data = node->data;

    queue->head = node->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(node);
    queue->size--;

    return 0;
}

int queue_peek(const queue_t *queue, int *data) {
    if (queue == NULL || queue_is_empty(queue)) {
        return -1;
    }

    *data = queue->head->data;

    return 0;
}

int queue_size(const queue_t *queue) {
    if (queue == NULL) {
        return -1;
    }

    return queue->size;
}

int main() {
    queue_t *queue = queue_create();
    if (queue == NULL) {
        return -1;
    }

    // Enqueue some data
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        if (queue_enqueue(queue, data[i]) != 0) {
            return -1;
        }
    }

    // Print the queue
    printf("Queue: [");
    node_t *node = queue->head;
    while (node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("]\n");

    // Dequeue some data
    int dequeued_data;
    for (int i = 0; i < 5; i++) {
        if (queue_dequeue(queue, &dequeued_data) != 0) {
            return -1;
        }

        printf("Dequeued: %d\n", dequeued_data);
    }

    // Peek at the front of the queue
    int front_data;
    if (queue_peek(queue, &front_data) != 0) {
        return -1;
    }

    printf("Front of queue: %d\n", front_data);

    // Check if the queue is empty
    if (queue_is_empty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    // Get the size of the queue
    int size = queue_size(queue);
    printf("Queue size: %d\n", size);

    // Destroy the queue
    queue_destroy(queue);

    return 0;
}