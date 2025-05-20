//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task
{
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

void insert_task(Task** head, char* name, int priority, int time_slot)
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

void schedule_tasks(Task* head)
{
    time_t now = time(NULL);
    time_t next_slot = now + 60;

    while (head)
    {
        if (head->time_slot == next_slot)
        {
            printf("Executing task: %s\n", head->name);
            next_slot += 60;
        }
        head = head->next;
    }
}

int main()
{
    Task* head = NULL;

    insert_task(&head, "Wake up", 1, 8);
    insert_task(&head, "Breakfast", 2, 9);
    insert_task(&head, "School", 3, 10);
    insert_task(&head, "Lunch", 2, 12);
    insert_task(&head, "Study", 1, 14);
    insert_task(&head, "Dinner", 3, 16);
    insert_task(&head, "Sleep", 4, 18);

    schedule_tasks(head);

    return 0;
}