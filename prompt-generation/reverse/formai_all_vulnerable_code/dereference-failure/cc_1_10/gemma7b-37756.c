//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct Task {
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
    time_t next_slot = now + 60 * head->time_slot;
    printf("Tasks for %s:\n", asctime(localtime(&now)));
    printf("----------------------------------------\n");
    while (head)
    {
        if (now < next_slot)
        {
            printf("%s (priority %d)\n", head->name, head->priority);
        }
        head = head->next;
    }
}

int main()
{
    Task* head = NULL;

    insert_task(&head, "Do homework", 3, 10);
    insert_task(&head, "Go shopping", 2, 12);
    insert_task(&head, "Watch TV", 1, 14);
    insert_task(&head, "Meet friends", 4, 16);
    insert_task(&head, "Clean the house", 2, 18);

    schedule_tasks(head);

    return 0;
}