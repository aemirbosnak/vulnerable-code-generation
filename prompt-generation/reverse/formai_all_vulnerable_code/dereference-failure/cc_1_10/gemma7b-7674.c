//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t scheduled_time;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority, time_t scheduled_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->scheduled_time = scheduled_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (currentTask->scheduled_time <= now) {
            printf("Task: %s, Priority: %d, Start Time: %ld\n", currentTask->name, currentTask->priority, currentTask->scheduled_time);
            currentTask = currentTask->next;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 1, time(NULL) + 60);
    addTask(&head, "Task 2", 2, time(NULL) + 30);
    addTask(&head, "Task 3", 3, time(NULL) + 90);

    scheduleTasks(head);

    return 0;
}