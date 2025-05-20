//FormAI DATASET v1.0 Category: Queue ; Style: bold
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue{
    int data[MAX_SIZE];
    int head;
    int tail;
};

typedef struct Queue Queue;

Queue* createQueue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = q->tail = -1;
    return q;
}

void enqueue(Queue* q, int value){
    if(q->tail == MAX_SIZE-1){
        printf("Queue is full\n");
        return;
    }
    else{
        q->tail++;
        q->data[q->tail] = value;
        if(q->head == -1){
            q->head = 0;
        }
    }
}

int dequeue(Queue* q){
    if(q->head == -1){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int data = q->data[q->head];
        if(q->head == q->tail){
            q->head = q->tail = -1;
        }
        else{
            q->head++;
        }
        return data;
    }
}

int main(){

    Queue* q = createQueue();

    // Enqueue some values
    enqueue(q, 12);
    enqueue(q, 43);
    enqueue(q, 7);
    enqueue(q, 9);

    // Dequeue some values and print them
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    // Enqueue some more values
    enqueue(q, 5);
    enqueue(q, 51);
    enqueue(q, 27);

    // Dequeue the rest of the values and print them
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    // Try to dequeue again to see if queue is empty
    printf("Dequeued: %d\n", dequeue(q));
    
    free(q);

    return 0;
}