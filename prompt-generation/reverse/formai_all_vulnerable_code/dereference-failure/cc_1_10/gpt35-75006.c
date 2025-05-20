//FormAI DATASET v1.0 Category: Queue ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* queue structure definition */
struct queue {
    int *items;
    int front, rear;
    int capacity;
};

/* function prototypes */
struct queue *createQueue(int);
void enqueue(struct queue *, int);
int dequeue(struct queue *);
void display(struct queue *);

int main() {
    struct queue *Q = createQueue(5);

    /* enqueue elements */
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);

    /* dequeue and display elements */
    printf("Dequeuing elements: ");
    printf("%d ", dequeue(Q));
    printf("%d ", dequeue(Q));
    printf("%d ", dequeue(Q));
    printf("%d ", dequeue(Q));
    printf("%d ", dequeue(Q));

    /* enqueue again */
    enqueue(Q, 6);

    /* display elements */
    printf("\nElements in queue after enqueueing again: ");
    display(Q);

    return 0;
}

/* function to create a queue of given capacity */
struct queue *createQueue(int capacity) {
    struct queue *Q = malloc(sizeof(struct queue));
    Q->items = malloc(sizeof(int) * capacity);
    Q->capacity = capacity;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

/* function to add an element to the queue */
void enqueue(struct queue *Q, int element) {
    if (Q->rear == Q->capacity - 1) {
        printf("Queue is full!\n");
    } else {
        if (Q->front == -1) {
            Q->front = 0;
        }
        Q->rear++;
        Q->items[Q->rear] = element;
        printf("Enqueued %d\n", element);
    }
}

/* function to remove an element from the queue */
int dequeue(struct queue *Q) {
    int element;

    if (Q->front == -1 || Q->front > Q->rear) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        element = Q->items[Q->front];
        Q->front++;

        printf("Dequeued %d\n", element);
        return element;
    }
}

/* function to display the elements of queue */
void display(struct queue *Q) {
    int i;
    if (Q->rear == -1) {
        printf("Queue is empty!\n");
    } else {

        for (i = Q->front; i <= Q->rear; i++) {
            printf("%d ", Q->items[i]);
        }
        printf("\n");
    }
}