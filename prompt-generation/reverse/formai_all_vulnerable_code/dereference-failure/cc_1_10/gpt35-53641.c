//FormAI DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, capacity;
    int *arr;
};

struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue){
    return queue->rear == queue->capacity-1;
}

int isEmpty(struct Queue* queue){
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int data){
    if(isFull(queue)){
        printf("Queue is full\n");
        return;
    }
    if(queue->front == -1){
        queue->front = 0;
    }
    queue->arr[++queue->rear] = data;
}

int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }
    else {
        queue->front++;
    }
    return item;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6); // Queue is full
    display(queue); // 1 2 3 4 5

    dequeue(queue);
    dequeue(queue);
    display(queue); // 3 4 5

    enqueue(queue, 6);
    display(queue); // 3 4 5 6

    return 0;
}