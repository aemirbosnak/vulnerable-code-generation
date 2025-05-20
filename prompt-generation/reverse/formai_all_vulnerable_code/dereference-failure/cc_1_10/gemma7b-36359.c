//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

struct Queue
{
    struct Node* head;
    struct Node* tail;
    int size;
    int maxSize;
};

void enqueue(struct Queue* queue, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
    if (queue->size == queue->maxSize)
    {
        printf("Queue Overflow\n");
    }
}

int dequeue(struct Queue* queue)
{
    if (queue->head == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;

    return data;
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

    printf("Dequed data: %d\n", dequeue(queue));
    printf("Dequed data: %d\n", dequeue(queue));
    printf("Dequed data: %d\n", dequeue(queue));
    printf("Dequed data: %d\n", dequeue(queue));

    free(queue);

    return 0;
}