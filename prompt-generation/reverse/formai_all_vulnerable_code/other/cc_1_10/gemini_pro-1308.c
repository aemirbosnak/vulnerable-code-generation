//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    void *data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    size_t count;
};

struct queue *queue_create() {
    struct queue *queue = malloc(sizeof(struct queue));
    assert(queue != NULL);
    queue->head = NULL;
    queue->tail = NULL;
    queue->count = 0;
    return queue;
}

bool queue_is_empty(struct queue *queue) {
    return queue->count == 0;
}

void queue_enqueue(struct queue *queue, void *data) {
    struct node *new_node = malloc(sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = NULL;
    if (queue->count == 0) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->count++;
}

void *queue_dequeue(struct queue *queue) {
    assert(!queue_is_empty(queue));
    void *data = queue->head->data;
    struct node *old_head = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(old_head);
    queue->count--;
    return data;
}

void queue_destroy(struct queue *queue) {
    while (!queue_is_empty(queue)) {
        free(queue->head);
        queue->head = queue->head->next;
    }
    free(queue);
}

int main() {
    struct queue *queue = queue_create();

    // Enqueue some data
    for (int i = 0; i < 10; i++) {
        queue_enqueue(queue, (void *)i);
    }

    // Dequeue some data
    for (int i = 0; i < 5; i++) {
        int *data = queue_dequeue(queue);
        printf("%d\n", *data);
    }

    // Destroy the queue
    queue_destroy(queue);

    return 0;
}