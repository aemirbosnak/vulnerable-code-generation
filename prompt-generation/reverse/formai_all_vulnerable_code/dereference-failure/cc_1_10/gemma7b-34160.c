//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task
{
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

void add_task(Task** head, char* name, int priority, int time_slot)
{
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->time_slot = time_slot;
    new_task->next = NULL;

    if (*head == NULL)
    {
        *head = new_task;
    }
    else
    {
        (*head)->next = new_task;
    }
}

void schedule_tasks(Task** head)
{
    Task* current_task = *head;
    while (current_task)
    {
        printf("Task: %s, Priority: %d, Time Slot: %d\n", current_task->name, current_task->priority, current_task->time_slot);
        sleep(current_task->time_slot);
        current_task = current_task->next;
    }
}

int main()
{
    Task* head = NULL;
    add_task(&head, "Task 1", 1, 5);
    add_task(&head, "Task 2", 2, 3);
    add_task(&head, "Task 3", 3, 2);
    add_task(&head, "Task 4", 4, 4);

    schedule_tasks(&head);

    return 0;
}