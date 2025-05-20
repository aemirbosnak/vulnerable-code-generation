//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 5
#define MAX_TIMES 10

typedef struct Task {
    char* name;
    int time;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

int main() {
    printf("Welcome to the Ephemeral Task Scheduler!\n");

    // Initialize tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].name = (char*)malloc(50);
        tasks[i].time = (rand() % 3600) + 1;
        sprintf(tasks[i].name, "Task %d", i+1);
        printf("Task %d: %s\n", i+1, tasks[i].name);
    }

    // Sort tasks by time
    for (int i = 0; i < taskCount; i++) {
        for (int j = i+1; j < taskCount; j++) {
            if (tasks[j].time < tasks[i].time) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Print sorted tasks
    printf("Sorted Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s - %d seconds\n", i+1, tasks[i].name, tasks[i].time);
    }

    // Simulate task execution
    for (int i = 0; i < taskCount; i++) {
        printf("%d. Task %s completed in %d seconds\n", i+1, tasks[i].name, tasks[i].time);
        sleep(tasks[i].time);
    }

    return 0;
}