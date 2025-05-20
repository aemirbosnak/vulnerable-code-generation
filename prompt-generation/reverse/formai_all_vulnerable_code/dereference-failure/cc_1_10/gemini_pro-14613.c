//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

// Define the task structure
typedef struct task {
    char *name;
    int priority;
    int time;
    struct task *next;
} task;

// Define the task queue
task *head = NULL;
task *tail = NULL;

// Add a task to the queue
void add_task(char *name, int priority, int time) {
    // Create a new task
    task *new_task = (task *)malloc(sizeof(task));
    new_task->name = name;
    new_task->priority = priority;
    new_task->time = time;
    new_task->next = NULL;

    // Add the task to the queue
    if (head == NULL) {
        head = new_task;
        tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }
}

// Remove a task from the queue
task *remove_task() {
    // Check if the queue is empty
    if (head == NULL) {
        return NULL;
    }

    // Remove the task from the queue
    task *removed_task = head;
    head = head->next;

    // Return the removed task
    return removed_task;
}

// Print the queue
void print_queue() {
    // Iterate over the queue
    task *current_task = head;
    while (current_task != NULL) {
        printf("%s %d %d\n", current_task->name, current_task->priority, current_task->time);
        current_task = current_task->next;
    }
}

// Run the scheduler
void run_scheduler() {
    // While there are still tasks in the queue
    while (head != NULL) {
        // Remove the next task from the queue
        task *next_task = remove_task();

        // Run the task
        printf("Running task %s\n", next_task->name);
        sleep(next_task->time);

        // Free the task
        free(next_task);
    }
}

// Main function
int main() {
    // Add some tasks to the queue
    add_task("Task 1", 1, 5);
    add_task("Task 2", 2, 10);
    add_task("Task 3", 3, 15);

    // Print the queue
    print_queue();

    // Run the scheduler
    run_scheduler();

    return 0;
}