//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 1024

typedef struct Node {
    void *data;
    size_t size;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    size_t size;
} Queue;

Queue *queue_new() {
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void queue_enqueue(Queue *q, void *data, size_t size) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;

    if (q->rear) {
        q->rear->next = new_node;
    }

    q->rear = new_node;

    if (q->size == MAX_QUEUE_SIZE) {
        size_t new_size = q->size + MAX_QUEUE_SIZE;
        Queue *new_q = realloc(q, sizeof(Queue) + new_size * sizeof(Node));
        Node *old_rear = q->rear;
        memmove(new_q->rear, old_rear, q->size * sizeof(Node));
        free(old_rear);
        q = new_q;
    }

    q->size++;
}

void *queue_dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }

    Node *old_front = q->front;
    void *data = old_front->data;
    q->front = old_front->next;
    free(old_front);
    q->size--;

    return data;
}

size_t queue_size(Queue *q) {
    return q->size;
}

void queue_destroy(Queue *q) {
    Node *current = q->front;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(q);
}

int main() {
    Queue *queue = queue_new();

    queue_enqueue(queue, "Hello", strlen("Hello") + 1);
    queue_enqueue(queue, "World", strlen("World") + 1);

    printf("Queue size: %zu\n", queue_size(queue));

    void *dequeued = queue_dequeue(queue);
    printf("Dequeued: %s\n", (char *)dequeued);

    queue_destroy(queue);

    return 0;
}