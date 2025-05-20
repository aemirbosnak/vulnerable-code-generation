//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int duration;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int duration) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);

    while (head) {
        struct tm* tm_task = localtime(&head->duration);

        if (tm_now->tm_hour == tm_task->tm_hour && tm_now->tm_min == tm_task->tm_min) {
            printf("Executing task: %s\n", head->name);
            sleep(head->duration);
        }

        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 10);
    addTask(&head, "Task 2", 15);
    addTask(&head, "Task 3", 20);

    scheduleTasks(head);

    return 0;
}