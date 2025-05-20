//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
    int data[MAX_QUEUE_SIZE];
    int head;  // Index of the first element
    int tail;  // Index of the next empty slot
} Queue;

Queue* create_queue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    return q;
}

// Queue is full if (tail+1) % MAX_QUEUE_SIZE == head
int is_full(Queue* q)
{
    return (q->tail + 1) % MAX_QUEUE_SIZE == q->head;
}

int is_empty(Queue* q)
{
    return q->head == q->tail;
}

void enqueue(Queue* q, int item)
{
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue* q)
{
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->data[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_SIZE;
    return item;
}

void print_queue(Queue* q)
{
    printf("Head = %d, Tail = %d\n", q->head, q->tail);
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->head;
    while (i != q->tail) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main()
{
    Queue* q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    print_queue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 6);
    enqueue(q, 7);
    print_queue(q);
    return 0;
}