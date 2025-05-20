//GEMINI-pro DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

// Custom error handler
void error_handler(int errnum) {
    char *errstr = strerror(errnum);
    fprintf(stderr, "Error %d: %s\n", errnum, errstr);
    exit(EXIT_FAILURE);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a command was provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a pipe for communication between parent and child processes
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        error_handler(errno);
    }

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        error_handler(errno);
    }

    // Child process executes the command
    if (child_pid == 0) {
        // Close the read end of the pipe in the child process
        close(pipe_fd[0]);

        // Redirect stdout and stderr to the write end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);
        dup2(pipe_fd[1], STDERR_FILENO);

        // Close the write end of the pipe
        close(pipe_fd[1]);

        // Execute the command
        execvp(argv[1], &argv[1]);

        // If execvp returns, it means there was an error
        error_handler(errno);
    }

    // Parent process waits for the child process to finish
    int status;
    waitpid(child_pid, &status, 0);

    // Close the write end of the pipe in the parent process
    close(pipe_fd[1]);

    // Read the output from the child process
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
        // Write the output to stdout
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // Close the read end of the pipe
    close(pipe_fd[0]);

    // Check the exit status of the child process
    if (WIFEXITED(status)) {
        // Child process exited normally
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        // Child process was terminated by a signal
        printf("Child process was terminated by signal %d\n", WTERMSIG(status));
    } else {
        // Child process exited abnormally
        printf("Child process exited abnormally\n");
    }

    return 0;
}