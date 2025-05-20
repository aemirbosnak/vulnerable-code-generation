//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: complete
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
        ((*head)->next = newTask);
        *head = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    time_t nextTaskTime = now + head->duration;

    while (head) {
        if (now < nextTaskTime) {
            printf("Waiting for task: %s... ", head->name);
            sleep(head->duration);
            printf("Task: %s completed!\n", head->name);
            nextTaskTime = now + head->duration;
        } else {
            printf("Task: %s completed!\n", head->name);
            nextTaskTime = now + head->duration;
            head = head->next;
        }
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 10);
    addTask(&head, "Task 2", 5);
    addTask(&head, "Task 3", 15);
    addTask(&head, "Task 4", 20);
    addTask(&head, "Task 5", 12);

    scheduleTasks(head);

    return 0;
}