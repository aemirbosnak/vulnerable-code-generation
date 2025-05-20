//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Queue {
    Node* head;
    Node* tail;
    int size;
    int maxSize;
};

void enqueue(struct Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
    if (queue->size >= queue->maxSize) {
        printf("Queue Overflow!\n");
    }
}

void dequeue(struct Queue* queue)
{
    if (queue->head == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    Node* tempNode = queue->head;
    queue->head = queue->head->next;
    free(tempNode);

    queue->size--;
}

int main()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->maxSize = MAX_SIZE;
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    dequeue(queue);
    dequeue(queue);

    printf("Elements in the queue: ");
    for (Node* node = queue->head; node; node = node->next) {
        printf("%d ", node->data);
    }

    printf("\n");

    return 0;
}