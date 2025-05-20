//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define a task structure
typedef struct Task {
    char *name;
    int priority;
    int duration;
    struct Task *next;
} Task;

// Define a function to add a task to the scheduler
void addTask(Task **head, char *name, int priority, int duration) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->duration = duration;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

// Define a function to schedule tasks
void scheduleTasks(Task *head) {
    time_t now = time(NULL);
    time_t nextTaskTime = now + head->duration;

    while (head) {
        if (now < nextTaskTime) {
            printf("Task: %s, Priority: %d, Duration: %d\n", head->name, head->priority, head->duration);
            sleep(head->duration);
            nextTaskTime = now + head->duration;
        }
        head = head->next;
    }
}

int main() {
    Task *head = NULL;

    // Add some tasks to the scheduler
    addTask(&head, "Task 1", 1, 5);
    addTask(&head, "Task 2", 2, 10);
    addTask(&head, "Task 3", 3, 15);

    // Schedule the tasks
    scheduleTasks(head);

    return 0;
}