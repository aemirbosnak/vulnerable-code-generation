//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Knight {
    int data;
    struct Knight* next;
} Knight;

Knight* rear = NULL;
Knight* front = NULL;

void enqueue(int data) {
    Knight* newNode = (Knight*)malloc(sizeof(Knight));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        return -1;
    }

    int data = front->data;
    front = front->next;

    return data;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    int data = dequeue();
    printf("Dequeued data: %d\n", data);

    data = dequeue();
    printf("Dequeued data: %d\n", data);

    data = dequeue();
    printf("Dequeued data: %d\n", data);

    return 0;
}