//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the Task struct to hold task information
typedef struct Task {
    int priority;
    int executionTime;
    char* description;
} Task;

// Define the TaskQueue struct to hold the tasks
typedef struct TaskQueue {
    int size;
    int count;
    Task* tasks;
} TaskQueue;

// Initialize the task queue with a given size
TaskQueue* initQueue(int size) {
    TaskQueue* queue = (TaskQueue*)malloc(sizeof(TaskQueue));
    queue->size = size;
    queue->count = 0;
    queue->tasks = (Task*)malloc(sizeof(Task) * size);
    return queue;
}

// Add a task to the task queue with a given priority and execution time
void addTask(TaskQueue* queue, int priority, int executionTime, char* description) {
    queue->tasks[queue->count].priority = priority;
    queue->tasks[queue->count].executionTime = executionTime;
    queue->tasks[queue->count].description = (char*)malloc(strlen(description) + 1);
    strcpy(queue->tasks[queue->count].description, description);
    queue->count++;
}

// Remove the task with the highest priority from the task queue
void removeTask(TaskQueue* queue) {
    if (queue->count == 0) {
        printf("Queue is empty\n");
        return;
    }

    int highestPriority = queue->tasks[0].priority;
    for (int i = 0; i < queue->count - 1; i++) {
        if (queue->tasks[i + 1].priority > highestPriority) {
            highestPriority = queue->tasks[i + 1].priority;
        }
    }

    free(queue->tasks[0].description);
    queue->tasks[0].priority = 0;
    queue->tasks[0].executionTime = 0;
    queue->tasks[0].description = NULL;

    for (int i = 0; i < queue->count - 1; i++) {
        queue->tasks[i] = queue->tasks[i + 1];
    }

    queue->count--;
}

// Print the tasks in the task queue
void printQueue(TaskQueue* queue) {
    if (queue->count == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority\tExecution Time\tDescription\n");
    for (int i = 0; i < queue->count; i++) {
        printf("%d\t%d\t%s\n", queue->tasks[i].priority, queue->tasks[i].executionTime, queue->tasks[i].description);
    }
}

// Example usage
int main() {
    int size = 5;
    TaskQueue* queue = initQueue(size);

    addTask(queue, 1, 5, "Task 1");
    addTask(queue, 2, 3, "Task 2");
    addTask(queue, 3, 4, "Task 3");
    addTask(queue, 4, 2, "Task 4");
    addTask(queue, 5, 1, "Task 5");

    printQueue(queue);

    removeTask(queue);

    printQueue(queue);

    return 0;
}