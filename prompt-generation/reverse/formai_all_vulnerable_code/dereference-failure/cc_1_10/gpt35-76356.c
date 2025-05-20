//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_TIME 10

typedef struct Task {
    int id;
    int priority;
    int time;
    bool completed;
} Task;

typedef struct TaskScheduler {
    int numTasks;
    Task* tasks[MAX_TASKS];
} TaskScheduler;

void insertTask(TaskScheduler* scheduler, int id, int priority, int time) {
    if (scheduler->numTasks == MAX_TASKS) {
        printf("Scheduler is full. Cannot insert task.\n");
        return;
    }
    Task* newTask = (Task*) malloc(sizeof(Task));
    newTask->id = id;
    newTask->priority = priority;
    newTask->time = time;
    newTask->completed = false;
    scheduler->tasks[scheduler->numTasks] = newTask;
    scheduler->numTasks++;
}

void removeTask(TaskScheduler* scheduler, int id) {
    int index = -1;
    for (int i = 0; i < scheduler->numTasks; i++) {
        if (scheduler->tasks[i]->id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Task with ID %d not found.\n", id);
        return;
    }
    free(scheduler->tasks[index]);
    for (int i = index; i < scheduler->numTasks - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i + 1];
    }
    scheduler->numTasks--;
}

Task* getHighestPriorityTask(TaskScheduler* scheduler) {
    Task* highestPriorityTask = NULL;
    int highestPriority = -1;
    for (int i = 0; i < scheduler->numTasks; i++) {
        Task* task = scheduler->tasks[i];
        if (!task->completed && task->priority > highestPriority) {
            highestPriorityTask = task;
            highestPriority = task->priority;
        }
    }
    return highestPriorityTask;
}

void runTask(Task* task) {
    printf("Running task with ID %d...\n", task->id);
    for (int i = 1; i <= task->time; i++) {
        printf("Task %d: %d/%d\n", task->id, i, task->time);
        sleep(1);
    }
    printf("Task with ID %d completed.\n", task->id);
    task->completed = true;
}

int main() {
    TaskScheduler scheduler;
    scheduler.numTasks = 0;
    srand(time(NULL));
    
    // Generate random tasks
    for (int i = 1; i <= MAX_TASKS; i++) {
        int id = i;
        int priority = rand() % 10;
        int time = rand() % MAX_TASK_TIME + 1;
        insertTask(&scheduler, id, priority, time);
    }
    
    // Run tasks in order of priority
    while (scheduler.numTasks > 0) {
        Task* task = getHighestPriorityTask(&scheduler);
        if (task == NULL) {
            printf("Scheduler is empty.\n");
            break;
        }
        runTask(task);
        removeTask(&scheduler, task->id);
    }
    
    return 0;
}