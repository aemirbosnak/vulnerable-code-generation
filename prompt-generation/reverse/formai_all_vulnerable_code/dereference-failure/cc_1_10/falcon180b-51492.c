//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element* elements[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        queue->elements[i] = NULL;
    }
    return queue;
}

void enqueue(Queue* queue, int data, int priority) {
    Element* element = (Element*)malloc(sizeof(Element));
    element->data = data;
    element->priority = priority;
    if (queue->rear == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->elements[queue->rear] = element;
    queue->size++;
}

Element* dequeue(Queue* queue) {
    Element* element = NULL;
    if (queue->front!= -1) {
        element = queue->elements[queue->front];
        queue->front++;
        queue->size--;
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
    }
    return element;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue* queue) {
    return (queue->size == MAX_SIZE);
}

void display(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->elements[i]->data);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10, 1);
    enqueue(queue, 20, 2);
    enqueue(queue, 30, 3);
    enqueue(queue, 40, 4);
    enqueue(queue, 50, 5);
    display(queue);
    Element* element = dequeue(queue);
    printf("Dequeued element: %d\n", element->data);
    display(queue);
    return 0;
}