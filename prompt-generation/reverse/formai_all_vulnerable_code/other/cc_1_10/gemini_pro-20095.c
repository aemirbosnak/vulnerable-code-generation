//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *head;
    node_t *tail;
    size_t size;
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
    if (queue == NULL) {
        return;
    }
    node_t *current = queue->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

int queue_enqueue(queue_t *queue, int data) {
    if (queue == NULL) {
        return -1;
    }
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

int queue_dequeue(queue_t *queue) {
    if (queue == NULL) {
        return -1;
    }
    if (queue->head == NULL) {
        return -1;
    }
    int data = queue->head->data;
    node_t *next = queue->head->next;
    free(queue->head);
    queue->head = next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    queue->size--;
    return data;
}

int queue_front(queue_t *queue) {
    if (queue == NULL) {
        return -1;
    }
    if (queue->head == NULL) {
        return -1;
    }
    return queue->head->data;
}

size_t queue_size(queue_t *queue) {
    if (queue == NULL) {
        return 0;
    }
    return queue->size;
}

int main() {
    queue_t *queue = queue_create();
    assert(queue != NULL);
    assert(queue_size(queue) == 0);

    int data = 1;
    assert(queue_enqueue(queue, data) == 0);
    assert(queue_size(queue) == 1);
    assert(queue_front(queue) == data);

    data = 2;
    assert(queue_enqueue(queue, data) == 0);
    assert(queue_size(queue) == 2);
    assert(queue_front(queue) == data);

    data = 3;
    assert(queue_enqueue(queue, data) == 0);
    assert(queue_size(queue) == 3);
    assert(queue_front(queue) == data);

    data = queue_dequeue(queue);
    assert(data == 1);
    assert(queue_size(queue) == 2);
    assert(queue_front(queue) == 2);

    data = queue_dequeue(queue);
    assert(data == 2);
    assert(queue_size(queue) == 1);
    assert(queue_front(queue) == 3);

    data = queue_dequeue(queue);
    assert(data == 3);
    assert(queue_size(queue) == 0);
    assert(queue_front(queue) == -1);

    queue_destroy(queue);

    return 0;
}