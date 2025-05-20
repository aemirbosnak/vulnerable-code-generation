//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
} Queue;

void initializeQueue(Queue* queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void enqueue(Queue* queue, int data)
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
}

int dequeue(Queue* queue)
{
    if (queue->head == NULL)
    {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

void displayQueue(Queue* queue)
{
    struct Node* current = queue->head;

    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initializeQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    displayQueue(queue);

    int data = dequeue(queue);
    printf("Data: %d\n", data);

    displayQueue(queue);

    return 0;
}