//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    time_t nextTaskTime = now + head->duration;

    while (head) {
        if (now >= nextTaskTime) {
            printf("Task: %s completed!\n", head->name);
            free(head);
            head = NULL;
            nextTaskTime = now + head->duration;
        } else {
            printf("Next task: %s in %d seconds.\n", head->name, (int)(nextTaskTime - now));
            head = head->next;
            nextTaskTime = now + head->duration;
        }
    }

    printf("All tasks completed.\n");
}

int main() {
    Task* head = NULL;

    addTask(&head, "Mop the floor", 5);
    addTask(&head, "Wash dishes", 3);
    addTask(&head, "Sweep the stairs", 4);

    scheduleTasks(head);

    return 0;
}