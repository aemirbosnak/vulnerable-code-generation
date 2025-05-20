//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    int duration;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority, int duration) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
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
    time_t nextTaskTime = now + head->duration;

    while (head) {
        if (now < nextTaskTime) {
            printf("Task: %s, Priority: %d, Duration: %d seconds\n", head->name, head->priority, head->duration);
            sleep(head->duration);
            nextTaskTime = now + head->duration;
        } else {
            head = head->next;
        }
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 1, 5);
    addTask(&head, "Task 2", 2, 10);
    addTask(&head, "Task 3", 3, 15);
    addTask(&head, "Task 4", 4, 20);
    addTask(&head, "Task 5", 5, 25);

    scheduleTasks(head);

    return 0;
}