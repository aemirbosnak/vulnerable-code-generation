//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue(int **queue, int *front, int *rear, int data)
{
    if ((*rear - *front + 1) % MAX == 0)
    {
        printf("Queue Overflow\n");
        return;
    }

    (*queue)[*rear] = data;
    *rear = (*rear + 1) % MAX;
}

int dequeue(int **queue, int *front, int *rear, int *data)
{
    if (*front == *rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    *data = (*queue)[*front];
    *front = (*front + 1) % MAX;
    return 0;
}

int main()
{
    int **queue = NULL;
    int front = -1;
    int rear = -1;

    queue = (int **)malloc(MAX * sizeof(int));

    enqueue(queue, &front, &rear, 10);
    enqueue(queue, &front, &rear, 20);
    enqueue(queue, &front, &rear, 30);
    enqueue(queue, &front, &rear, 40);
    enqueue(queue, &front, &rear, 50);

    int data;
    dequeue(queue, &front, &rear, &data);
    printf("Data: %d\n", data);

    dequeue(queue, &front, &rear, &data);
    printf("Data: %d\n", data);

    free(queue);

    return 0;
}