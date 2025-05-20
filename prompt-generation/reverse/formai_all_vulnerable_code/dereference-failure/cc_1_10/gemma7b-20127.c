//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int duration;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int duration) {
    Task* newTask = malloc(sizeof(Task));
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
    time_t nextTaskTime = now + head->duration;

    while (head) {
        if (now >= nextTaskTime) {
            printf("Task: %s, start time: %ld, duration: %d\n", head->name, nextTaskTime, head->duration);
            nextTaskTime += head->duration;
        }
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 10);
    addTask(&head, "Task 2", 15);
    addTask(&head, "Task 3", 20);
    addTask(&head, "Task 4", 5);
    addTask(&head, "Task 5", 12);

    scheduleTasks(head);

    return 0;
}