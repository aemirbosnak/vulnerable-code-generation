//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
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
            printf("Task: %s, Priority: %d, Executed at: %s\n", currentTask->name, currentTask->priority, asctime(localtime(&currentTask->scheduled_time)));
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Wake up", 1, time(NULL) + 60 * 6);
    addTask(&head, "Breakfast", 2, time(NULL) + 60 * 8);
    addTask(&head, "Work", 3, time(NULL) + 60 * 10);
    addTask(&head, "Lunch", 2, time(NULL) + 60 * 12);
    addTask(&head, "Nap", 1, time(NULL) + 60 * 14);
    addTask(&head, "Dinner", 3, time(NULL) + 60 * 18);
    addTask(&head, "Watch TV", 2, time(NULL) + 60 * 20);

    scheduleTasks(head);

    return 0;
}