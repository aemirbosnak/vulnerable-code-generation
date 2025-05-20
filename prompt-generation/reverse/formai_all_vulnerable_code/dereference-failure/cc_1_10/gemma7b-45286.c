//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority, int time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->estimated_time = time;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* currentTask = head;
        while (currentTask->next) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }

    return head;
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (now >= currentTask->estimated_time) {
            printf("Task: %s, completed.\n", currentTask->name);
            free(currentTask);
            currentTask = NULL;
        } else {
            currentTask = currentTask->next;
        }
    }

    printf("All tasks completed.\n");
}

int main() {
    Task* head = NULL;
    insertTask(head, "Task 1", 1, 10);
    insertTask(head, "Task 2", 2, 15);
    insertTask(head, "Task 3", 3, 20);
    insertTask(head, "Task 4", 2, 12);

    scheduleTasks(head);

    return 0;
}