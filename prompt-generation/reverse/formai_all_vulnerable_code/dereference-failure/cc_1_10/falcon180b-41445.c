//Falcon-180B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    pid_t child_pid;
    int status;
    char *args[] = {"ls", "-l", NULL};

    // Fork a child process
    child_pid = fork();

    // Check if the child process was successfully created
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    // If the parent process
    if (child_pid > 0) {
        // Wait for the child process to exit
        waitpid(child_pid, &status, 0);
    }

    // If the child process
    else {
        // Redirect standard output to a file
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        dup2(fd, STDOUT_FILENO);
        close(fd);

        // Execute the command
        execvp(args[0], args);

        // If execvp fails, print the error message and exit
        if (errno == ENOENT) {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            exit(1);
        } else {
            perror("execvp");
            exit(1);
        }
    }

    return 0;
}