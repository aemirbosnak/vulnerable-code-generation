//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    size_t size;
    size_t capacity;
    void** data;
} Queue;

void queue_init(Queue* q, size_t element_size) {
    q->size = 0;
    q->capacity = 8;
    q->data = malloc(q->capacity * element_size);
}

void queue_push(Queue* q, const void* element) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->data = realloc(q->data, q->capacity * sizeof(void*));
    }
    ((char*)q->data)[q->size * sizeof(void*)] = ((char*)element) + (sizeof(element) - 1);
    q->data[q->size++] = (void*)element;
}

void queue_pop(Queue* q) {
    if (q->size == 0) {
        fprintf(stderr, "Queue is empty.\n");
        return;
    }
    void* element = q->data[--q->size];
    size_t element_size = (size_t) ((char*)q->data[q->size] - ((char*)q->data[q->size - 1]));
    memmove(q->data + q->size, q->data + q->size + element_size, (q->size - 1) * sizeof(void*));
    free(q->data + q->size + element_size);
}

void queue_destroy(Queue* q) {
    free(q->data);
}

int main() {
    Queue q;
    queue_init(&q, sizeof(int));

    for (int i = 0; i < 10; i++) {
        queue_push(&q, &i);
    }

    for (int i = 0; i < 5; i++) {
        int popped_element;
        queue_pop(&q);
        popped_element = *(int*)popped_element;
        printf("Popped: %d\n", popped_element);
    }

    queue_push(&q, "Hello World");
    const char* str;
    queue_pop(&q);
    str = (const char*)q.data[0];
    printf("Popped: %s\n", str);

    queue_destroy(&q);

    return 0;
}