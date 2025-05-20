//FormAI DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of tasks the scheduler can handle
#define MAX_TASKS 10

// Define structure for task
typedef struct {
    int id;
    char* name;
    int time;
    bool completed;
} Task;

// Define global variables
Task tasks[MAX_TASKS];
int task_count = 0;

// Function to add task to the scheduler
void add_task(char* name, int time) {
    // Check if maximum number of tasks has been reached
    if (task_count >= MAX_TASKS) {
        printf("Maximum number of tasks reached");
        return;
    }
    // Allocate memory for new task
    Task* new_task = (Task*) malloc(sizeof(Task));
    new_task->id = task_count + 1;
    new_task->name = name;
    new_task->time = time;
    new_task->completed = false;
    // Add new task to array
    tasks[task_count] = *new_task;
    // Update task count
    task_count++;
    // Print confirmation message
    printf("Task %d added to scheduler\n", new_task->id);
}

// Function to print tasks in the scheduler
void print_tasks() {
    // Print table header
    printf("| %-4s| %-20s| %-10s| %-10s|\n", "ID", "Name", "Time", "Completed");
    printf("|----|----------------------|-----------|-----------|\n");
    // Loop through tasks and print details
    for (int i = 0; i < task_count; i++) {
        printf("| %-4d| %-20s| %-10d| %-10s|\n", tasks[i].id, tasks[i].name, tasks[i].time, tasks[i].completed ? "Yes" : "No");
    }
}

// Function to remove task from the scheduler
void remove_task(int id) {
    // Check if ID is valid
    if (id < 1 || id > task_count) {
        printf("Invalid task ID");
        return;
    }
    // Remove task from array by shifting all tasks to the left
    for (int i = id; i < task_count; i++) {
        tasks[i - 1] = tasks[i];
    }
    // Update task count
    task_count--;
    // Print confirmation message
    printf("Task %d removed from scheduler\n", id);
}

// Function to complete a task in the scheduler
void complete_task(int id) {
    // Check if ID is valid
    if (id < 1 || id > task_count) {
        printf("Invalid task ID");
        return;
    }
    // Mark task as completed
    tasks[id - 1].completed = true;
    // Print confirmation message
    printf("Task %d marked as completed\n", id);
}

// Function to schedule tasks
void schedule_tasks() {
    // Loop through tasks and run each one
    for (int i = 0; i < task_count; i++) {
        // Print details of current task
        printf("Task %d: %s (Estimated time: %d minutes)\n", tasks[i].id, tasks[i].name, tasks[i].time);
        // Wait for task to complete
        int time_remaining = tasks[i].time;
        while (time_remaining > 0) {
            printf("%d minutes remaining...\n", time_remaining);
            sleep(1);
            time_remaining--;
        }
        // Mark task as completed
        tasks[i].completed = true;
        printf("Task %d completed!\n\n", tasks[i].id);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    // Add some tasks to the scheduler
    add_task("Clean the house", 30);
    add_task("Do laundry", 45);
    add_task("Buy groceries", 60);
    add_task("Finish work project", 120);
    // Print current tasks in the scheduler
    print_tasks();
    // Let's say the user wants to remove task 3
    remove_task(3);
    // Print updated tasks in the scheduler
    print_tasks();
    // Let's say the user has completed task 1
    complete_task(1);
    // Print updated tasks in the scheduler
    print_tasks();
    // Let's schedule the remaining tasks
    schedule_tasks();
    // Print final tasks in the scheduler
    print_tasks();
    return 0;
}