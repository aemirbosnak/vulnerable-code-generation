//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue queue;

void initializeQueue() {
    queue.front = NULL;
    queue.rear = NULL;
}

int isFull() {
    return (queue.rear == (Node*) (malloc(sizeof(Node)) - 1));
}

int isEmpty() {
    return (queue.front == NULL && queue.rear == NULL);
}

void enqueue(char data) {
    if (isFull()) {
        printf("Queue is full. Data not enqueued.\n");
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

char dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. No data dequeued.\n");
        return '\0';
    }

    char data = queue.front->data;
    Node* temp = queue.front;

    if (queue.front == queue.rear) {
        queue.front = NULL;
        queue.rear = NULL;
    } else {
        queue.front = queue.front->next;
    }

    free(temp);

    return data;
}

void printQueue() {
    Node* current = queue.front;

    printf("Queue contents: ");

    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    initializeQueue();

    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('D');

    printQueue();

    char data = dequeue();
    printf("Dequeued data: %c\n", data);

    printQueue();

    return 0;
}