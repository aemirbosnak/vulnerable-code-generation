//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _queue {
	void *data;
	size_t size;
	size_t capacity;
} queue;

queue *queue_create(size_t capacity)
{
	queue *q = malloc(sizeof(queue));
	q->data = malloc(capacity * sizeof(void *));
	q->size = 0;
	q->capacity = capacity;
	return q;
}

void queue_destroy(queue *q)
{
	free(q->data);
	free(q);
}

bool queue_is_empty(queue *q)
{
	return q->size == 0;
}

bool queue_is_full(queue *q)
{
	return q->size == q->capacity;
}

void queue_push(queue *q, void *data, size_t size)
{
	assert(!queue_is_full(q));

	if (q->size + size > q->capacity) {
		q->data = realloc(q->data, q->capacity * 2 * sizeof(void *));
		q->capacity *= 2;
	}

	memcpy(q->data + q->size, data, size);
	q->size += size;
}

void *queue_pop(queue *q, size_t size)
{
	assert(!queue_is_empty(q));

	void *data = malloc(size);
	memcpy(data, q->data, size);
	memmove(q->data, q->data + size, q->size - size);
	q->size -= size;
	return data;
}

void queue_print(queue *q)
{
	printf("[");
	for (size_t i = 0; i < q->size; i++) {
		printf(" %p", q->data + i);
	}
	printf(" ]\n");
}

int main()
{
	queue *q = queue_create(10);
	queue_push(q, "Hello", strlen("Hello") + 1);
	queue_push(q, "World", strlen("World") + 1);
	queue_print(q);
	char *s = queue_pop(q, strlen("Hello") + 1);
	printf("%s\n", s);
	queue_print(q);
	queue_destroy(q);
	return 0;
}