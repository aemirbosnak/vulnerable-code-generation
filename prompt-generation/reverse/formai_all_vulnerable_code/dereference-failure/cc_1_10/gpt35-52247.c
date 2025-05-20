//FormAI DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid;
    int status;

    if (argc < 2) {
        printf("Usage: %s command [args...]\n", argv[0]);
        exit(-1);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(-1);
    }
    else if (pid == 0) {
        char* path = getenv("PATH");
        char* cmd = argv[1];

        while (path && *path) {
            char* colon = strchr(path, ':');
            if (colon) {
                *colon = '\0';
                ++colon;
            }

            char* full_path = malloc(strlen(path) + strlen(cmd) + 2);
            sprintf(full_path, "%s/%s", path, cmd);

            execv(full_path, &argv[1]);

            free(full_path);
            path = colon;
        }

        // If we get here, execv failed
        perror(cmd);
        exit(-1);
    }
    else {
        while (wait(&status) != pid) {
            // Waiting for child process to finish
        }

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
        else {
            return -1;
        }
    }
}