//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASK_NUM 10

typedef struct task
{
    char name[20];
    int priority;
    int estimated_time;
    int remaining_time;
    struct task* next;
} task;

void insert_task(task** head, char* name, int priority, int estimated_time)
{
    task* new_task = (task*)malloc(sizeof(task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_time = estimated_time;
    new_task->remaining_time = estimated_time;
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

void schedule_tasks(task* head)
{
    time_t now = time(NULL);
    task* current_task = head;

    while (current_task)
    {
        int remaining_time = current_task->remaining_time - (int)(now - current_task->estimated_time);

        if (remaining_time > 0)
        {
            printf("%s is running\n", current_task->name);
            current_task->remaining_time = remaining_time;
        }
        else
        {
            printf("%s has finished\n", current_task->name);
            free(current_task);
            current_task = NULL;
        }
    }
}

int main()
{
    task* head = NULL;

    insert_task(&head, "Task 1", 1, 10);
    insert_task(&head, "Task 2", 2, 15);
    insert_task(&head, "Task 3", 3, 20);

    schedule_tasks(head);

    return 0;
}