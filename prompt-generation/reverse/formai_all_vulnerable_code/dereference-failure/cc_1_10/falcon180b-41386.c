//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int parent_to_child_pipe[2];
    int child_to_parent_pipe[2];
    pid_t child_pid;
    char buffer[BUFFER_SIZE];

    // Create pipes for interprocess communication
    if (pipe(parent_to_child_pipe) == -1 ||
        pipe(child_to_parent_pipe) == -1) {
        fprintf(stderr, "Error creating pipes: %s\n", strerror(errno));
        return 1;
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(parent_to_child_pipe[0]);
        close(child_to_parent_pipe[1]);

        dup2(parent_to_child_pipe[1], STDOUT_FILENO);
        close(parent_to_child_pipe[1]);

        execlp("ls", "ls", "-l", NULL);

        fprintf(stderr, "Error executing ls: %s\n", strerror(errno));
        return 1;
    } else {
        // Parent process
        close(parent_to_child_pipe[1]);
        close(child_to_parent_pipe[0]);

        while (1) {
            ssize_t bytes_read = read(child_to_parent_pipe[1], buffer, BUFFER_SIZE);

            if (bytes_read <= 0) {
                if (bytes_read == 0) {
                    fprintf(stdout, "Child process has exited\n");
                } else {
                    fprintf(stderr, "Error reading from pipe: %s\n", strerror(errno));
                    return 1;
                }
                break;
            }

            buffer[bytes_read] = '\0';
            fprintf(stdout, "%s", buffer);
        }
    }

    return 0;
}