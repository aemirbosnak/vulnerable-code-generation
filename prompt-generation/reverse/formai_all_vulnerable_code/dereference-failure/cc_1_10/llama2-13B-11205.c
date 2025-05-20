//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_DESCRIPTION_LENGTH 50

// Structure to hold a task
typedef struct {
    char name[50]; // Task name
    char description[50]; // Task description
    int priority; // Priority (1-5)
    int due_date; // Due date (in days)
    int completed; // Completed flag (0-1)
} task_t;

// Global variables
task_t tasks[MAX_TASKS];
int num_tasks;

// Function to add a task
void add_task(char *name, char *description, int priority, int due_date) {
    task_t *task = (task_t *)malloc(sizeof(task_t));
    strcpy(task->name, name);
    strcpy(task->description, description);
    task->priority = priority;
    task->due_date = due_date;
    task->completed = 0;
    num_tasks++;
    tasks[num_tasks - 1] = *task;
}

// Function to mark a task as completed
void mark_task_completed(int task_num) {
    tasks[task_num].completed = 1;
}

// Function to print the tasks
void print_tasks() {
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("Task %d: %s (%s, priority %d, due %d, completed %d)\n",
            i + 1, tasks[i].name, tasks[i].description, tasks[i].priority, tasks[i].due_date, tasks[i].completed);
    }
}

// Function to run the scheduler
void run_scheduler() {
    int i, j;
    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].due_date <= time(NULL) && !tasks[i].completed) {
            // Task is overdue, mark it as completed
            mark_task_completed(i);
            // Print the task
            printf("Task %d: %s (%s, priority %d, due %d, completed %d)\n",
                i + 1, tasks[i].name, tasks[i].description, tasks[i].priority, tasks[i].due_date, tasks[i].completed);
        }
    }
}

int main() {
    // Add some tasks
    add_task("Gather firewood", "Collect firewood for the castle's fireplaces", 3, 3);
    add_task("Repair the moat", "Repair the damaged sections of the castle's moat", 4, 5);
    add_task("Train the guards", "Train the castle's guards in combat and archery", 2, 7);
    add_task("Plan the harvest", "Plan the harvest for the castle's crops", 1, 10);

    // Run the scheduler
    run_scheduler();

    return 0;
}