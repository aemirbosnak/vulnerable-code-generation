//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASK_NUMBER 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    int remaining_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int estimated_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->estimated_time = estimated_time;
    newTask->remaining_time = estimated_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* currentTask = *head;
        while (currentTask->next) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void updateRemainingTime(Task* task, int timeElapsed) {
    task->remaining_time -= timeElapsed;
}

void printTasks(Task* head) {
    printf("Tasks:\n");
    while (head) {
        printf("%s (priority: %d, remaining time: %d)\n", head->name, head->priority, head->remaining_time);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, 20);
    insertTask(&head, "Task 2", 2, 15);
    insertTask(&head, "Task 3", 3, 10);

    time_t start_time = time(NULL);

    updateRemainingTime(head, 5);
    updateRemainingTime(head->next, 3);

    time_t end_time = time(NULL);

    printTasks(head);

    printf("Time elapsed: %d seconds\n", end_time - start_time);

    return 0;
}