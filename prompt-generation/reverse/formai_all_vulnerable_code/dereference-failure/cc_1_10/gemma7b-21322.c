//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASK_NUMBER 10

typedef struct Task
{
    char name[20];
    int priority;
    struct Task* next;
} Task;

void addTask(Task* head, char* name, int priority)
{
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL)
    {
        head = newTask;
    }
    else
    {
        Task* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

void scheduleTasks(Task* head)
{
    time_t now = time(NULL);
    int i = 0;

    printf("Tasks scheduled for today:\n");
    while (head)
    {
        int taskTime = head->priority * 10;
        if (taskTime >= now)
        {
            printf("%s (priority %d) will run at %d:%02d\n", head->name, head->priority, taskTime / 3600, (taskTime % 3600) / 60);
        }
        head = head->next;
    }
}

int main()
{
    Task* head = NULL;

    addTask(head, "Do homework", 1);
    addTask(head, "Buy groceries", 3);
    addTask(head, "Clean the house", 2);
    addTask(head, "Watch TV", 4);

    scheduleTasks(head);

    return 0;
}