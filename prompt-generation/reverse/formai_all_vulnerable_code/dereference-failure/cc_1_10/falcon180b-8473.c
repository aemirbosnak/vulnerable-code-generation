//Falcon-180B DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // do nothing
    }
}

int launch_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(command, NULL) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            return -1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        return 1;
    }

    signal(SIGCHLD, sigchld_handler);

    char input_buffer[MAX_COMMAND_LENGTH];
    strncpy(input_buffer, argv[1], MAX_COMMAND_LENGTH);
    char *command = strtok(input_buffer, " ");

    while (command!= NULL) {
        int result = launch_command(command);

        if (result == -1) {
            fprintf(stderr, "Error executing command '%s'\n", command);
        }

        command = strtok(NULL, " ");
    }

    return 0;
}