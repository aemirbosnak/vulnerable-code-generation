//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int *data;
    int front;
    int rear;
    int size;
};

void create_queue(struct queue *q, int size) {
    q->size = size;
    q->data = (int *) malloc(q->size * sizeof(int));
    q->front = 0;
    q->rear = -1;
}

void insert_element(struct queue *q, int element) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = element;
}

int delete_element(struct queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = q->data[q->front];
    q->front++;
    return element;
}

void display_queue(struct queue *q) {
    int i;
    printf("Front: %d, Rear: %d\n", q->front, q->rear);
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    create_queue(&q, 5);
    insert_element(&q, 10);
    insert_element(&q, 20);
    insert_element(&q, 30);
    insert_element(&q, 40);
    display_queue(&q);
    printf("Deleted element: %d\n", delete_element(&q));
    display_queue(&q);
    return 0;
}