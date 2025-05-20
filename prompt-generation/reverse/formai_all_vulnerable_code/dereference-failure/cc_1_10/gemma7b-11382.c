//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    int start_time;
    int end_time;
    struct Task *next;
} Task;

Task *insert_task(Task *head, char *name, int priority, int start_time, int end_time)
{
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_task;
    }

    return head;
}

void schedule_tasks(Task *head)
{
    time_t now = time(NULL);
    Task *current = head;

    while (current) {
        if (current->start_time <= now && now <= current->end_time) {
            printf("%s is running\n", current->name);
        }
        current = current->next;
    }
}

int main()
{
    Task *head = NULL;

    insert_task(head, "Task 1", 1, 10, 15);
    insert_task(head, "Task 2", 2, 12, 18);
    insert_task(head, "Task 3", 3, 14, 20);

    schedule_tasks(head);

    return 0;
}