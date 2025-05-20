//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task
{
    char *name;
    int priority;
    int execution_time;
    struct Task *next;
} Task;

void schedule_add(Task **head, char *name, int priority, int execution_time)
{
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (*head == NULL)
    {
        *head = new_task;
    }
    else
    {
        Task *temp = *head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_task;
    }
}

void schedule_execute(Task **head)
{
    Task *current_task = *head;

    while (current_task)
    {
        printf("Executing task: %s\n", current_task->name);
        sleep(current_task->execution_time);
        current_task = current_task->next;
    }
}

int main()
{
    Task *head = NULL;

    schedule_add(&head, "Task A", 1, 5);
    schedule_add(&head, "Task B", 3, 2);
    schedule_add(&head, "Task C", 2, 4);

    schedule_execute(&head);

    return 0;
}