//FormAI DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME 20

// Struct to hold task information
struct task {
    char name[MAX_NAME];
    time_t start_time;
    int duration;
};

// Function to print the list of tasks
void print_tasks(struct task* tasks, int num_tasks) {
    printf("TASKS:\n");
    for(int i = 0; i < num_tasks; i++) {
        printf("%s (%d seconds)\n", tasks[i].name, tasks[i].duration);
    }
}

// Function to check if all tasks have completed
int all_tasks_completed(int* completed_tasks, int num_tasks) {
    for(int i = 0; i < num_tasks; i++) {
        if(completed_tasks[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    // Initialize variables
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;
    int completed_tasks[MAX_TASKS] = {0};

    // Loop to add tasks
    char input[MAX_NAME + 10];
    while(num_tasks < MAX_TASKS) {
        printf("Enter task name (max %d characters) and duration in seconds, separated by a space (or enter 'done' to stop adding tasks):\n", MAX_NAME);
        fgets(input, MAX_NAME + 10, stdin);

        // Check if input is 'done'
        if(strncmp(input, "done", 4) == 0) {
            break;
        }

        // Parse input into task information
        char* task_name = strtok(input, " ");
        int duration = atoi(strtok(NULL, " "));

        // Add task to list
        strcpy(tasks[num_tasks].name, task_name);
        tasks[num_tasks].start_time = time(NULL);
        tasks[num_tasks].duration = duration;
        num_tasks++;
    }

    // Print list of tasks
    print_tasks(tasks, num_tasks);

    // Loop to execute tasks
    int current_task = 0;
    while(!all_tasks_completed(completed_tasks, num_tasks)) {
        if(completed_tasks[current_task] == 0) {
            struct task* task = &tasks[current_task];
            printf("Executing task: %s\n", task->name);

            // Wait for task to complete
            while(difftime(time(NULL), task->start_time) < task->duration) {
                sleep(1);
            }

            // Print completion message and mark task as completed
            printf("Task '%s' completed!\n", task->name);
            completed_tasks[current_task] = 1;
        }

        // Move on to next task
        current_task = (current_task + 1) % num_tasks;
    }

    printf("All tasks completed!\n");

    return 0;
}