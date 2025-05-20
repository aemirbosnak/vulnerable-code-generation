//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task
{
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int time_slot)
{
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->time_slot = time_slot;
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

void scheduleTasks(Task* head)
{
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);

    while (head)
    {
        struct tm* tm_task = localtime(&head->time_slot);

        if (tm_now->tm_hour == tm_task->tm_hour && tm_now->tm_min == tm_task->tm_min)
        {
            printf("Task: %s, Priority: %d\n", head->name, head->priority);
            head = head->next;
        }
        else
        {
            head = head->next;
        }
    }
}

int main()
{
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, 10);
    insertTask(&head, "Task 2", 2, 12);
    insertTask(&head, "Task 3", 3, 14);

    scheduleTasks(head);

    return 0;
}