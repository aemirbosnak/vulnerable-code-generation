//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Custom task structure
struct task {
    char *command;       // Command to execute
    int interval;         // Interval between executions (seconds)
    int next_execution;   // Time of next execution (seconds since epoch)
};

// Create a new task
struct task *create_task(char *command, int interval) {
    struct task *task = malloc(sizeof(struct task));
    task->command = strdup(command);
    task->interval = interval;
    task->next_execution = 0;
    return task;
}

// Free a task
void free_task(struct task *task) {
    free(task->command);
    free(task);
}

// Execute a task
int execute_task(struct task *task) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execlp("/bin/sh", "sh", "-c", task->command, NULL);
        perror("execlp");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    } else {
        // Error
        return -1;
    }
}

// Compare two tasks by their next execution time
int compare_tasks(const void *a, const void *b) {
    struct task *task1 = *(struct task **)a;
    struct task *task2 = *(struct task **)b;
    return task1->next_execution - task2->next_execution;
}

// Task scheduler loop
void task_scheduler(struct task **tasks, int num_tasks) {
    while (1) {
        // Get the current time
        time_t now = time(NULL);

        // Sort the tasks by their next execution time
        qsort(tasks, num_tasks, sizeof(struct task *), compare_tasks);

        // Execute the first task that is due to run
        if (tasks[0]->next_execution <= now) {
            if (execute_task(tasks[0]) == 0) {
                // Task executed successfully, reset its next execution time
                tasks[0]->next_execution = now + tasks[0]->interval;
            } else {
                // Task failed, remove it from the list
                free_task(tasks[0]);
                tasks = (struct task **)realloc(tasks, (num_tasks - 1) * sizeof(struct task *));
                num_tasks--;
            }
        }

        // Sleep until the next task is due to run
        if (num_tasks > 0) {
            sleep(tasks[0]->next_execution - now);
        }
    }
}

int main() {
    // Create a list of tasks
    struct task *tasks[] = {
        create_task("echo Hello, world! >> /tmp/log.txt", 5),
        create_task("df -h >> /tmp/log.txt", 30),
        create_task("uptime >> /tmp/log.txt", 60),
    };
    int num_tasks = sizeof(tasks) / sizeof(struct task *);

    // Start the task scheduler
    task_scheduler(tasks, num_tasks);

    // Clean up
    for (int i = 0; i < num_tasks; i++) {
        free_task(tasks[i]);
    }
    free(tasks);

    return 0;
}