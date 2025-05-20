//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

void init(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(struct queue *q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct queue *q, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue *q) {
    int data;
    struct node *temp = q->front;

    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
        return data;
    }
}

void display(struct queue *q) {
    struct node *temp = q->front;

    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue elements are: ");
    display(&q);

    int data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);

    printf("Queue elements are: ");
    display(&q);

    data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);

    printf("Queue elements are: ");
    display(&q);

    data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);

    printf("Queue elements are: ");
    display(&q);

    data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);

    printf("Queue elements are: ");
    display(&q);

    return 0;
}