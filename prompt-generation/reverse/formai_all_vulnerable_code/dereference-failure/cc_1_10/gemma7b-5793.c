//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

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
    time_t nextTaskTime = now + 60;

    while (head) {
        if (now >= head->priority) {
            printf("Task: %s, completed at: %s\n", head->name, ctime(&now));
            head = head->next;
        } else {
            nextTaskTime = fmin(nextTaskTime, head->priority);
        }
    }

    printf("Next task scheduled to complete at: %s\n", ctime(&nextTaskTime));
}

int main() {
    Task* head = NULL;

    addTask(&head, "Do homework", 10);
    addTask(&head, "Eat dinner", 8);
    addTask(&head, "Go to the park", 6);
    addTask(&head, "Watch TV", 4);

    scheduleTasks(head);

    return 0;
}