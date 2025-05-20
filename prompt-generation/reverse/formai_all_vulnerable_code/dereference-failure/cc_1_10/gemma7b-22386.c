//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task
{
    char name[20];
    int priority;
    int executionTime;
    struct Task* nextTask;
} Task;

Task* createTask(char* name, int priority, int executionTime)
{
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->executionTime = executionTime;
    newTask->nextTask = NULL;
    return newTask;
}

void scheduleTasks(Task* taskHead)
{
    time_t currentTime = time(NULL);
    Task* currentTask = taskHead;

    while (currentTask)
    {
        if (currentTime >= currentTask->executionTime)
        {
            printf("Executing task: %s\n", currentTask->name);
            currentTime += currentTask->executionTime;
            currentTask = currentTask->nextTask;
        }
        else
        {
            currentTask = currentTask->nextTask;
        }
    }
}

int main()
{
    Task* taskHead = NULL;

    taskHead = createTask("Math Homework", 1, 30);
    taskHead = createTask("Physics Quiz", 2, 45);
    taskHead = createTask("Biology Lab", 3, 60);

    scheduleTasks(taskHead);

    return 0;
}