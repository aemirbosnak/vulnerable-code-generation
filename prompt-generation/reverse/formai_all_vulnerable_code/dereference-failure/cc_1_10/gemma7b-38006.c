//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, time_t start_time, time_t end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task* head, Task* newTask) {
    if (head == NULL) {
        head = newTask;
    } else {
        newTask->next = head;
        head = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t current_time = time(NULL);
    Task* currentTask = head;
    while (currentTask) {
        if (current_time >= currentTask->start_time && current_time < currentTask->end_time) {
            printf("Task: %s, Start Time: %s, End Time: %s\n", currentTask->name, currentTask->start_time, currentTask->end_time);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;
    addTask(head, createTask("Task 1", 1, 10, 20));
    addTask(head, createTask("Task 2", 2, 15, 25));
    addTask(head, createTask("Task 3", 3, 20, 30));
    scheduleTasks(head);
    return 0;
}