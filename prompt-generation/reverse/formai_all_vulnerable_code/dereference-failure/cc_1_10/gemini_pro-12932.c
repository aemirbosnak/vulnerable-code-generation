//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Define the task structure
typedef struct task {
    char *command;  // The command to execute
    int delay;      // The delay in seconds before executing the command
    int pid;        // The process ID of the task
} task;

// Create a new task
task *create_task(char *command, int delay) {
    task *new_task = malloc(sizeof(task));
    new_task->command = strdup(command);
    new_task->delay = delay;
    new_task->pid = -1;
    return new_task;
}

// Free the memory allocated for a task
void free_task(task *task) {
    free(task->command);
    free(task);
}

// Execute a task
int execute_task(task *task) {
    // Fork a new process
    int pid = fork();
    if (pid == 0) {
        // Child process
        execlp("/bin/sh", "sh", "-c", task->command, NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        task->pid = pid;
        return 0;
    } else {
        // Error
        perror("fork");
        return -1;
    }
}

// Wait for a task to complete
int wait_for_task(task *task) {
    int status;
    pid_t pid = waitpid(task->pid, &status, 0);
    if (pid == -1) {
        perror("waitpid");
        return -1;
    } else if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    } else {
        return -1;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Create a task queue
    task *queue[100];
    int queue_size = 0;

    // Add tasks to the queue
    queue[queue_size++] = create_task("echo Hello, world!", 1);
    queue[queue_size++] = create_task("sleep 5", 5);
    queue[queue_size++] = create_task("echo Goodbye, world!", 1);

    // Execute the tasks
    for (int i = 0; i < queue_size; i++) {
        execute_task(queue[i]);
    }

    // Wait for the tasks to complete
    for (int i = 0; i < queue_size; i++) {
        wait_for_task(queue[i]);
    }

    // Free the memory allocated for the tasks
    for (int i = 0; i < queue_size; i++) {
        free_task(queue[i]);
    }

    return 0;
}