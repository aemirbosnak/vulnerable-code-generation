//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10
#define TASK_NAME_SIZE 20

struct Task
{
    char name[TASK_NAME_SIZE];
    int start_time;
    int end_time;
    struct Task* next;
};

void add_task(struct Task** head, char* name, int start_time, int end_time)
{
    struct Task* new_task = malloc(sizeof(struct Task));

    strcpy(new_task->name, name);
    new_task->start_time = start_time;
    new_task->end_time = end_time;
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

void print_schedule(struct Task* head)
{
    struct Task* current = head;

    printf("Current Schedule:\n");
    while (current)
    {
        printf("  %s: Start time %d, End time %d\n", current->name, current->start_time, current->end_time);
        current = current->next;
    }
}

int main()
{
    struct Task* head = NULL;

    add_task(&head, "Wake up", 7, 10);
    add_task(&head, "Breakfast", 8, 9);
    add_task(&head, "School", 9, 16);
    add_task(&head, "Lunch", 12, 13);
    add_task(&head, "Homework", 14, 16);
    add_task(&head, "Dinner", 17, 19);
    add_task(&head, "Watch TV", 19, 22);

    print_schedule(head);

    return 0;
}