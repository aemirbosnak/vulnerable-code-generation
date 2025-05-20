//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct task_t 
{
    char* name;
    int priority;
    int interval;
    int wait_time;
    int (*function)(void);
} Task_t;

typedef struct task_node_t 
{
    Task_t* task;
    struct task_node_t* next;
} TaskNode_t;

TaskNode_t* head = NULL;
int running = 0;

// add task to scheduler
void add_task(Task_t* task) 
{
    TaskNode_t* new_node = (TaskNode_t*)malloc(sizeof(TaskNode_t));
    new_node->task = task;
    new_node->next = head;
    head = new_node;
}

// remove task from scheduler
void remove_task(Task_t* task) 
{
    TaskNode_t* current = head;
    TaskNode_t* previous = NULL;

    while (current != NULL) 
    {
        if (current->task == task) 
        {
            if (previous == NULL) 
            {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// check if a task should run
int should_run(Task_t* task) 
{
    return task->wait_time <= 0;
}

// run a task and update its wait time
void run_task(Task_t* task) 
{
    task->function();
    task->wait_time = task->interval;
}

// update the wait time of all tasks
void update_tasks(int elapsed) 
{
    TaskNode_t* current = head;

    while (current != NULL) 
    {
        current->task->wait_time -= elapsed;
        current = current->next;
    }
}

// find the highest priority task that should run
Task_t* get_next_task() 
{
    TaskNode_t* current = head;
    Task_t* next_task = NULL;

    while (current != NULL) 
    {
        if (should_run(current->task)) 
        {
            if (next_task == NULL || current->task->priority > next_task->priority) 
            {
                next_task = current->task;
            }
        }
        current = current->next;
    }

    return next_task;
}

// execute tasks asynchronously
void execute_tasks() 
{
    time_t old_time = time(NULL);
    running = 1;

    while (running) 
    {
        // get elapsed time since last update
        time_t current_time = time(NULL);
        int elapsed = (int)difftime(current_time, old_time);

        // update tasks and run any that should
        update_tasks(elapsed);
        Task_t* next_task = get_next_task();
        while (next_task != NULL) 
        {
            run_task(next_task);
            next_task = get_next_task();
        }

        old_time = current_time;
    }
}

// example tasks
int task1() 
{
    printf("Task 1\n");
    return 0;
}

int task2() 
{
    printf("Task 2\n");
    return 0;
}

int task3() 
{
    printf("Task 3\n");
    return 0;
}

// main function
int main() 
{
    Task_t* task1_ptr = (Task_t*)malloc(sizeof(Task_t));
    task1_ptr->name = "Task 1";
    task1_ptr->priority = 1;
    task1_ptr->interval = 2;
    task1_ptr->wait_time = 2;
    task1_ptr->function = task1;
    add_task(task1_ptr);

    Task_t* task2_ptr = (Task_t*)malloc(sizeof(Task_t));
    task2_ptr->name = "Task 2";
    task2_ptr->priority = 2;
    task2_ptr->interval = 5;
    task2_ptr->wait_time = 5;
    task2_ptr->function = task2;
    add_task(task2_ptr);

    Task_t* task3_ptr = (Task_t*)malloc(sizeof(Task_t));
    task3_ptr->name = "Task 3";
    task3_ptr->priority = 3;
    task3_ptr->interval = 10;
    task3_ptr->wait_time = 10;
    task3_ptr->function = task3;
    add_task(task3_ptr);

    execute_tasks();

    return 0;
}