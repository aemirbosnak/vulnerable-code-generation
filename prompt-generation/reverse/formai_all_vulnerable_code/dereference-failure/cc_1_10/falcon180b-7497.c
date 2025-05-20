//Falcon-180B DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024

void my_exit_handler(int signum) {
    if (signum == SIGSEGV) {
        fprintf(stderr, "Segmentation fault occurred.\n");
    } else if (signum == SIGINT) {
        fprintf(stderr, "Interrupted by user.\n");
    } else if (signum == SIGABRT) {
        fprintf(stderr, "Abnormal termination.\n");
    } else {
        fprintf(stderr, "Unknown signal %d.\n", signum);
    }

    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        char *args[argc + 1];
        args[0] = argv[1];
        for (int i = 1; i < argc; i++) {
            args[i] = argv[i];
        }
        args[argc] = NULL;

        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
            return 1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status)) {
            int signum = WTERMSIG(status);
            my_exit_handler(signum);
        } else if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status!= 0) {
                fprintf(stderr, "Command exited with status %d.\n", exit_status);
            }
        } else {
            fprintf(stderr, "Unknown child status.\n");
        }
    }

    return 0;
}