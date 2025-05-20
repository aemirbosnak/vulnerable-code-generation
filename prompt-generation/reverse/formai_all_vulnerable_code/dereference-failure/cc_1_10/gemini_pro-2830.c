//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int *data;
	int head;
	int tail;
	int size;
} queue_t;

queue_t *queue_create(int size) {
	queue_t *queue = malloc(sizeof(queue_t));
	if (!queue) {
		return NULL;
	}

	queue->data = malloc(sizeof(int) * size);
	if (!queue->data) {
		free(queue);
		return NULL;
	}

	queue->head = 0;
	queue->tail = 0;
	queue->size = size;

	return queue;
}

void queue_destroy(queue_t *queue) {
	free(queue->data);
	free(queue);
}

int queue_enqueue(queue_t *queue, int data) {
	if ((queue->tail + 1) % queue->size == queue->head) {
		return -1;
	}

	queue->data[queue->tail] = data;
	queue->tail = (queue->tail + 1) % queue->size;

	return 0;
}

int queue_dequeue(queue_t *queue, int *data) {
	if (queue->head == queue->tail) {
		return -1;
	}

	*data = queue->data[queue->head];
	queue->head = (queue->head + 1) % queue->size;

	return 0;
}

int main() {
	queue_t *queue = queue_create(10);
	if (!queue) {
		return EXIT_FAILURE;
	}

	for (int i = 0; i < 10; i++) {
		if (queue_enqueue(queue, i) == -1) {
			printf("Error: queue is full\n");
			return EXIT_FAILURE;
		}
	}

	int data;
	for (int i = 0; i < 10; i++) {
		if (queue_dequeue(queue, &data) == -1) {
			printf("Error: queue is empty\n");
			return EXIT_FAILURE;
		}

		printf("%d ", data);
	}

	printf("\n");

	queue_destroy(queue);

	return EXIT_SUCCESS;
}