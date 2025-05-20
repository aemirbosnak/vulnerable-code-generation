//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a task structure
typedef struct Task
{
    char name[20];
    int duration;
    struct Task* next;
} Task;

// Function to add a task to the end of the list
void addTask(Task** head, char* name, int duration)
{
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
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

// Function to schedule tasks
void scheduleTasks(Task* head)
{
    time_t now = time(NULL);
    time_t nextTaskTime = now + head->duration;

    printf("Next task: %s scheduled for %ld seconds from now\n", head->name, nextTaskTime - now);

    while (head->next)
    {
        head = head->next;
        nextTaskTime = now + head->duration;

        printf("Next task: %s scheduled for %ld seconds from now\n", head->name, nextTaskTime - now);
    }
}

int main()
{
    Task* head = NULL;

    addTask(&head, "Task 1", 10);
    addTask(&head, "Task 2", 15);
    addTask(&head, "Task 3", 20);

    scheduleTasks(head);

    return 0;
}