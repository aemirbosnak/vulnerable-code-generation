//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int duration;
    struct Task* next;
} Task;

Task* head = NULL;

void scheduleTask(char* name, int duration) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* currentTask = head;
        while (currentTask->next) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void executeTasks() {
    Task* currentTask = head;
    while (currentTask) {
        printf("Executing task: %s\n", currentTask->name);
        sleep(currentTask->duration);
        currentTask = currentTask->next;
    }
}

int main() {
    scheduleTask("Wake up", 10);
    scheduleTask("Breakfast", 20);
    scheduleTask("School", 40);
    scheduleTask("Lunch", 20);
    scheduleTask("Homework", 30);

    executeTasks();

    return 0;
}