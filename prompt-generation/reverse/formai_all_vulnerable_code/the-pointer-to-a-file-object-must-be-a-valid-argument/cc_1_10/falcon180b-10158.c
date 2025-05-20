//Falcon-180B DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int main() {
    int fd[2];
    pid_t child_pid;
    char input_buffer[MAX_LINE_LENGTH];
    char *token;
    int status;

    // Create pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Error creating pipe: %s\n", strerror(errno));
        return 1;
    }

    // Fork child process
    child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "Error forking child process: %s\n", strerror(errno));
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]); // Close reading end of pipe
        dup2(fd[1], STDOUT_FILENO); // Duplicate writing end of pipe to stdout
        close(fd[1]); // Close writing end of pipe
        execlp("ls", "ls", NULL); // Execute "ls" command
        fprintf(stderr, "Error executing command: %s\n", strerror(errno));
        return 1;
    } else {
        // Parent process
        close(fd[1]); // Close writing end of pipe
        while (fgets(input_buffer, MAX_LINE_LENGTH, fd[0])!= NULL) {
            token = strtok(input_buffer, "\n");
            printf("%s", token);
        }
        close(fd[0]); // Close reading end of pipe
        waitpid(child_pid, &status, 0); // Wait for child process to exit
        if (WIFEXITED(status)) {
            printf("\nCommand exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("\nCommand terminated abnormally\n");
        }
    }

    return 0;
}