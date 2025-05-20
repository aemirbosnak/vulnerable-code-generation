//FormAI DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the maximum tasks
#define MAX_TASKS 10

// Define a struct for the task
struct task
{
    char* name;             // Name of the task
    int interval;           // How often task runs (in seconds)
    void (*function)(void); // The task callback function
    pid_t pid;              // The process ID of the task
    int running;            // Whether the task is currently running
};

// Define a global array of tasks
struct task tasks[MAX_TASKS];

// Define a function to add a task to the array
int add_task(char* name, int interval, void (*function)(void))
{
    // Find an empty slot in the array
    int i;
    for (i = 0; i < MAX_TASKS; i++)
    {
        if (tasks[i].name == NULL)
        {
            break;
        }
    }

    // If all slots are full, return an error
    if (i == MAX_TASKS)
    {
        return -1;
    }

    // Allocate memory for the name and copy it in
    tasks[i].name = (char*)malloc(sizeof(char) * 256);
    snprintf(tasks[i].name, 256, "%s", name);

    // Set the other values of the task
    tasks[i].interval = interval;
    tasks[i].function = function;
    tasks[i].pid = 0;
    tasks[i].running = 0;

    return i;
}

// Define a function to remove a task from the array
int remove_task(int task_id)
{
    // Check if the task ID is valid
    if (task_id < 0 || task_id >= MAX_TASKS || tasks[task_id].name == NULL)
    {
        return -1;
    }

    // Free the memory for the task name
    free(tasks[task_id].name);

    // Set the task values to NULL/0
    tasks[task_id].name = NULL;
    tasks[task_id].interval = 0;
    tasks[task_id].function = NULL;
    tasks[task_id].pid = 0;
    tasks[task_id].running = 0;

    return 0;
}

// Define a function to run a single task
void run_task(int task_id)
{
    // Check if the task ID is valid
    if (task_id < 0 || task_id >= MAX_TASKS || tasks[task_id].name == NULL)
    {
        return;
    }

    // Create a new process to run the task
    pid_t pid = fork();

    if (pid == 0)
    {
        // Run the task's function in the child process
        tasks[task_id].function();

        // Exit the child process
        exit(0);
    }

    // Set the task's PID and running status
    tasks[task_id].pid = pid;
    tasks[task_id].running = 1;
}

// Define a function to run all tasks
void run_all_tasks()
{
    // Loop through the tasks array and run each task
    int i;
    for (i = 0; i < MAX_TASKS; i++)
    {
        if (tasks[i].name != NULL)
        {
            run_task(i);
        }
    }
}

// Define a function to stop a single task
void stop_task(int task_id)
{
    // Check if the task ID is valid
    if (task_id < 0 || task_id >= MAX_TASKS || tasks[task_id].name == NULL)
    {
        return;
    }

    // Send a SIGTERM signal to the task's process
    kill(tasks[task_id].pid, SIGTERM);

    // Wait for the task to exit
    int status;
    waitpid(tasks[task_id].pid, &status, 0);

    // Set the task's PID and running status
    tasks[task_id].pid = 0;
    tasks[task_id].running = 0;
}

// Define a function to stop all tasks
void stop_all_tasks()
{
    // Loop through the tasks array and stop each task
    int i;
    for (i = 0; i < MAX_TASKS; i++)
    {
        if (tasks[i].name != NULL && tasks[i].running)
        {
            stop_task(i);
        }
    }
}

// Define a function for task 1
void task1()
{
    printf("Task 1 running...\n");
    sleep(1);
}

// Define a function for task 2
void task2()
{
    printf("Task 2 running...\n");
    sleep(2);
}

int main()
{
    // Initialize the tasks array to all NULL/0 values
    int i;
    for (i = 0; i < MAX_TASKS; i++)
    {
        tasks[i].name = NULL;
        tasks[i].interval = 0;
        tasks[i].function = NULL;
        tasks[i].pid = 0;
        tasks[i].running = 0;
    }

    // Add two tasks to the array
    int task1_id = add_task("Task 1", 1, task1);
    int task2_id = add_task("Task 2", 2, task2);

    // Run all tasks
    run_all_tasks();

    // Wait for user input to stop tasks
    printf("Press Enter to stop tasks...\n");
    getchar();

    // Stop all tasks
    stop_all_tasks();

    // Remove the tasks from the array
    remove_task(task1_id);
    remove_task(task2_id);

    return 0;
}