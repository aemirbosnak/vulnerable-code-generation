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

queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
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
}

int dequeue(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    int data = queue->head->data;
    node_t *new_head = queue->head->next;
    free(queue->head);
    queue->head = new_head;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    queue->size--;
    return data;
}

int peek(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    return queue->head->data;
}

int is_empty(queue_t *queue) {
    return queue->size == 0;
}

int main() {
    queue_t *queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    while (!is_empty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");
    return 0;
}