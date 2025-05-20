//FormAI DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

volatile sig_atomic_t g_child_exit_status;

static void
sigchld_handler(int sig)
{
    int status = 0;
    pid_t pid = 0;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        if (WIFEXITED(status)) {
            g_child_exit_status = WEXITSTATUS(status);
        } else {
            g_child_exit_status = EXIT_FAILURE;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Failed to open file '%s': %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }

    struct sigaction act;
    act.sa_handler = sigchld_handler;
    act.sa_flags = SA_NOCLDSTOP | SA_RESTART;
    sigemptyset(&act.sa_mask);

    if (sigaction(SIGCHLD, &act, NULL) == -1) {
        fprintf(stderr, "Failed to register signal handler: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork child process: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child process
        if (execl("/usr/bin/md5sum", "md5sum", argv[1], NULL) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    } else {
        // Parent process
        fclose(f);

        // Wait for child to finish
        while (g_child_exit_status == -1);

        if (g_child_exit_status != EXIT_SUCCESS) {
            fprintf(stderr, "Command execution failed\n");
            return EXIT_FAILURE;
        }

        printf("Command execution succeeded\n");
    }

    return EXIT_SUCCESS;
}