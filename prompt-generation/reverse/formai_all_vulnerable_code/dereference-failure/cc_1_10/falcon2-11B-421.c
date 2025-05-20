//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    int status;
    int pipefd[2];
    if(pipe(pipefd) == -1) {
        perror("Error creating pipe");
        return 1;
    }

    if(fork() == 0) {
        // Child process
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        close(pipefd[0]);

        char buf[128];
        while(read(0, buf, sizeof(buf)) > 0) {
            if(strcmp(buf, "exit\n") == 0) {
                exit(0);
            }
        }
    } else {
        // Parent process
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);

        pid_t child = waitpid(pid, &status, 0);
        if(child == -1) {
            perror("Error waiting for child process");
            return 1;
        }

        if(WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)) {
            printf("Child process was terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child process exited abnormally\n");
        }
    }

    return 0;
}