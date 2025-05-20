//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Maximum number of tasks that can be scheduled */
#define MAX_TASKS 100

/* Structure to hold task information */
typedef struct {
    char name[50];
    int priority;
    int time_to_run;
    time_t scheduled_time;
} Task;

/* Global array to hold all scheduled tasks */
Task tasks[MAX_TASKS];

/* Count of scheduled tasks */
int task_count = 0;

/* Function to add a task to the scheduler */
void add_task(char* name, int priority, int time_to_run) {
    /* Make sure there's room for the task */
    if (task_count >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached!\n");
        return;
    }

    /* Create a new task */
    Task new_task;
    strcpy(new_task.name, name);
    new_task.priority = priority;
    new_task.time_to_run = time_to_run;

    /* Determine the scheduled time for the task */
    if (task_count == 0) {
        /* First task starts now */
        new_task.scheduled_time = time(NULL);
    } else {
        /* Scheduled time is the end of the previous task */
        new_task.scheduled_time = tasks[task_count-1].scheduled_time + tasks[task_count-1].time_to_run;
    }

    /* Add the task to the array */
    tasks[task_count] = new_task;
    task_count++;
}

/* Function to print out all scheduled tasks */
void print_tasks() {
    printf("Scheduled Tasks:\n");
    printf("-----------------\n");
    for (int i = 0; i < task_count; i++) {
        /* Convert the scheduled time to a string */
        char* scheduled_time_str = ctime(&tasks[i].scheduled_time);
        /* Remove the newline character at the end of the string */
        scheduled_time_str[strlen(scheduled_time_str)-1] = '\0';
        printf("%s - Priority: %d - Time to run: %d seconds\n", scheduled_time_str, tasks[i].priority, tasks[i].time_to_run);
    }
}

int main() {
    /* Add some tasks */
    add_task("Task 1", 3, 5);
    add_task("Task 2", 1, 10);
    add_task("Task 3", 2, 7);
    add_task("Task 4", 2, 3);
    add_task("Task 5", 3, 8);

    /* Print out the scheduled tasks */
    print_tasks();

    return 0;
}