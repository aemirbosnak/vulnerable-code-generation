//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PROCESS 64

struct happy_process {
    int pid;
    char *command;
    char *args[64];
};

void happy_sysadmin_program(void) {
    char *line = NULL;
    size_t line_length = 0;
    size_t i = 0;
    struct happy_process processes[MAX_PROCESS];
    int status = 0;

    // Ask user for commands
    printf("Welcome to the happy system administration program! Please enter commands:\n");
    while (1) {
        // Read line from user
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line_length = strlen(line);

        // Check if enter was pressed
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
        }

        // Parse command
        if (strcmp(line, "quit") == 0) {
            break;
        } else if (strcmp(line, "start") == 0) {
            // Start a new process
            if (i >= MAX_PROCESS) {
                printf("Too many processes running! Please close some before starting more.\n");
                break;
            }
            processes[i].pid = fork();
            if (processes[i].pid == 0) {
                // Child process
                char *arg = strtok(line, " ");
                while (arg != NULL && i < 64) {
                    processes[i].args[i] = arg;
                    arg = strtok(NULL, " ");
                    i++;
                }
                execvp(arg[0], arg);
                perror("exec");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                wait(NULL);
            }
            i++;
        } else if (strcmp(line, "status") == 0) {
            // Print status of all processes
            for (i = 0; i < MAX_PROCESS; i++) {
                if (processes[i].pid > 0) {
                    printf("%d: %s\n", processes[i].pid, processes[i].command);
                }
            }
        } else {
            // Unknown command
            printf("Invalid command. Please enter 'start', 'status', or 'quit'.\n");
        }
    }

    // Clean up
    for (i = 0; i < MAX_PROCESS; i++) {
        if (processes[i].pid > 0) {
            wait(NULL);
        }
    }

    return;
}

int main(void) {
    happy_sysadmin_program();
    return 0;
}