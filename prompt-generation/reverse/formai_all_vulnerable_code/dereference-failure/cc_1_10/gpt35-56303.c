//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include<stdio.h>
#include<stdlib.h>

// Define Task structure
typedef struct {
    int id; // Task id
    int priority; // Priority of task
    int wait_time; // Time to wait before execution
    void (*fun)(); // Pointer to function which the task should execute
} Task;

// Define a function to create a task
Task* create_task(int id, int priority, int wait_time, void (*fun)()) {
    Task *t = (Task*)malloc(sizeof(Task)); // Allocating memory for task pointer
    t->id = id;
    t->priority = priority;
    t->wait_time = wait_time;
    t->fun = fun;
    return t;
}

// Define a function to execute the task
void execute_task(Task *t) {
    printf("Executing task with id: %d\n", t->id);
    t->fun(); // Calling the function pointer
}

// Define a function to find the task with highest priority
Task* find_highest_priority_task(Task *tasks[], int num_tasks) {
    Task *highest_priority_task = tasks[0]; // Assume the first task has the highest priority
    int i;
    for(i = 1; i < num_tasks; i++) {
        // Check if the current task has higher priority
        if(tasks[i]->priority > highest_priority_task->priority) {
            highest_priority_task = tasks[i];
        }
    }
    return highest_priority_task;
}

int main() {
    // Create some sample tasks
    Task *t1 = create_task(1, 3, 5, &printf);
    Task *t2 = create_task(2, 2, 2, &scanf);
    Task *t3 = create_task(3, 1, 3, &exit);
    Task *t4 = create_task(4, 5, 4, &malloc);
    Task *t5 = create_task(5, 4, 1, &free);

    int num_tasks = 5;    
    Task *tasks[num_tasks];
    tasks[0] = t1;
    tasks[1] = t2;
    tasks[2] = t3;
    tasks[3] = t4;
    tasks[4] = t5;

    int current_time = 0;
    int i;
    while(1) {
        printf("Current Time: %d\n", current_time);
        for(i = 0; i < num_tasks; i++) {
            // Check if the task should execute
            if(tasks[i]->wait_time == current_time) {
                printf("Task with id %d is ready to execute!\n", tasks[i]->id);
            }
        }
        Task *highest_priority_task = find_highest_priority_task(tasks, num_tasks);
        execute_task(highest_priority_task); // Execute the highest priority task
        current_time++; // Increase the current time by 1
    }

    return 0;
}