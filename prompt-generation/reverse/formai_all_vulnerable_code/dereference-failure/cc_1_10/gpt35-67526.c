//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Task structure
struct Task {
    int id;
    int priority;
    int interval;
};

// Global variables
struct Task* tasks;
int num_tasks = 0;
int current_task = 0;

// Signal handler for timer interrupt
void on_timer_interrupt(int sig) {
    // Ignore signal if there are no tasks
    if (num_tasks == 0) {
        return;
    }
    
    // Execute current task
    printf("Executing task %d\n", tasks[current_task].id);
    sleep(tasks[current_task].interval);
    
    // Select next task based on priority
    int highest_priority = 0;
    int highest_priority_task = -1;
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].priority > highest_priority) {
            highest_priority = tasks[i].priority;
            highest_priority_task = i;
        }
    }
    current_task = highest_priority_task;
}

// Add task function
void add_task(int priority, int interval) {
    // Allocate memory for new task
    num_tasks++;
    struct Task* new_tasks = realloc(tasks, num_tasks * sizeof(struct Task));
    if (new_tasks == NULL) {
        printf("Unable to allocate memory\n");
        exit(1);
    }
    tasks = new_tasks;
    
    // Initialize task
    struct Task new_task;
    new_task.id = num_tasks;
    new_task.priority = priority;
    new_task.interval = interval;
    tasks[num_tasks - 1] = new_task;
    
    // Set signal handler for timer interrupt
    signal(SIGALRM, on_timer_interrupt);
    
    // Set timer for first task
    if (num_tasks == 1) {
        ualarm(tasks[0].interval * 1000, tasks[0].interval * 1000);
    }
}

int main() {
    // Add tasks
    add_task(1, 2);
    add_task(2, 4);
    add_task(3, 1);
    
    // Wait for tasks to finish
    sleep(20);
    
    return 0;
}