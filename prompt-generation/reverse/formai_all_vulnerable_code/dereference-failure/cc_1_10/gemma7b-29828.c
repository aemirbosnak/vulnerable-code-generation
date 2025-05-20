//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_TASKS 5

struct Task {
    char name[20];
    int priority;
    int duration;
    struct Task* next;
};

struct Task* createTask(char* name, int priority, int duration) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->duration = duration;
    newTask->next = NULL;
    return newTask;
}

void addTask(struct Task** head, char* name, int priority, int duration) {
    struct Task* newTask = createTask(name, priority, duration);
    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(struct Task* head) {
    time_t now = time(NULL);
    struct Task* currentTask = head;
    while (currentTask) {
        int remainingTime = currentTask->duration - (time(NULL) - now);
        if (remainingTime > 0) {
            printf("Task: %s, remaining time: %d seconds\n", currentTask->name, remainingTime);
        } else {
            printf("Task: %s completed!\n", currentTask->name);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    struct Task* tasks = NULL;
    addTask(&tasks, "Task 1", 1, 10);
    addTask(&tasks, "Task 2", 2, 5);
    addTask(&tasks, "Task 3", 3, 15);
    addTask(&tasks, "Task 4", 4, 20);
    addTask(&tasks, "Task 5", 5, 25);

    scheduleTasks(tasks);

    return 0;
}