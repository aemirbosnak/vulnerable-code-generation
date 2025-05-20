//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* currentTask = head;
        while (currentTask->next != NULL) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void scheduleTasks() {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        int taskTime = now - currentTask->priority;
        if (taskTime >= 0) {
            printf("%s is running...\n", currentTask->name);
            sleep(2);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    addTask("Task 1", 5);
    addTask("Task 2", 3);
    addTask("Task 3", 2);
    addTask("Task 4", 4);

    scheduleTasks();

    return 0;
}