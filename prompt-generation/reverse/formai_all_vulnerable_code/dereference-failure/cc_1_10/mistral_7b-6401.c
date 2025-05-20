//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int size;
    int head;
    int tail;
    int* data;
} Queue_Of_Scribbles;

void create_queue(Queue_Of_Scribbles* q, int size) {
    *q = (Queue_Of_Scribbles) {
        .size = size,
        .head = -1,
        .tail = -1,
        .data = calloc(size, sizeof(int))
    };
    strcpy(q->name, "Queue_Of_Scribbles");
}

void enqueue(Queue_Of_Scribbles* q, int value) {
    if (is_full(*q)) {
        printf("%s: Queue is full, cannot enqueue %d\n", q->name, value);
        return;
    }
    q->data[++(q->tail)] = value;
}

int dequeue(Queue_Of_Scribbles* q) {
    if (is_empty(*q)) {
        printf("%s: Queue is empty, cannot dequeue\n", q->name);
        return -1;
    }
    int value = q->data[q->head++];
    if (q->head > q->tail) q->head = q->tail;
    return value;
}

int is_empty(Queue_Of_Scribbles q) {
    return q.head == q.tail;
}

int is_full(Queue_Of_Scribbles q) {
    return (q.tail + 1) % q.size == q.head;
}

int main() {
    Queue_Of_Scribbles my_queue;
    create_queue(&my_queue, 10);

    enqueue(&my_queue, 5);
    enqueue(&my_queue, 10);
    enqueue(&my_queue, 15);
    enqueue(&my_queue, 20);

    printf("%s: Size = %d, Head = %d, Tail = %d, Data = [%d, %d, %d, %d]\n",
        my_queue.name, my_queue.size, my_queue.head, my_queue.tail,
        my_queue.data[0], my_queue.data[1], my_queue.data[2], my_queue.data[3]);

    int dequeued = dequeue(&my_queue);
    printf("%s: Dequeued %d\n", my_queue.name, dequeued);

    int dequeued2 = dequeue(&my_queue);
    printf("%s: Dequeued %d\n", my_queue.name, dequeued2);

    return 0;
}