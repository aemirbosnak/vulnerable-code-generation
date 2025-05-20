//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Defining a struct to hold tasks
typedef struct task {
    int id;
    int priority;
    int execution_time; // in seconds
    bool is_completed;
} task_t;

// Function to generate random integer within a range
int generate_random(int start, int end) {
    return start + rand() % (end - start + 1);
}

// Function to create a new task with random priority and execution time
task_t* create_task(int id) {
    task_t* task = (task_t*) malloc(sizeof(task_t));
    task->id = id;
    task->priority = generate_random(1, 10);
    task->execution_time = generate_random(1, 5);
    task->is_completed = false;
    return task;
}

// Function to print task details
void print_task(task_t* task) {
    printf("Task ID: %d | Priority: %d | Execution Time: %d\n", task->id, task->priority, task->execution_time);
}

// Function to execute task
void execute_task(task_t* task) {
    printf("Executing task ID %d for %d seconds...\n", task->id, task->execution_time);
    sleep(task->execution_time);
    task->is_completed = true;
    printf("Task ID %d completed!\n", task->id);
}

int main() {
    // Initializing task queue with 5 tasks
    task_t* task_queue[5];
    for (int i = 0; i < 5; i++) {
        task_queue[i] = create_task(i + 1);
    }

    // Sorting tasks by priority in descending order
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (task_queue[i]->priority < task_queue[j]->priority) {
                // Swap tasks
                task_t* temp = task_queue[i];
                task_queue[i] = task_queue[j];
                task_queue[j] = temp;
            }
        }
    }

    // Executing tasks one by one in order of priority
    for (int i = 0; i < 5; i++) {
        print_task(task_queue[i]);
        execute_task(task_queue[i]);
    }

    return 0;
}