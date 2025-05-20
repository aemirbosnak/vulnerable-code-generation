//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#define MAX_BAGGAGE 100

struct baggage {
    int flight_num;
    int weight;
};

struct node {
    struct baggage *data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

struct queue *createQueue() 
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct queue *q, struct baggage *b) 
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = b;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct queue *q) 
{
    if (q->front == NULL)
        return;
    struct node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL)
        q->rear = NULL;
}

int main() 
{
    struct queue *q = createQueue();

    struct baggage *b1 = (struct baggage*) malloc(sizeof(struct baggage));
    b1->flight_num = 123;
    b1->weight = 50;

    struct baggage *b2 = (struct baggage*) malloc(sizeof(struct baggage));
    b2->flight_num = 567;
    b2->weight = 75;

    struct baggage *b3 = (struct baggage*) malloc(sizeof(struct baggage));
    b3->flight_num = 890;
    b3->weight = 100;

    enQueue(q, b1);
    enQueue(q, b2);
    enQueue(q, b3);

    printf("Baggage queue:\n");
    while (q->front != NULL) {
        struct baggage *b = q->front->data;
        printf("Flight number: %d, weight: %d\n", b->flight_num, b->weight);
        deQueue(q);
    }

    return 0;
}