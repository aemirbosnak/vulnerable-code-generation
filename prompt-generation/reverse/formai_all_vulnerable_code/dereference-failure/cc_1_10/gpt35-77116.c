//FormAI DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct task {
    char *name;
    int priority;
    int timeRequired;
    void (*funcPointer)();
} Task;

Task *tasks;
int taskCount = 0;

void addTask(char* name, int priority, int timeRequired, void (*funcPointer)()) 
{
    tasks = realloc(tasks, (taskCount + 1) * sizeof(Task));
    tasks[taskCount].name = name;
    tasks[taskCount].priority = priority;
    tasks[taskCount].timeRequired = timeRequired;
    tasks[taskCount].funcPointer = funcPointer;
    taskCount++;
}

void sortTasksByPriority() 
{
    for(int i = 0; i < taskCount; i++) 
    {
        for(int j = 0; j < taskCount - 1; j++) 
        {
            if(tasks[j].priority < tasks[j+1].priority) 
            {
                Task temp = tasks[j+1];
                tasks[j+1] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void executeTasks() 
{
    for(int i = 0; i < taskCount; i++)
    {
        time_t start_time, current_time;
        time(&start_time);
        while(difftime(current_time, start_time) < tasks[i].timeRequired) 
        {
            time(&current_time);
            tasks[i].funcPointer();
        }
    }
}

void task1() 
{
    printf("Executing task 1... Done!\n");
}

void task2() 
{
    printf("Executing task 2... Done!\n");
}

void task3() 
{
    printf("Executing task 3... Done!\n");
    sleep(3); // Simulate long task
}

void task4() 
{
    printf("Executing task 4... Done!\n");
}

void task5() 
{
    printf("Executing task 5... Done!\n");
}

int main() 
{
    addTask("Task 1", 2, 2, &task1);
    addTask("Task 2", 1, 4, &task2);
    addTask("Task 3", 3, 10, &task3);
    addTask("Task 4", 5, 1, &task4);
    addTask("Task 5", 4, 3, &task5);

    printf("Original Task Order:\n");
    for(int i = 0; i < taskCount; i++) 
    {
        printf("Task name: %s | Priority: %d | Time Required: %d\n", tasks[i].name, tasks[i].priority, tasks[i].timeRequired);
    }

    sortTasksByPriority();

    printf("\nSorted by Priority:\n");
    for(int i = 0; i < taskCount; i++) 
    {
        printf("Task name: %s | Priority: %d | Time Required: %d\n", tasks[i].name, tasks[i].priority, tasks[i].timeRequired);
    }

    printf("\nExecuting tasks:\n");
    executeTasks();

    return 0;
}