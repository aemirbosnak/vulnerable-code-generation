//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* front;
    struct Node* rear;
} Queue;

Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue* queue) {
    if(queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int data = queue->front->data;
    struct Node* temp = queue->front;
    
    queue->front = queue->front->next;
    
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    
    return data;
}

void display(Queue* queue) {
    if(queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node* temp = queue->front;
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main() {
    Queue* queue = initQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    display(queue);
    
    dequeue(queue);
    
    display(queue);
    
    enqueue(queue, 40);
    
    display(queue);
    
    return 0;
}