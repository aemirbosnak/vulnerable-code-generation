//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

//Queue Structure
struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
};

//Create Queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(sizeof(int)*capacity);
    return queue;
};

//Queue is Full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity-1 && queue->front == 0) || (queue->rear+1 == queue->front);
}

//Queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

//Add an element to Queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("\nQueue Overflow\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = item;
    printf("\nElement %d added to Queue\n", item);
}

//Remove an element from Queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue Underflow\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        queue->front = (queue->front+1) % queue->capacity;

    return item;
}

//Driver Code
int main() {

    struct Queue* queue = createQueue(10);

    //Adding elements to Queue
    enqueue(queue, 11);
    enqueue(queue, 22);
    enqueue(queue, 33);
    enqueue(queue, 44);
    enqueue(queue, 55);

    //Removing elements from Queue
    printf("\nQueue Element: %d\n", dequeue(queue));
    printf("\nQueue Element: %d\n", dequeue(queue));
    printf("\nQueue Element: %d\n", dequeue(queue));
    printf("\nQueue Element: %d\n", dequeue(queue));
    printf("\nQueue Element: %d\n", dequeue(queue));
    printf("\nQueue Element: %d\n", dequeue(queue));  //Empty Queue
    return 0;
}