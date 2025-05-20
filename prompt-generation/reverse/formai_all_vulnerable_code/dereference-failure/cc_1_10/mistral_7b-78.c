//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    char items[MAX_QUEUE_SIZE][20];
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)calloc(1, sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, const char *str) {
    if (isFull(q)) {
        printf("Error: Queue is full.\n");
        return;
    }

    strcpy(q->items[++q->rear], str);
}

char *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    char *str = q->items[q->front++];

    if (q->front > q->rear) {
        q->front = q->rear;
    }

    return str;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    // Romeo
    enqueue(queue, "Romeo: O soft tear, my fair Ophelia.");
    enqueue(queue, "Romeo: O brave new world, If I could be where thou art.");

    // Friar Laurence
    printf("Friar Laurence: The lovers are in the church, I must interfere.\n");
    printQueue(queue);

    // Juliet
    enqueue(queue, "Juliet: O Romeo, Romeo, wherefore art thou Romeo?");
    enqueue(queue, "Juliet: O sweet Romeo, make gentle the time, Make bright those golden hours.");

    // Friar Laurence
    printQueue(queue);
    char *str = dequeue(queue);
    printf("Friar Laurence: %s\n", str);

    free(queue);

    return 0;
}