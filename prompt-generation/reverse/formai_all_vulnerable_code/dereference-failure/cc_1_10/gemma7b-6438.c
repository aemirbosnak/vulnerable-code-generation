//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    time_t scheduled_time;
    struct Task *next;
} Task;

void addTask(Task **head, char *name, int priority, time_t scheduled_time) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->scheduled_time = scheduled_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task *head) {
    time_t now = time(NULL);
    Task *currentTask = head;

    while (currentTask) {
        if (currentTask->scheduled_time <= now) {
            printf("%s has started!\n", currentTask->name);
            sleep(2);
            printf("%s has finished.\n", currentTask->name);
            free(currentTask);
            currentTask = NULL;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task *head = NULL;

    addTask(head, "Task 1", 1, time(NULL) + 5);
    addTask(head, "Task 2", 2, time(NULL) + 3);
    addTask(head, "Task 3", 1, time(NULL) + 2);

    scheduleTasks(head);

    return 0;
}