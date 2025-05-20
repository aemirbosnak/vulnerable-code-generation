//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5

struct task
{
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct task* next;
};

struct task* head = NULL;

void addTask(char* name, int priority, time_t start_time, time_t end_time)
{
    struct task* newTask = (struct task*)malloc(sizeof(struct task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (head == NULL)
    {
        head = newTask;
    }
    else
    {
        struct task* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

void printTasks()
{
    struct task* temp = head;
    while (temp)
    {
        printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", temp->name, temp->priority, temp->start_time, temp->end_time);
        temp = temp->next;
    }
}

int main()
{
    addTask("Task 1", 1, time(NULL), time(NULL) + 60);
    addTask("Task 2", 2, time(NULL) + 30, time(NULL) + 60);
    addTask("Task 3", 3, time(NULL) + 60, time(NULL) + 90);
    addTask("Task 4", 4, time(NULL) + 30, time(NULL) + 60);
    addTask("Task 5", 5, time(NULL) + 60, time(NULL) + 90);

    printTasks();

    return 0;
}