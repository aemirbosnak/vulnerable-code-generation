//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    int execution_time;
    struct Task *next;
} Task;

void add_task(Task **head, char *name, int priority, int execution_time) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void schedule_tasks(Task **head) {
    time_t now = time(NULL);
    Task *current_task = *head;

    while (current_task) {
        if (now >= current_task->execution_time) {
            printf("%s is executing...\n", current_task->name);
            sleep(current_task->execution_time);
            printf("%s has finished executing.\n", current_task->name);
            free(current_task);
            current_task = NULL;
        } else {
            current_task = current_task->next;
        }
    }

    printf("All tasks have been completed.\n");
}

int main() {
    Task *head = NULL;
    add_task(&head, "Task 1", 5, 10);
    add_task(&head, "Task 2", 3, 5);
    add_task(&head, "Task 3", 2, 2);
    schedule_tasks(&head);

    return 0;
}