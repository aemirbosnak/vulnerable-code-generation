//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Define the maximum number of tasks
#define MAX_TASKS 100

// Define the structure of a task
typedef struct task {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    bool completed;
} task;

// Define the structure of the scheduler
typedef struct scheduler {
    task tasks[MAX_TASKS];
    int num_tasks;
    int current_time;
    int running_task_id;
} scheduler;

// Create a new scheduler
scheduler* create_scheduler() {
    scheduler* s = (scheduler*)malloc(sizeof(scheduler));
    s->num_tasks = 0;
    s->current_time = 0;
    s->running_task_id = -1;
    return s;
}

// Destroy the scheduler
void destroy_scheduler(scheduler* s) {
    free(s);
}

// Add a task to the scheduler
void add_task(scheduler* s, task t) {
    s->tasks[s->num_tasks] = t;
    s->num_tasks++;
}

// Get the next task to run
task* get_next_task(scheduler* s) {
    int min_arrival_time = -1;
    int min_arrival_task_id = -1;
    for (int i = 0; i < s->num_tasks; i++) {
        if (!s->tasks[i].completed && (s->tasks[i].arrival_time <= s->current_time) && (s->tasks[i].arrival_time < min_arrival_time || min_arrival_time == -1)) {
            min_arrival_time = s->tasks[i].arrival_time;
            min_arrival_task_id = i;
        }
    }
    if (min_arrival_task_id != -1) {
        return &s->tasks[min_arrival_task_id];
    } else {
        return NULL;
    }
}

// Run the scheduler
void run_scheduler(scheduler* s) {
    while (true) {
        // Get the next task to run
        task* t = get_next_task(s);

        // If there are no more tasks to run, break out of the loop
        if (t == NULL) {
            break;
        }

        // Start the task
        printf("Starting task %d at time %d\n", t->id, s->current_time);
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            sleep(t->burst_time);
            exit(0);
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
            // Mark the task as completed
            t->completed = true;
            s->running_task_id = -1;
        }

        // Increment the current time
        s->current_time++;
    }
}

// Print the scheduler's tasks
void print_tasks(scheduler* s) {
    printf("Tasks:\n");
    for (int i = 0; i < s->num_tasks; i++) {
        printf("Task %d: arrival time %d, burst time %d, priority %d\n", s->tasks[i].id, s->tasks[i].arrival_time, s->tasks[i].burst_time, s->tasks[i].priority);
    }
}

// Main function
int main() {
    // Create a new scheduler
    scheduler* s = create_scheduler();

    // Add some tasks to the scheduler
    task t1 = {1, 0, 10, 1};
    add_task(s, t1);
    task t2 = {2, 2, 5, 2};
    add_task(s, t2);
    task t3 = {3, 4, 8, 3};
    add_task(s, t3);
    task t4 = {4, 6, 6, 4};
    add_task(s, t4);
    task t5 = {5, 8, 4, 5};
    add_task(s, t5);

    // Print the scheduler's tasks
    print_tasks(s);

    // Run the scheduler
    run_scheduler(s);

    // Destroy the scheduler
    destroy_scheduler(s);

    return 0;
}