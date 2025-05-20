//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // maximum size of queue

struct Queue {
    int front, rear;
    int items[MAX_SIZE];
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue *q) {
    if(q->rear == -1) return 1;
    else return 0;
}

int isFull(struct Queue *q) {
    if(q->rear == MAX_SIZE-1) return 1;
    else return 0;
}

void enqueue(struct Queue *q, int value) {
    if(isFull(q)) printf("[!] The Queue is full.\n");
    else {
        if(q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("[%d] enqueued to the Queue.\n", value);
    }
}

int dequeue(struct Queue *q) {
    int item;
    if(isEmpty(q)) {
        printf("[!] The Queue is empty.\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear) {
            printf("[!] Queue is empty.\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void display(struct Queue *q) {
    int i;
    if(isEmpty(q)) printf("[!] The Queue is empty.\n");
    else {
        printf("[+] The Queue is as follows:\n");
        for(i=q->front; i<=q->rear; i++) printf("%d\n", q->items[i]);
    }
}

int main() {
    struct Queue *q = createQueue();
    
    // enqueue 5 numbers
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // display queue
    display(q);

    // dequeue 2 elements
    dequeue(q);
    dequeue(q);

    // display queue
    display(q);

    return 0;
}