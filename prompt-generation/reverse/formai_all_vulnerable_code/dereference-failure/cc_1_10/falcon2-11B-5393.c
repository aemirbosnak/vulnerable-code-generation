//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* back;
};

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->front == NULL) {
        q->front = newNode;
        q->back = newNode;
    } else {
        q->back->next = newNode;
        q->back = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return 0;
    }
    
    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->back = NULL;
    }
    
    free(temp);
    
    return data;
}

int front(struct Queue* q) {
    if (q->front == NULL) {
        return 0;
    }
    
    return q->front->data;
}

int back(struct Queue* q) {
    if (q->back == NULL) {
        return 0;
    }
    
    return q->back->data;
}

int main() {
    struct Queue q;
    q.front = NULL;
    q.back = NULL;
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    
    printf("Front: %d\n", front(&q));
    printf("Back: %d\n", back(&q));
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Front: %d\n", front(&q));
    printf("Back: %d\n", back(&q));
    
    return 0;
}