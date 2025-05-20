//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int execution_time;
    struct Task* next;
} Task;

void insert_task(Task** head, char* name, int priority, int execution_time)
{
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
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
    Task* current_task = head;

    while (current_task)
    {
        time_t task_time = now + current_task->execution_time;

        if (task_time <= now)
        {
            printf("%s has completed execution.\n", current_task->name);
            free(current_task);
            current_task = head;
        }
        else
        {
            current_task = current_task->next;
        }
    }

    printf("All tasks have been completed.\n");
}

int main()
{
    Task* head = NULL;

    insert_task(&head, "Dinner", 1, 60);
    insert_task(&head, "Movies", 2, 90);
    insert_task(&head, "Shopping", 3, 120);

    schedule_tasks(head);

    return 0;
}