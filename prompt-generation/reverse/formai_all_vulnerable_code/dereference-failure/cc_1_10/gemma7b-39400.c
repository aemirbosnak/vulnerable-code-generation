//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define TASK_TIME 5

typedef struct Task
{
    char name[20];
    int time;
    struct Task* next;
} Task;

Task* createTask(char* name, int time)
{
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->time = time;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task* head, char* name, int time)
{
    Task* newTask = createTask(name, time);
    if (head == NULL)
    {
        head = newTask;
    }
    else
    {
        head->next = newTask;
    }
}

void scheduleTasks(Task* head)
{
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask)
    {
        if (currentTask->time >= now)
        {
            printf("Executing task: %s\n", currentTask->name);
            now += TASK_TIME;
        }
        currentTask = currentTask->next;
    }
}

int main()
{
    Task* head = NULL;
    addTask(head, "Task 1", 10);
    addTask(head, "Task 2", 15);
    addTask(head, "Task 3", 20);

    scheduleTasks(head);

    return 0;
}