//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESS_NAME 32
#define MAX_ARGS 128

struct process {
    int pid;
    char name[MAX_PROCESS_NAME];
    char *args[MAX_ARGS];
};

int main(int argc, char *argv[]) {
    // Initialize process array
    struct process *processes = calloc(10, sizeof(struct process));

    // Parse command line arguments
    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s [--help] [<process_name> <args>...]\n", argv[0]);
            exit(EXIT_SUCCESS);
        }

        if (processes[i - 1].pid = fork()) {
            if (processes[i - 1].pid == 0) {
                // Child process
                close(STDIN_FILENO);
                close(STDOUT_FILENO);
                close(STDERR_FILENO);

                // Redirect standard file descriptors to /dev/null
                open("/dev/null", O_RDONLY);
                open("/dev/null", O_WRONLY);
                open("/dev/null", O_WRONLY);

                // Execute process
                execvp(argv[i], argv + i);
                perror("execvp");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                wait(NULL);
            }
        } else {
            // Parent process
            printf("Process %d (%s) started\n", processes[i - 1].pid, argv[i]);
        }

        i++;
    }

    // Clean up
    free(processes);

    return EXIT_SUCCESS;
}