//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* data;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} queue;

void queue_init(queue* q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

bool queue_is_empty(queue* q) {
    return q->size == 0;
}

bool queue_is_full(queue* q) {
    return q->size == 100; // Assuming a maximum size of 100
}

void queue_enqueue(queue* q, void* data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue_is_empty(q)) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->size++;
}

void* queue_dequeue(queue* q) {
    if (queue_is_empty(q)) {
        return NULL;
    }

    node* temp_node = q->head;
    void* data = temp_node->data;
    q->head = temp_node->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp_node);
    q->size--;

    return data;
}

void* queue_peek(queue* q) {
    if (queue_is_empty(q)) {
        return NULL;
    }

    return q->head->data;
}

int main() {
    queue q;
    queue_init(&q);

    queue_enqueue(&q, "hello");
    queue_enqueue(&q, "world");

    printf("Peek: %s\n", (char*)queue_peek(&q));

    void* data1 = queue_dequeue(&q);
    void* data2 = queue_dequeue(&q);

    printf("Dequeued data 1: %s\n", (char*)data1);
    printf("Dequeued data 2: %s\n", (char*)data2);

    return 0;
}