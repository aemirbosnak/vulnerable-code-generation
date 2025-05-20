//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct Task
{
    char *name;
    int (*function)(void);
    struct Task *next;
} Task;

void addTask(Task **head, char *name, int function)
{
    Task *newTask = malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->function = function;
    newTask->next = NULL;

    if (*head == NULL)
    {
        *head = newTask;
    }
    else
    {
        (*head)->next = newTask;
    }
}

void scheduler(Task **head)
{
    Task *currentTask = *head;

    while (currentTask)
    {
        printf("Executing task: %s\n", currentTask->name);
        currentTask->function();
        sleep(1);
        currentTask = currentTask->next;
    }
}

int task1(void)
{
    return 0;
}

int task2(void)
{
    return 1;
}

int main()
{
    Task *head = NULL;
    addTask(&head, "Task 1", task1);
    addTask(&head, "Task 2", task2);

    scheduler(&head);

    return 0;
}