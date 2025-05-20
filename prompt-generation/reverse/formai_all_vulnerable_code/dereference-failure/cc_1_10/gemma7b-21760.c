//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5

struct Task
{
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
};

struct Task** create_task_list()
{
    struct Task** head = (struct Task**)malloc(sizeof(struct Task*) * NUM_TASKS);
    for (int i = 0; i < NUM_TASKS; i++)
    {
        head[i] = NULL;
    }
    return head;
}

void add_task(struct Task** head, char* name, int priority, int estimated_time)
{
    struct Task* new_task = (struct Task*)malloc(sizeof(struct Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_time = estimated_time;
    new_task->next = NULL;

    if (head[priority] == NULL)
    {
        head[priority] = new_task;
    }
    else
    {
        head[priority]->next = new_task;
    }
}

void print_task_list(struct Task** head)
{
    for (int i = 0; i < NUM_TASKS; i++)
    {
        struct Task* current_task = head[i];
        while (current_task)
        {
            printf("Name: %s, Priority: %d, Estimated Time: %d\n", current_task->name, current_task->priority, current_task->estimated_time);
            current_task = current_task->next;
        }
    }
}

int main()
{
    struct Task** task_list = create_task_list();

    add_task(task_list, "Task 1", 1, 30);
    add_task(task_list, "Task 2", 2, 20);
    add_task(task_list, "Task 3", 1, 40);
    add_task(task_list, "Task 4", 2, 10);
    add_task(task_list, "Task 5", 3, 25);

    print_task_list(task_list);

    return 0;
}