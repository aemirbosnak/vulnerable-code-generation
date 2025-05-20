//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void queue_destroy(queue_t *queue) {
    while (queue->head != NULL) {
        node_t *next = queue->head->next;
        free(queue->head);
        queue->head = next;
    }
    free(queue);
}

int queue_is_empty(queue_t *queue) {
    return queue->size == 0;
}

int queue_size(queue_t *queue) {
    return queue->size;
}

void queue_enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
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
}

int queue_dequeue(queue_t *queue) {
    assert(!queue_is_empty(queue));
    node_t *old_head = queue->head;
    int data = old_head->data;
    queue->head = old_head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(old_head);
    queue->size--;
    return data;
}

void queue_print(queue_t *queue) {
    printf("Queue: ");
    for (node_t *node = queue->head; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
    printf("\n");
}

int main() {
    queue_t *queue = queue_create();
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_print(queue);
    printf("Size: %d\n", queue_size(queue));
    int data = queue_dequeue(queue);
    printf("Dequeued: %d\n", data);
    queue_print(queue);
    queue_destroy(queue);
    return 0;
}