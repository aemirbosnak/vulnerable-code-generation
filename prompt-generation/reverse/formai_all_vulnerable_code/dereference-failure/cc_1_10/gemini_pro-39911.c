//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the system call arguments
#define MAX_ARGS 10

// Define the maximum size of the system call command
#define MAX_COMMAND 100

// Define the maximum number of system calls to be monitored
#define MAX_SYSCALLS 10

// Define the list of system calls to be monitored
const char *monitored_syscalls[] = {"open", "read", "write", "close", "execve", "fork", "kill", "exit", "mkdir", "rmdir"};

// Define the structure of a system call event
typedef struct syscall_event {
    char *command;
    char *args[MAX_ARGS];
    int num_args;
} syscall_event;

// Define the list of system call events
syscall_event syscall_events[MAX_SYSCALLS];

// Define the number of system call events
int num_syscall_events = 0;

// Define the function to add a system call event to the list
void add_syscall_event(char *command, char *args[]) {
    // Check if the number of system call events has reached the maximum
    if (num_syscall_events >= MAX_SYSCALLS) {
        fprintf(stderr, "Error: The maximum number of system call events has been reached.\n");
        return;
    }

    // Allocate memory for the system call event
    syscall_event *event = malloc(sizeof(syscall_event));

    // Copy the command and arguments to the system call event
    event->command = strdup(command);
    for (int i = 0; i < MAX_ARGS; i++) {
        event->args[i] = strdup(args[i]);
    }

    // Set the number of arguments in the system call event
    event->num_args = MAX_ARGS;

    // Add the system call event to the list
    syscall_events[num_syscall_events++] = *event;
}

// Define the function to check if a system call is monitored
int is_monitored_syscall(char *command) {
    // Iterate over the list of monitored system calls
    for (int i = 0; i < MAX_SYSCALLS; i++) {
        // Check if the command matches a monitored system call
        if (strcmp(command, monitored_syscalls[i]) == 0) {
            return 1;
        }
    }

    // The command is not a monitored system call
    return 0;
}

// Define the function to handle a system call event
void handle_syscall_event(syscall_event *event) {
    // Check if the system call is monitored
    if (!is_monitored_syscall(event->command)) {
        return;
    }

    // Print the system call event
    printf("System call: %s", event->command);
    for (int i = 0; i < event->num_args; i++) {
        printf(" %s", event->args[i]);
    }
    printf("\n");

    // Check if the system call is suspicious
    if (strcmp(event->command, "execve") == 0 && strcmp(event->args[0], "/bin/sh") == 0) {
        // The system call is suspicious
        printf("Suspicious system call: %s", event->command);
        for (int i = 0; i < event->num_args; i++) {
            printf(" %s", event->args[i]);
        }
        printf("\n");
    }
}

// Define the main function
int main(int argc, char *argv[]) {
    // Parse the command line arguments
    for (int i = 0; i < argc; i++) {
        // Check if the argument is a system call
        if (is_monitored_syscall(argv[i])) {
            // Add the system call to the list of monitored system calls
            add_syscall_event(argv[i], argv + i + 1);
        }
    }

    // Loop forever and handle system call events
    while (1) {
        // Wait for a system call event
        syscall_event event;
        read(0, &event, sizeof(syscall_event));

        // Handle the system call event
        handle_syscall_event(&event);
    }

    return 0;
}