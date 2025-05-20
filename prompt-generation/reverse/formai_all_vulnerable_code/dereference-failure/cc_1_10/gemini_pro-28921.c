//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct __queue__ {
    size_t capacity;
    size_t size;
    uint8_t *buffer;
    size_t head;
    size_t tail;
} __queue__;

static bool queue_init(__queue__ *queue, size_t capacity)
{
    assert(queue != NULL);

    queue->capacity = capacity;
    queue->buffer = malloc(capacity);
    if (queue->buffer == NULL) {
        return false;
    }
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;

    return true;
}

static void queue_destroy(__queue__ *queue)
{
    assert(queue != NULL);

    if (queue->buffer == NULL) {
        return;
    }
    free(queue->buffer);
    queue->buffer = NULL;
}

static bool queue_push(__queue__ *queue, uint8_t data)
{
    assert(queue != NULL);

    if (queue->size == queue->capacity) {
        return false;
    }
    queue->buffer[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;

    return true;
}

static bool queue_pop(__queue__ *queue, uint8_t *data)
{
    assert(queue != NULL);

    if (queue->size == 0) {
        return false;
    }
    *data = queue->buffer[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;

    return true;
}

static size_t queue_size(__queue__ *queue)
{
    assert(queue != NULL);

    return queue->size;
}

static bool queue_empty(__queue__ *queue)
{
    assert(queue != NULL);

    return queue->size == 0;
}

static bool queue_full(__queue__ *queue)
{
    assert(queue != NULL);

    return queue->size == queue->capacity;
}

int main(int argc, char *argv[])
{
    __queue__ queue;

    assert(queue_init(&queue, 10) == true);

    for (size_t i = 0; i < queue.capacity; i++) {
        assert(queue_push(&queue, (uint8_t)i) == true);
    }

    assert(queue_full(&queue) == true);

    for (size_t i = 0; i < queue.capacity; i++) {
        uint8_t data;
        assert(queue_pop(&queue, &data) == true);
        assert(data == (uint8_t)i);
    }

    assert(queue_empty(&queue) == true);

    queue_destroy(&queue);

    return EXIT_SUCCESS;
}