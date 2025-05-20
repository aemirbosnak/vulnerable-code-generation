//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_SIZE 20

typedef struct Task {
    char name[TASK_SIZE];
    int duration;
    struct Task* next;
} Task;

void addTask(Task* head, char* name, int duration) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        head->next = newTask;
    }
}

void executeTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        time_t taskStart = time(NULL) - currentTask->duration;
        if (taskStart <= now) {
            printf("%s has completed!\n", currentTask->name);
            free(currentTask);
            currentTask = head;
        } else {
            currentTask = currentTask->next;
        }
    }

    printf("All tasks have completed.\n");
}

int main() {
    Task* head = NULL;

    addTask(head, "Slay the Dragon", 5);
    addTask(head, "Collect the Dragon's Jewel", 3);
    addTask(head, "Create a Dam", 2);
    addTask(head, "Build a Tower", 4);

    executeTasks(head);

    return 0;
}