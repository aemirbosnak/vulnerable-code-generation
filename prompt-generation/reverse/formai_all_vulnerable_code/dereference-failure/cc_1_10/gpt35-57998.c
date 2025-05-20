//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TASK_INTERVAL 5 // 5 second interval between each task
#define NUM_TASKS 5 // number of tasks to be scheduled

typedef struct task {
    int id; // unique task identifier
    int priority; // task priority (0 is highest)
    time_t last_run; // timestamp of last run
    void (*func_ptr)(); // function pointer to task function
} Task;

// sample task function
void sample_task() {
    printf("Executing sample task at %ld\n", time(NULL));
}

// initialize and schedule tasks
Task* init_tasks() {
    Task* tasks = malloc(NUM_TASKS * sizeof(Task));
    
    for(int i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % 3; // random priority assignment
        tasks[i].last_run = time(NULL);
        tasks[i].func_ptr = &sample_task;
    }
    
    return tasks;
}

// get highest priority task
Task* get_highest_priority_task(Task* tasks) {
    Task* highest_priority_task = NULL;
    
    for(int i = 0; i < NUM_TASKS; i++) {
        if(highest_priority_task == NULL || tasks[i].priority < highest_priority_task->priority) {
            highest_priority_task = &tasks[i];
        }
    }
    
    return highest_priority_task;
}

// execute tasks in a distributed style
void schedule_tasks(Task* tasks) {
    while(1) {
        Task* next_task = get_highest_priority_task(tasks);
        
        // check if it's time to execute task
        if(difftime(time(NULL), next_task->last_run) >= TASK_INTERVAL) {
            next_task->func_ptr();
            next_task->last_run = time(NULL);
        }
    }
}

int main() {
    srand(time(NULL));
    Task* tasks = init_tasks();
    
    schedule_tasks(tasks);
    return 0;
}