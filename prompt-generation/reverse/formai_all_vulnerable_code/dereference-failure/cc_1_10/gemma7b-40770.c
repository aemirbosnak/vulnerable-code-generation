//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task
{
    char name[20];
    int priority;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority)
{
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
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
    int i = 0;

    for (Task* task = head; task; task = task->next)
    {
        int taskTime = task->priority * 10;
        if (now >= taskTime)
        {
            printf("Task: %s, Priority: %d, Time: %d\n", task->name, task->priority, taskTime);
            i++;
        }
    }

    printf("Total tasks scheduled: %d\n", i);
}

int main()
{
    Task* head = NULL;

    addTask(&head, "Wash dishes", 3);
    addTask(&head, "Do laundry", 2);
    addTask(&head, "Cook dinner", 4);
    addTask(&head, "Clean the house", 1);
    addTask(&head, "Study for exams", 5);

    scheduleTasks(head);

    return 0;
}