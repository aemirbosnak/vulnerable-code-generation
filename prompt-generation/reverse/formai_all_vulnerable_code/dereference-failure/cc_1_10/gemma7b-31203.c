//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10
#define TASK_DELAY_MIN 1
#define TASK_DELAY_MAX 5

typedef struct Task {
    char name[20];
    int delay;
    struct Task* next;
} Task;

void scheduler_add(Task** head, char* name, int delay)
{
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->delay = delay;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void scheduler_execute(Task** head)
{
    time_t now = time(NULL);
    Task* current_task = *head;

    while (current_task) {
        if (now >= current_task->delay) {
            printf("Task: %s, executed at: %ld\n", current_task->name, now);
            current_task->delay += TASK_DELAY_MIN;
        } else {
            break;
        }
        current_task = current_task->next;
    }
}

int main()
{
    Task* head = NULL;

    scheduler_add(&head, "Task 1", 3);
    scheduler_add(&head, "Task 2", 5);
    scheduler_add(&head, "Task 3", 2);

    scheduler_execute(&head);

    return 0;
}