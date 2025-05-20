//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: authentic
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

void addTask(Task** head) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    printf("Enter task name: ");
    scanf("%s", newTask->name);
    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask->priority);
    printf("Enter estimated time (in minutes): ");
    scanf("%d", &newTask->estimated_time);
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void displayTasks(Task* head) {
    printf("Tasks:\n");
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Priority: %d\n", head->priority);
        printf("Estimated time: %d minutes\n", head->estimated_time);
        printf("\n");
        head = head->next;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    for (Task* task = head; task; task = task->next) {
        int estimatedTime = task->estimated_time * 60;
        int remainingTime = estimatedTime - now;
        if (remainingTime > 0) {
            printf("Task: %s, Remaining time: %d minutes\n", task->name, remainingTime);
        }
    }
}

int main() {
    Task* head = NULL;
    addTask(&head);
    addTask(&head);
    addTask(&head);
    displayTasks(head);
    scheduleTasks(head);

    return 0;
}