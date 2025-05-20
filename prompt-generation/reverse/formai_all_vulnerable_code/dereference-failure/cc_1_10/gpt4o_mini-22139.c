//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TASKS 100
#define TASK_NAME_LEN 50
#define QUEUE_SIZE 10

typedef struct {
    char name[TASK_NAME_LEN];
    int priority;
    int execution_time; // In seconds
} Task;

typedef struct {
    Task *tasks[MAX_TASKS];
    int count;
} TaskQueue;

TaskQueue *createTaskQueue() {
    TaskQueue *queue = (TaskQueue *)malloc(sizeof(TaskQueue));
    queue->count = 0;
    return queue;
}

void addTask(TaskQueue *queue, const char *name, int priority, int execution_time) {
    if (queue->count >= MAX_TASKS) {
        printf("Task queue is full!\n");
        return;
    }
    Task *newTask = (Task *)malloc(sizeof(Task));
    strncpy(newTask->name, name, TASK_NAME_LEN);
    newTask->priority = priority;
    newTask->execution_time = execution_time;
    queue->tasks[queue->count++] = newTask;
    printf("Added task: %s, Priority: %d, Execution Time: %d seconds\n", name, priority, execution_time);
}

void removeTask(TaskQueue *queue, const char *name) {
    for (int i = 0; i < queue->count; i++) {
        if (strcmp(queue->tasks[i]->name, name) == 0) {
            free(queue->tasks[i]);
            queue->tasks[i] = queue->tasks[--queue->count];
            printf("Removed task: %s\n", name);
            return;
        }
    }
    printf("Task not found: %s\n", name);
}

int compareTasks(const void *a, const void *b) {
    Task *taskA = *(Task **)a;
    Task *taskB = *(Task **)b;
    return taskB->priority - taskA->priority; // Higher priority first
}

void executeTasks(TaskQueue *queue) {
    qsort(queue->tasks, queue->count, sizeof(Task *), compareTasks);
    for (int i = 0; i < queue->count; i++) {
        Task *task = queue->tasks[i];
        printf("Executing task: %s (Priority: %d)\n", task->name, task->priority);
        sleep(task->execution_time);
        printf("Finished task: %s\n", task->name);
    }
}

void freeTaskQueue(TaskQueue *queue) {
    for (int i = 0; i < queue->count; i++) {
        free(queue->tasks[i]);
    }
    free(queue);
}

void displayMenu() {
    printf("\n=== Task Scheduler ===\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. Execute Tasks\n");
    printf("4. Exit\n");
    printf("=======================\n");
}

int main() {
    TaskQueue *taskQueue = createTaskQueue();
    int choice;
    char taskName[TASK_NAME_LEN];
    int priority, executionTime;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", taskName);
                printf("Enter task priority (1-10): ");
                scanf("%d", &priority);
                printf("Enter task execution time (in seconds): ");
                scanf("%d", &executionTime);
                addTask(taskQueue, taskName, priority, executionTime);
                break;
            case 2:
                printf("Enter task name to remove: ");
                scanf("%s", taskName);
                removeTask(taskQueue, taskName);
                break;
            case 3:
                executeTasks(taskQueue);
                break;
            case 4:
                freeTaskQueue(taskQueue);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}