//FormAI DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Structure for queue node
struct QueueNode{
    int data;
    struct QueueNode *next;
};

// Structure for queue
struct Queue
{
    struct QueueNode *front, *rear;
};

// Function to create a new node
struct QueueNode* newQueueNode(int data)
{
    struct QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
struct Queue* createQueue()
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue
void enqueue(struct Queue *queue, int data)
{
    struct QueueNode *temp = newQueueNode(data);

    if (queue->rear == NULL){
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to dequeue
int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
        return -1;

    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    int data = temp->data;
    free(temp);
    return data;
}

void laugh(){
    printf("HAHAHAHA! I am a queue implementation program, and you thought code isn't funny?\n");
}

void thank(){
    printf("Thanks for using my queue implementation program. Have a great day! :)\n");
}

int main()
{
    struct Queue *queue = createQueue();

    printf("Welcome to my unique C Queue Implementation Program!\n");
    printf("I will make sure you get the hang of it while having fun.\n");
    printf("Alright, let's get started with enqueuing some numbers! Here we go...\n");

    laugh();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Successfully enqueued numbers: 1, 2, 3, 4, 5\n");

    laugh();

    printf("Now let's dequeue some items from the queue, shall we?\n");

    int dequeuedItem = dequeue(queue);
    printf("Dequeued item is %d\n", dequeuedItem);

    dequeuedItem = dequeue(queue);
    printf("Dequeued item is %d\n", dequeuedItem);

    laugh();

    printf("Now the queue is left with these items: ");

    struct QueueNode *current = queue->front;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    laugh();

    thank();

    return 0;
}