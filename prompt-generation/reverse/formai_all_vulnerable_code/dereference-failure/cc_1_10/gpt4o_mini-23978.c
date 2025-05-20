//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

// Task structure definition
typedef struct Task {
    int id;
    char name[50];
    int interval; // Interval in seconds
    time_t next_run;
    struct Task *next;
} Task;

// Global variables
Task *task_list = NULL;
int task_counter = 0;

// Function prototypes
void add_task(const char *name, int interval);
void remove_task(int id);
void display_tasks();
void execute_tasks();
void signal_handler(int signal);
void free_tasks();

// Function to add a new task
void add_task(const char *name, int interval) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->id = task_counter++;
    strncpy(new_task->name, name, 50);
    new_task->interval = interval;
    new_task->next_run = time(NULL) + interval;
    new_task->next = task_list;
    task_list = new_task;
    printf("Added task: %s with interval: %d seconds\n", name, interval);
}

// Function to remove a task by id
void remove_task(int id) {
    Task **current = &task_list;
    while (*current) {
        if ((*current)->id == id) {
            Task *to_delete = *current;
            *current = (*current)->next;
            free(to_delete);
            printf("Removed task with id: %d\n", id);
            return;
        }
        current = &(*current)->next;
    }
    printf("Task with id: %d not found.\n", id);
}

// Function to display all tasks
void display_tasks() {
    Task *current = task_list;
    printf("\nCurrent Scheduled Tasks:\n");
    while (current) {
        printf("Task ID: %d, Name: %s, Interval: %d seconds, Next Run: %s", 
            current->id, current->name, current->interval, ctime(&current->next_run));
        current = current->next;
    }
    printf("\n");
}

// Function to execute tasks that are due
void execute_tasks() {
    time_t current_time = time(NULL);
    Task *current = task_list;

    while (current) {
        if (current->next_run <= current_time) {
            printf("Executing task: %s (ID: %d)\n", current->name, current->id);
            current->next_run = current_time + current->interval;
        }
        current = current->next;
    }
}

// Signal handler for graceful exit
void signal_handler(int signal) {
    printf("\nCaught signal %d. Cleaning up tasks...\n", signal);
    free_tasks();
    exit(0);
}

// Function to free all tasks
void free_tasks() {
    Task *current = task_list;
    while (current) {
        Task *to_delete = current;
        current = current->next;
        free(to_delete);
    }
}

// Main function
int main() {
    signal(SIGINT, signal_handler);  // Capture Ctrl+C

    // Add sample tasks
    add_task("Task 1", 3);
    add_task("Task 2", 5);
    add_task("Task 3", 7);

    while (1) {
        execute_tasks();
        display_tasks();
        sleep(1); // Sleep before checking tasks again
    }

    return 0;
}