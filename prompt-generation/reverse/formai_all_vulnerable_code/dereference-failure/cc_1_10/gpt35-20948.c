//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task
{
    int task_id;
    char *task_name;
    int priority;
} Task;

typedef struct TaskScheduler
{
    Task **tasks;
    int task_count;
    int max_tasks;
} TaskScheduler;

TaskScheduler *createTaskScheduler(int max_tasks)
{
    TaskScheduler *ts = malloc(sizeof(TaskScheduler));
    ts->tasks = malloc(sizeof(Task*) * max_tasks);
    ts->task_count = 0;
    ts->max_tasks = max_tasks;
    return ts;
}

void addTask(TaskScheduler *ts, Task *task)
{
    if (ts->task_count == ts->max_tasks)
    {
        printf("Task Scheduler is full. Could not add task.\n");
        return;
    }
    ts->tasks[ts->task_count++] = task;
}

void printTask(Task *task)
{
    printf("Task ID: %d, Name: %s, Priority: %d\n", task->task_id, task->task_name, task->priority);
}

void printTaskScheduler(TaskScheduler *ts)
{
    printf("Task Scheduler:\n");
    for (int i = 0; i < ts->task_count; i++)
    {
        printf("%d. ", i+1);
        printTask(ts->tasks[i]);
    }
}

void executeTask(Task *task)
{
    printf("Executing task: %s\n", task->task_name);
}

Task *getHighestPriorityTask(TaskScheduler *ts)
{
    if (ts->task_count == 0)
    {
        return NULL;
    }
    Task *highest_priority_task = ts->tasks[0];
    for (int i = 1; i < ts->task_count; i++)
    {
        if (ts->tasks[i]->priority > highest_priority_task->priority)
        {
            highest_priority_task = ts->tasks[i];
        }
    }
    return highest_priority_task;
}

bool removeTask(TaskScheduler *ts, int task_id)
{
    for (int i = 0; i < ts->task_count; i++)
    {
        if (ts->tasks[i]->task_id == task_id)
        {
            printf("Removing task: %s\n", ts->tasks[i]->task_name);
            free(ts->tasks[i]);
            ts->tasks[i] = ts->tasks[--ts->task_count];
            return true;
        }
    }
    printf("Task with ID %d not found.\n", task_id);
    return false;
}

int main()
{
    TaskScheduler *ts = createTaskScheduler(5);
    
    Task *task1 = malloc(sizeof(Task));
    task1->task_id = 1;
    task1->task_name = "Implement binary search algorithm";
    task1->priority = 3;
    addTask(ts, task1);
    
    Task *task2 = malloc(sizeof(Task));
    task2->task_id = 2;
    task2->task_name = "Refactor code for modularity";
    task2->priority = 2;
    addTask(ts, task2);
    
    Task *task3 = malloc(sizeof(Task));
    task3->task_id = 3;
    task3->task_name = "Write unit tests for database layer";
    task3->priority = 5;
    addTask(ts, task3);
    
    printf("Higest priority task: ");
    printTask(getHighestPriorityTask(ts));
    
    removeTask(ts, 2);
    
    printf("\n");
    printTaskScheduler(ts);
    
    executeTask(getHighestPriorityTask(ts));
    
    return 0;
}