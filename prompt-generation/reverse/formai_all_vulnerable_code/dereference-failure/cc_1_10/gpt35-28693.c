//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep function

typedef struct task {
    char* name;
    time_t start_time;
    time_t end_time;
} Task;

Task* create_task(char* name, time_t start_time, time_t end_time) {
    Task* new_task = (Task*) malloc(sizeof(Task));
    new_task->name = name;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    return new_task;
}

void destroy_task(Task* task) {
    free(task);
}

void execute_task(Task* task) {
    printf("Executing task %s...\n", task->name);
    sleep(1);
    printf("Task completed.\n");
}

void schedule_task(Task* task) {
    time_t current_time = time(NULL);
    
    if (current_time >= task->start_time) {
        execute_task(task);
    }
    else {
        time_t wait_time = task->start_time - current_time;
        sleep(wait_time);
        execute_task(task);
    }
}

int main() {
    Task* task1 = create_task("Task 1", time(NULL) + 5, time(NULL) + 10);
    Task* task2 = create_task("Task 2", time(NULL) + 10, time(NULL) + 20);
    Task* task3 = create_task("Task 3", time(NULL) + 20, time(NULL) + 30);
    
    printf("Tasks scheduled. Waiting for execution...\n");
    
    schedule_task(task1);
    schedule_task(task2);
    schedule_task(task3);
    
    destroy_task(task1);
    destroy_task(task2);
    destroy_task(task3);
    
    return 0;
}