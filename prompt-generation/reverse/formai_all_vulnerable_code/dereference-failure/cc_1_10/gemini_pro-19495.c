//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>

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
    queue_t *queue = malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void queue_destroy(queue_t *queue) {
    node_t *current = queue->head;

    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int queue_enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;

    return 0;
}

int queue_dequeue(queue_t *queue, int *data) {
    if (queue->head == NULL) {
        return -1;
    }

    node_t *current = queue->head;
    *data = current->data;

    queue->head = current->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(current);

    queue->size--;

    return 0;
}

int queue_peek(queue_t *queue, int *data) {
    if (queue->head == NULL) {
        return -1;
    }

    *data = queue->head->data;

    return 0;
}

int queue_size(queue_t *queue) {
    return queue->size;
}

int main() {
    queue_t *queue = queue_create();

    int data;

    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);

    queue_peek(queue, &data);
    printf("Peek: %d\n", data);

    queue_dequeue(queue, &data);
    printf("Dequeue: %d\n", data);

    queue_dequeue(queue, &data);
    printf("Dequeue: %d\n", data);

    queue_dequeue(queue, &data);
    printf("Dequeue: %d\n", data);

    queue_destroy(queue);

    return 0;
}