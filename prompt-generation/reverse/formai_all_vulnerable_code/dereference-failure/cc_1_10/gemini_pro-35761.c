//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PROCESSES 10

// Custom data structure to represent a process
typedef struct Process {
    int pid;
    char *command;
    char *args;
    time_t start_time;
    time_t end_time;
    int status;
} Process;

// Global array to store all the processes
Process *processes[MAX_PROCESSES];

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a random number of processes
    int num_processes = rand() % MAX_PROCESSES + 1;
    for (int i = 0; i < num_processes; i++) {
        // Create a new process
        Process *process = (Process *)malloc(sizeof(Process));

        // Generate a random command and arguments
        process->command = (char *)malloc(BUFFER_SIZE);
        sprintf(process->command, "/bin/sh");
        process->args = (char *)malloc(BUFFER_SIZE);
        sprintf(process->args, "-c 'sleep %d'", rand() % 10 + 1);

        // Start the process
        process->pid = fork();
        if (process->pid == 0) {
            // Child process
            execlp(process->command, process->command, process->args, NULL);
            exit(EXIT_FAILURE);
        } else if (process->pid > 0) {
            // Parent process
            processes[i] = process;
        } else {
            // Error
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all the processes to finish
    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i]->pid, &processes[i]->status, 0);
        processes[i]->end_time = time(NULL);
    }

    // Print a summary of the processes
    printf("Summary of processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: %s %s\n", processes[i]->pid, processes[i]->command, processes[i]->args);
        printf("Start time: %s", ctime(&processes[i]->start_time));
        printf("End time: %s", ctime(&processes[i]->end_time));
        printf("Status: %d\n", processes[i]->status);
    }

    // Free the memory allocated for the processes
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]->command);
        free(processes[i]->args);
        free(processes[i]);
    }

    return EXIT_SUCCESS;
}