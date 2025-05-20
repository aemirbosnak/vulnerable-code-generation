//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h> 
#include <stdbool.h> 

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 20

typedef struct Task {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    void (*function)(void);
    bool isDone;
} Task;

Task taskList[MAX_TASKS];
int numOfTasks = 0;

void addTask(char name[], int priority, void (*function)(void)) {
    if (numOfTasks >= MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }
    Task newTask = {name, priority, function, false};
    taskList[numOfTasks++] = newTask;
}

void runTasks() {
    int highestPriorityTaskIndex;
    while (numOfTasks > 0) {
        highestPriorityTaskIndex = 0;
        for (int i = 1; i < numOfTasks; i++) {
            if (taskList[i].priority > taskList[highestPriorityTaskIndex].priority) {
                highestPriorityTaskIndex = i;
            }
        }
        printf("Running task \"%s\" with priority %d.\n", taskList[highestPriorityTaskIndex].name, taskList[highestPriorityTaskIndex].priority);
        taskList[highestPriorityTaskIndex].function();
        taskList[highestPriorityTaskIndex].isDone = true;
        // Shift remaining tasks left
        for (int i = highestPriorityTaskIndex; i < numOfTasks-1; i++) {
            taskList[i] = taskList[i+1];
        }
        numOfTasks--;
    }
}

void task1() {
    printf("Executing task 1...\n");
}

void task2() {
    printf("Executing task 2...\n");
}

int main() {
    addTask("Task 1", 1, &task1);
    addTask("Task 2", 2, &task2);
    printf("Starting task scheduler...\n");
    runTasks();
    printf("All tasks completed.\n");
    return 0;
}