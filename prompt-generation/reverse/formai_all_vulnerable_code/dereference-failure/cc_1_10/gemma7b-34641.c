//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_SCHEDULE 10

typedef struct Task {
    char name[20];
    int priority;
    int execution_time;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, int execution_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->execution_time = execution_time;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task* head, Task* newTask) {
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

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;
    while (currentTask) {
        if (currentTask->execution_time <= now) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(currentTask->execution_time);
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* head = NULL;
    addTask(head, createTask("Task 1", 1, 5));
    addTask(head, createTask("Task 2", 2, 3));
    addTask(head, createTask("Task 3", 3, 2));
    addTask(head, createTask("Task 4", 4, 4));
    addTask(head, createTask("Task 5", 5, 1));

    scheduleTasks(head);

    return 0;
}