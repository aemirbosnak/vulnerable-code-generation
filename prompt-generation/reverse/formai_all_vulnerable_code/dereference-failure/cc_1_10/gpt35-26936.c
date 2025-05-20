//FormAI DATASET v1.0 Category: Queue ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct Queue{
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, int item){
    if(queue->rear == MAX_QUEUE_SIZE-1){
        printf("Oops! The Queue is full.\n");
        return;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
    printf("Item %d has been successfully enqueued in the Queue.\n", item);
}

int dequeue(Queue* queue){
    if(queue->rear == -1){
        printf("Oops! The Queue is empty.\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    printf("Item %d has been successfully dequeued from the Queue.\n", item);
    return item;
}

int main(){
    printf("Welcome to my unique and exciting Queue program!\n");
    printf("Let's start by creating a Queue.\n");
    Queue* myQueue = createQueue();
    printf("\nNow, let's enqueue some items in the Queue.\n");
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    printf("\nLet's dequeue an item from the Queue.\n");
    dequeue(myQueue);
    printf("\nNow, let's enqueue some more items in the Queue.\n");
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60);
    printf("\nGreat! Now, let's dequeue all the items from the Queue.\n");
    while(myQueue->rear != -1){
        dequeue(myQueue);
    }
    printf("\nWow! That was exciting. Thanks for using my program. Bye bye!\n");
    return 0;
}