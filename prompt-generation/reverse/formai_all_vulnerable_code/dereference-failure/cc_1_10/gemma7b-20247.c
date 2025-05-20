//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    int i = 0;

    while (head) {
        int scheduledTime = head->priority * 10 + now;
        if (scheduledTime > now) {
            printf("Task: %s, scheduled at: %d\n", head->name, scheduledTime);
            i++;
        }
        head = head->next;
    }

    if (i == 0) {
        printf("No tasks scheduled.\n");
    }
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 1);
    addTask(&head, "Task 2", 3);
    addTask(&head, "Task 3", 2);
    addTask(&head, "Task 4", 4);

    scheduleTasks(head);

    return 0;
}