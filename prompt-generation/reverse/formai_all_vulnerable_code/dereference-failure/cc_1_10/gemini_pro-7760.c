//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdlib.h>
#include <stdio.h>

typedef struct queue_node_s {
    int data;
    struct queue_node_s *next;
} queue_node_t;

typedef struct queue_s {
    queue_node_t *head;
    queue_node_t *tail;
    int size;
} queue_t;

queue_t *queue_create(void) {
    queue_t *queue = malloc(sizeof(*queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void queue_destroy(queue_t *queue) {
    queue_node_t *current = queue->head;
    while (current != NULL) {
        queue_node_t *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int queue_is_empty(const queue_t *queue) {
    return queue->size == 0;
}

int queue_size(const queue_t *queue) {
    return queue->size;
}

int queue_front(const queue_t *queue) {
    if (queue_is_empty(queue)) {
        return -1;
    }

    return queue->head->data;
}

int queue_back(const queue_t *queue) {
    if (queue_is_empty(queue)) {
        return -1;
    }

    return queue->tail->data;
}

int queue_enqueue(queue_t *queue, int data) {
    queue_node_t *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue_is_empty(queue)) {
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
    if (queue_is_empty(queue)) {
        return -1;
    }

    queue_node_t *old_head = queue->head;
    int data = old_head->data;

    queue->head = old_head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(old_head);

    queue->size--;

    return data;
}

void queue_print(const queue_t *queue) {
    queue_node_t *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main(void) {
    queue_t *queue = queue_create();

    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, 5);

    queue_print(queue);

    printf("Front: %d\n", queue_front(queue));
    printf("Back: %d\n", queue_back(queue));
    printf("Size: %d\n", queue_size(queue));

    queue_dequeue(queue);
    queue_dequeue(queue);

    queue_print(queue);

    printf("Front: %d\n", queue_front(queue));
    printf("Back: %d\n", queue_back(queue));
    printf("Size: %d\n", queue_size(queue));

    queue_destroy(queue);

    return 0;
}