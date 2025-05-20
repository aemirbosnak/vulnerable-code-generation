//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
	int *arr;
	int head, tail, size;
} Queue;

Queue* createQueue(int size) {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	q->arr = (int*) malloc(sizeof(int) * size);
	q->size = size;
	q->head = q->tail = -1;
	return q;
}

void enqueue(Queue *q, int data) {
	if(q->tail == q->size - 1) {
		printf("Queue is full!\n");
		return;
	}
	else if(q->head == -1) {
		q->head = q->tail = 0;
	}
	else {
		q->tail++;
	}
	q->arr[q->tail] = data;
}

int dequeue(Queue *q) {
	if(q->head == -1) {
		printf("Queue is empty!\n");
		return -1;
	}
	int data = q->arr[q->head];
	if(q->head == q->tail) {
		q->head = q->tail = -1;
	}
	else {
		q->head++;
	}
	return data;
}

void displayQueue(Queue *q) {
	if(q->head == -1) {
		printf("Queue is empty!\n");
	}
	else {
		int i;
		printf("Queue: ");
		for(i = q->head; i <= q->tail; i++) {
			printf("%d ", q->arr[i]);
		}
		printf("\n");
	}
}

int main() {
	Queue *q = createQueue(5);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	displayQueue(q);
	printf("Dequeue: %d\n", dequeue(q));
	printf("Dequeue: %d\n", dequeue(q));
	printf("Dequeue: %d\n", dequeue(q));
	displayQueue(q);
	enqueue(q, 6);
	enqueue(q, 7);
	displayQueue(q);
	return 0;
}