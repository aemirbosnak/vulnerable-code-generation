//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 5

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
    time_t currentTime = time(NULL);
    time_t nextTime = currentTime;
    Task* currentTask = head;

    while (currentTask) {
        if (currentTime >= nextTime) {
            printf("Starting task: %s\n", currentTask->name);
            sleep(currentTask->duration);
            nextTime += currentTask->duration;
        }
        currentTask = currentTask->next;
    }

    printf("All tasks completed.\n");
}

int main() {
    Task* tasks = NULL;
    addTask(&tasks, "Wake up", 60);
    addTask(&tasks, "Breakfast", 30);
    addTask(&tasks, "Work", 120);
    addTask(&tasks, "Lunch", 60);
    addTask(&tasks, "Study", 90);

    scheduleTasks(tasks);

    return 0;
}