//GEMINI-pro DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_CMD_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *cmd = argv[1];
    char *args[MAX_CMD_LEN];
    int num_args = 0;

    char *ptr = strtok(cmd, " ");
    while (ptr != NULL) {
        args[num_args++] = ptr;
        ptr = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // child process
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process was killed by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child process exited with unknown status\n");
        }
    }

    return EXIT_SUCCESS;
}