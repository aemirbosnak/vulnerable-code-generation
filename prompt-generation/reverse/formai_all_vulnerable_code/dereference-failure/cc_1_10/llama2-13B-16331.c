//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>

#define MAX_CMD_LEN 1024
#define MAX_PROCESS_LEN 64

struct process {
    char *name;
    char *command;
    pid_t pid;
    int status;
};

int main(void) {
    char *current_dir = getcwd(NULL, 0);
    if (current_dir == NULL) {
        perror("getcwd");
        return 1;
    }

    printf("Hello, world! I'm a system monitor, and I'm running in %s\n", current_dir);

    // Spin up a few processes to monitor
    int num_processes = 5;
    struct process *processes = calloc(num_processes, sizeof(struct process));
    for (int i = 0; i < num_processes; i++) {
        char *command = "/bin/bash -c 'echo $$; sleep 10'";
        processes[i].name = strdup("bash-process");
        processes[i].command = command;
        processes[i].pid = fork();
        if (processes[i].pid == 0) {
            // Child process
            execvp(command, command);
            perror("execvp");
            exit(1);
        } else if (processes[i].pid > 0) {
            // Parent process
            wait(NULL);
        }
    }

    // Monitor the processes
    while (1) {
        // Check the status of each process
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].status == 0) {
                printf("Process %s is still running\n", processes[i].name);
            } else {
                printf("Process %s has exited with status %d\n", processes[i].name, processes[i].status);
            }
        }

        // Sleep for a bit before checking again
        sleep(1);
    }

    return 0;
}

// Utility functions

// Print the command and PID of a process
void print_process(struct process *process) {
    printf("Process %s (PID %d) is running %s\n", process->name, process->pid, process->command);
}

// Wait for a process to finish
int wait_for_process(struct process *process) {
    wait(NULL);
    return process->status;
}