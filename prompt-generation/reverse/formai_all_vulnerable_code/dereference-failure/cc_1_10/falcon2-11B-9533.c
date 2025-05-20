//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: automated
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <process id>\n", argv[0]);
        return 1;
    }

    pid = atoi(argv[1]);

    if (pid < 0) {
        fprintf(stderr, "Invalid process id\n");
        return 1;
    }

    int pipefd[2];
    if (pipe(pipefd)!= 0) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(pipefd[0]);
        dup2(pipefd[1], STDIN_FILENO);
        close(pipefd[1]);

        execl("/bin/sh", "sh", "-c", "sleep 10", NULL);
    } else {
        // Parent process
        close(pipefd[1]);
        dup2(pipefd[0], STDOUT_FILENO);
        close(pipefd[0]);

        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process was terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child process terminated abnormally\n");
        }

        close(STDOUT_FILENO);
    }

    return 0;
}