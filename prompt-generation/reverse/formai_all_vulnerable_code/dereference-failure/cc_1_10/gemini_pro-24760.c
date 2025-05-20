//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct queue
{
    size_t capacity;
    size_t front;
    size_t rear;
    size_t size;
    void **items;
} queue_t;

queue_t *queue_new(size_t capacity)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return NULL;

    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->items = malloc(sizeof(void *) * capacity);
    if (!queue->items)
    {
        free(queue);
        return NULL;
    }

    return queue;
}

void queue_delete(queue_t *queue)
{
    free(queue->items);
    free(queue);
}

bool queue_is_empty(queue_t *queue)
{
    return queue->size == 0;
}

bool queue_is_full(queue_t *queue)
{
    return queue->size == queue->capacity;
}

size_t queue_size(queue_t *queue)
{
    return queue->size;
}

void queue_enqueue(queue_t *queue, void *item)
{
    if (queue_is_full(queue))
        return;

    queue->items[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

void *queue_dequeue(queue_t *queue)
{
    if (queue_is_empty(queue))
        return NULL;

    void *item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return item;
}

void *queue_peek(queue_t *queue)
{
    if (queue_is_empty(queue))
        return NULL;

    return queue->items[queue->front];
}

int main(void)
{
    queue_t *queue = queue_new(10);

    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);

    queue_enqueue(queue, (void *)1);
    queue_enqueue(queue, (void *)2);
    queue_enqueue(queue, (void *)3);

    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 3);

    assert(queue_dequeue(queue) == (void *)1);
    assert(queue_dequeue(queue) == (void *)2);

    queue_enqueue(queue, (void *)4);

    assert(queue_peek(queue) == (void *)3);

    queue_dequeue(queue);
    queue_dequeue(queue);

    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);

    queue_delete(queue);

    return 0;
}