//FormAI DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define task struct */
typedef struct Task {
    int ID;
    int priority;
    int jobTime;
    int remainingTime;
} Task;

/* Define queue struct for holding tasks */
typedef struct Queue {
    Task *tasks;
    int front;
    int rear;
} Queue;

/* Initialize the queue */
Queue* initQueue(int size)
{
    Queue* queue = (Queue *) malloc(sizeof(Queue));
    queue -> tasks = (Task *) malloc(sizeof(Task) * size);
    queue -> front = -1;
    queue -> rear = -1;
    return queue;
}

/* Check if queue is empty */
int isEmpty(Queue *queue)
{
    return queue->front == -1 || queue->front > queue->rear;
}

/* Check if queue is full */
int isFull(Queue *queue, int size)
{
    return queue->rear == size - 1;
}

/* Add a task to the queue */
void enqueue(Queue *queue, Task task)
{
    if (isEmpty(queue)) {
        queue -> front = 0;
        queue -> rear = 0;
    } 
    else if (!isFull(queue, 10)) {
        queue -> rear++;
    } 
    else {
        printf("ERROR: Queue is full!\n");
        return;
    }
    queue -> tasks[queue -> rear] = task;
}

/* Remove a task from the queue */
Task dequeue(Queue *queue)
{
    Task task;
    if (isEmpty(queue)) {
        printf("ERROR: Queue is empty!\n");
    } 
    else {
        task = queue -> tasks[queue -> front];
        queue -> front++;
    }
    return task;
}

/* Get the task at the front of the queue without removing it */
Task peek(Queue *queue)
{
    Task task;
    if (isEmpty(queue)) {
        printf("ERROR: Queue is empty!\n");
    } 
    else {
        task = queue -> tasks[queue -> front];
    }
    return task;
}

/* Algorithm to schedule the tasks */
void taskScheduler(Queue *queue)
{
    int currentTime = 0;
    while (!isEmpty(queue)) {
        Task currentTask = dequeue(queue);
        printf("Running task with ID %d and priority %d\n", currentTask.ID, currentTask.priority);
        while (currentTask.remainingTime > 0) {
            currentTask.remainingTime--;
            currentTime++;
        }
        printf("Task with ID %d and priority %d completed at time %d\n", currentTask.ID, currentTask.priority, currentTime);
    }
}

/* Define main function */
int main()
{
    srand(time(0));

    /* Define tasks */
    Task task1 = {1, 2, (rand() % 10) + 1, 0};
    Task task2 = {2, 3, (rand() % 10) + 1, 0};
    Task task3 = {3, 1, (rand() % 10) + 1, 0};
    Task task4 = {4, 2, (rand() % 10) + 1, 0};
    Task task5 = {5, 3, (rand() % 10) + 1, 0};

    /* Initialize the queue */
    Queue *queue = initQueue(10);

    /* Add tasks to the queue */
    enqueue(queue, task1);
    enqueue(queue, task2);
    enqueue(queue, task3);
    enqueue(queue, task4);
    enqueue(queue, task5);

    /* Schedule the tasks */
    taskScheduler(queue);

    return 0;
}